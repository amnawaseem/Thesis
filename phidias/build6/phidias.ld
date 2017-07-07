PHDRS {
	load_x PT_LOAD;
	load_r PT_LOAD;
	load_ws PT_LOAD;
	load_w PT_LOAD;
}
SECTIONS {
	. = PHIDIAS_VADDR_BASE;
	__phidias_start = .;
	.text : {
			__phidias_code_start = .;
			*(.text.startup)
			*(.text)
			*(.text.__x86*)
			*(.text.unlikely)
			__phidias_code_end = .;
			. = ALIGN(0x1000);
	} :load_x
	.rodata : {
			__phidias_rodata_start = .;
			*(.rodata)
			*(.rodata.str1.1)
			*(.rodata.str1.4)
			*(.rodata.str1.8)
			*(.rodata.cst8)
			__phidias_rodata_end = .;
			. = ALIGN(0x1000);
        } :load_r
	.data_shared : {
			__phidias_data_shared_start = .;
			*(.data_shared)
			__phidias_data_shared_end = .;
			. = ALIGN(0x1000);
        } :load_ws
	.data : {
			__phidias_data_start = .;
			*(.data)
			__phidias_data_end = .;
	} :load_w
	.bss : {
			__phidias_bss_start = .;
			*(.bss)
			__phidias_bss_end = .;
			. = ALIGN(0x1000);
        } :load_w
	__phidias_end = .;
	_specification = .;
	/DISCARD/ : {
			*(.comment)
			*(.eh_frame)
			*(.eh_frame_hdr)
	} :NONE
}
ENTRY(__boot)
