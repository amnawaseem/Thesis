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

static int kmemfd = -1;

/**
 * Verifies whether a certain (word-sized, i.e. 4 byte) location in
 * virtual kernel memory indeed contains the desired value.
 *
 * Due to strange effects of messing with the '/dev/kmem' device, not
 * all writes may be visible - some just take time, some never show up.
 * Better verify everything you want to be in RAM after writing.
 *
 * This function returns TRUE (!= 0) if the value was found, and FALSE
 * if it was not found (either a different value was retrieved or the
 * location could not be read at all).
 */
int kernel_value_present(void *address, unsigned int value) {
	unsigned int compare;
	int read_status;

	if (kmemfd < 0) {
		kmemfd = open("/dev/kmem", O_RDONLY);
	}

	// if "/dev/kmem" cannot be opened, return FALSE
	if (kmemfd < 0) {
		return 0;
	}

	lseek64(kmemfd, (unsigned int)address, SEEK_SET);
	read_status = read(kmemfd, &compare, 4);

	// if location cannot be read, return FALSE
	if (read_status != 4)
		return 0;

	return (value == compare);
}

/**
 * Writes the contents of memory at [src, src+len[ to the destination range
 * [dest, dest+len[ using the exploitable write bug.
 *
 * Use write_a_word() from tty.c as your writing primitive, and use the
 * other functions from that file to tune the value written. Note that the
 * TTY queue is backed by a kernel buffer and thus limited in size - the
 * highest amount you can queue is around 20KB. The functions in tty.c
 * limit this even further, but in practice you won't need more than what
 * we provide... just employ a clever writing strategy.
 *
 * After you're done writing, flush data and instruction caches and check
 * that the memory contents indeed match your expectations - use the provided
 * kernel_value_present() for the latter.
 *
 * Return the number of bytes you could match; you don't have to be exact,
 * i.e. checking and reporting at word granularity is sufficient.
 *
 * If the return value is in the range [0,len[, main() will reattempt
 * the write. You can return something below 0 to signal an error condition
 * (but there should be no reason to).
 */
int memcpy_to_kernel(void *dest, void *src, unsigned int len) {
	(void)dest; (void)src; (void)len;

	return -1;
}
