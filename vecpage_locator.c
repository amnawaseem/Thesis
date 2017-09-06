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

void *vecpage;

/* TODO: your value from (6b) goes here, replace the "NULL" */
void *vecpage_fixed_virtual = NULL;

/**
 * Locate the vectors page in the kernel physmap.
 *
 * This function scans kernel memory, looking for the vectors page by
 * comparing each page's contents with the vectors page mapped into the
 * current process at the well-known fixed virtual address.
 *
 * On success the global variable 'vecpage' is updated to point to the
 * "master" location. On the rare occasion that multiple pages match,
 * 'vecpage' should not be set; main() will then refrain from doing
 * stupid things.
 *
 * Hint for finally running your exploit once everything is ready:
 * If you get multiple matches, you can manually modify individual
 * candidate pages one at a time using your write bug. Either you hit
 * the real page (which will also modify your mapped virtual page, and
 * the next run will have a unique hit) or you hit a duplicate (which
 * will then no longer show up as a match).
 */
void find_vectors_page() {
	/* TODO: your code */
}
