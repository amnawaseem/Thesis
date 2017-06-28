.section .rodata, "a"

.global phidias_buildstamp_git_revision
phidias_buildstamp_git_revision:
	.asciz	"3a1771b"

.global phidias_buildstamp_time_compile
phidias_buildstamp_time_compile:
	.asciz	"2017/06/28 15:45:05"

.global	binutils_version
binutils_version:
	.asciz	"2.26.1"

.global	gcc_version
gcc_version:
	.asciz	"5.4.0"
