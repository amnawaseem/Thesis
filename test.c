#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

char * const args[2] = { "/bin/sh", NULL };

extern char **environ;

static void catch_ill(int sig) {
	(void)sig;
	printf("Received SIGILL - unimplemented syscall...\n");
	exit(1);
}

int main(int an, char **ac) {
	unsigned int result;

	(void)an; (void)ac;

	signal(SIGILL, &catch_ill);

	printf("Trying magical test syscall.\n");

	/**
	 * Call magical syscall #0xee0001 in order to check whether our
	 * intercept code was successfully installed.
	 */
	asm volatile("ldr r7, =0xee0001\n\tsvc #0\n\tmov %0, r0"
			: "=r" (result) :: "r0", "r7");

	if (result != 0) {
		printf("Intercept code not found, magical syscall #1 returned %d\n", result);
		return 1;
	}

	printf("Trying magical make-me-root syscall.\n");

	/**
	 * Call magical syscall #0xee0002 to change the subjective credentials
	 * of the current process to root.
	 */
	asm volatile("ldr r7, =0xee0002\n\tsvc #0\n\tmov %0, r0"
			: "=r" (result) :: "r0", "r7");

	if (result != 0) {
		printf("Acquiring root privileges failed, magical syscall #2 returned %d\n", result);
		return 1;
	}

	printf("Everything looks ok, execve()ing into a shell...\n");

	execve(args[0], args, environ);

	printf("Performing execve() failed - strange.\n");
	return 1;
}
