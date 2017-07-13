.section .rodata, "a"

.global phidias_buildstamp_git_revision
phidias_buildstamp_git_revision:
	.asciz	"3a1771b+"

.global phidias_buildstamp_time_compile
phidias_buildstamp_time_compile:
	.asciz	"2017/07/13 14:46:42"

.global	binutils_version
binutils_version:
	.asciz	"2.26.1"

.global	gcc_version
gcc_version:
	.asciz	"5.4.0"
