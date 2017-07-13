.section .rodata, "a"

.global phidias_buildstamp_git_revision
phidias_buildstamp_git_revision:
	.asciz	"3a1771b+"

.global phidias_buildstamp_time_compile
phidias_buildstamp_time_compile:
	.asciz	"2017/07/12 15:44:29"

.global	binutils_version
binutils_version:
	.asciz	"2.26.1"

.global	gcc_version
gcc_version:
	.asciz	"5.4.0"
