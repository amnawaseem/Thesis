nopsled:
	.rep	(262144 / 4 - 1)
	nop
	.endr
	bx	lr
