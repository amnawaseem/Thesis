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
// Flush the corresponding caches. We cannot do this by issuing DCCMVAC or
// ICIALLU, because these are (privileged) MCR instructions which would trap.
// There is a strange special cacheflush syscall on ARM (number #0x9f002),
// but we're going with the simple way of just exerting enough pressure on
// the data cache and the instruction cache so our stuff is pushed out.
//
// These helpers are provided for free, as these details are quite finicky
// to get right (and still may not work at 100% reliability).
// --------------------------------------------------------------------------

static void *dc_mem, *ic_mem;

/**
 * Map a data area of 1MB which we can touch later in a non-linear fashion to
 * evict all interesting lines from the data cache. Touch it now so all pages
 * are already faulted in when we later do the flush.
 *
 * Additionally, map the 'nopsled' file RX, which contains 256K of NOPs and
 * a final return. Immediately call it once so all code pages are faulted in.
 */
void prepare_squeezers(void) {
	int ic_fd;
	int i;
	volatile int J = 0;

	dc_mem = mmap(NULL, 1UL << 20, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (dc_mem == MAP_FAILED) {
		fprintf(stderr, "prepare_squeezers(): could not map data cache flush area\n");
		exit(1);
	}
	// hit every page
	for (i = 0; i < (1 << 8); i++) {
		J += *(int *)(dc_mem + (i << 12));
		*(int *)(dc_mem + (i << 12)) = J;
	}

	ic_fd = open("payload/nopsled", O_RDONLY);
	ic_mem = mmap(NULL, 1UL << 18, PROT_READ | PROT_EXEC, MAP_PRIVATE, ic_fd, 0);
	if ((ic_fd < 0) || (ic_mem == MAP_FAILED)) {
		fprintf(stderr, "prepare_squeezers(): could not map nop sled\n");
		exit(1);
	}

	// run it once; also causes the compiler not to optimize J away
	((void (*)(int))ic_mem)(J);
}

/**
 * Touch 1024KB of data cache with read accesses. Make sure that we do not
 * use a simple linear pattern, as the cache will notice and switch to
 * no-allocate mode.
 */
int squeeze_data_cache(void) {
	int i;
	volatile int J = 0;

	for (i = 0; i < (1 << 14); i++) {
		J += *(int *)(dc_mem + ((i & 0xff) << 12) + ((i & 0x3f00) >> 2));
	}

	return J;
}

/**
 * Touch 256KB of instruction cache by jumping to a fat NOP sled. The sled
 * is precompiled, so we can just conveniently map it PROT_EXEC.
 */
void squeeze_insn_cache(void) {
	((void (*)())ic_mem)();
}
