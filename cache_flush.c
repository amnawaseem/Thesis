#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sched.h>
static void *dc_mem;
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

int main(int an, char **ac) {
    prepare_squeezers();

    (void)squeeze_data_cache();
    (void)squeeze_data_cache();
    (void)squeeze_data_cache();
    return 0;


}
