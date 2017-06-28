#include <phidias.h>
#include <vm.h>
#include <interrupts.h>
#include <emulate/core.h>
#include <emulate/uart.h>
#include <emulate/irq.h>
#include <emulate/timer.h>
#include <emulate/clock.h>
#include <emulate/vtlb.h>
#include <emulate/memory.h>
#include <arch/cpu_state.h>
#include <schedule.h>
#include <specification.h>
#include <arch/specification.h>

#define	__SEC_ROH	__attribute__((section(".rodata_head")))
#define	__SEC_RO	__attribute__((section(".rodata")))
#define	__SEC_RW	__attribute__((section(".data")))
#define	__SEC_RWS	__attribute__((section(".data_shared")))

__SEC_ROH specification const _specification;
__SEC_RO const vm * const _specification_irq_owners[IRQID_MAXIMUM];
__SEC_RO specification_arch const _specification_arch;
__SEC_RO specification_cpu const _specification_cpus[8];
__SEC_RO memarea const cpu0_memareas[34];
__SEC_RO tree_memarea const cpu0_memtree_l_l_l_l;
__SEC_RO tree_memarea const cpu0_memtree_l_l_l;
__SEC_RO tree_memarea const cpu0_memtree_l_l;
__SEC_RO tree_memarea const cpu0_memtree_l_l_r_l;
__SEC_RO tree_memarea const cpu0_memtree_l_l_r;
__SEC_RO tree_memarea const cpu0_memtree_l;
__SEC_RO tree_memarea const cpu0_memtree_l_r_l_l;
__SEC_RO tree_memarea const cpu0_memtree_l_r_l;
__SEC_RO tree_memarea const cpu0_memtree_l_r;
__SEC_RO tree_memarea const cpu0_memtree_l_r_r;
__SEC_RO tree_memarea const cpu0_memtree;
__SEC_RO tree_memarea const cpu0_memtree_r_l_l_l;
__SEC_RO tree_memarea const cpu0_memtree_r_l_l;
__SEC_RO tree_memarea const cpu0_memtree_r_l;
__SEC_RO tree_memarea const cpu0_memtree_r_l_r_l;
__SEC_RO tree_memarea const cpu0_memtree_r_l_r;
__SEC_RO tree_memarea const cpu0_memtree_r;
__SEC_RO tree_memarea const cpu0_memtree_r_r_l_l;
__SEC_RO tree_memarea const cpu0_memtree_r_r_l;
__SEC_RO tree_memarea const cpu0_memtree_r_r;
__SEC_RO tree_memarea const cpu0_memtree_r_r_r;
__SEC_RO vm_cpu * const cpu0_vm_cpus[1];
__SEC_RO memarea const cpu1_memareas[32];
__SEC_RO tree_memarea const cpu1_memtree_l_l_l_l;
__SEC_RO tree_memarea const cpu1_memtree_l_l_l;
__SEC_RO tree_memarea const cpu1_memtree_l_l;
__SEC_RO tree_memarea const cpu1_memtree_l_l_r;
__SEC_RO tree_memarea const cpu1_memtree_l;
__SEC_RO tree_memarea const cpu1_memtree_l_r_l_l;
__SEC_RO tree_memarea const cpu1_memtree_l_r_l;
__SEC_RO tree_memarea const cpu1_memtree_l_r;
__SEC_RO tree_memarea const cpu1_memtree_l_r_r;
__SEC_RO tree_memarea const cpu1_memtree;
__SEC_RO tree_memarea const cpu1_memtree_r_l_l_l;
__SEC_RO tree_memarea const cpu1_memtree_r_l_l;
__SEC_RO tree_memarea const cpu1_memtree_r_l;
__SEC_RO tree_memarea const cpu1_memtree_r_l_r;
__SEC_RO tree_memarea const cpu1_memtree_r;
__SEC_RO tree_memarea const cpu1_memtree_r_r_l_l;
__SEC_RO tree_memarea const cpu1_memtree_r_r_l;
__SEC_RO tree_memarea const cpu1_memtree_r_r;
__SEC_RO tree_memarea const cpu1_memtree_r_r_r;
__SEC_RO vm_cpu * const cpu1_vm_cpus[0];
__SEC_RO memarea const cpu2_memareas[32];
__SEC_RO tree_memarea const cpu2_memtree_l_l_l_l;
__SEC_RO tree_memarea const cpu2_memtree_l_l_l;
__SEC_RO tree_memarea const cpu2_memtree_l_l;
__SEC_RO tree_memarea const cpu2_memtree_l_l_r;
__SEC_RO tree_memarea const cpu2_memtree_l;
__SEC_RO tree_memarea const cpu2_memtree_l_r_l_l;
__SEC_RO tree_memarea const cpu2_memtree_l_r_l;
__SEC_RO tree_memarea const cpu2_memtree_l_r;
__SEC_RO tree_memarea const cpu2_memtree_l_r_r;
__SEC_RO tree_memarea const cpu2_memtree;
__SEC_RO tree_memarea const cpu2_memtree_r_l_l_l;
__SEC_RO tree_memarea const cpu2_memtree_r_l_l;
__SEC_RO tree_memarea const cpu2_memtree_r_l;
__SEC_RO tree_memarea const cpu2_memtree_r_l_r;
__SEC_RO tree_memarea const cpu2_memtree_r;
__SEC_RO tree_memarea const cpu2_memtree_r_r_l_l;
__SEC_RO tree_memarea const cpu2_memtree_r_r_l;
__SEC_RO tree_memarea const cpu2_memtree_r_r;
__SEC_RO tree_memarea const cpu2_memtree_r_r_r;
__SEC_RO vm_cpu * const cpu2_vm_cpus[0];
__SEC_RO memarea const cpu3_memareas[32];
__SEC_RO tree_memarea const cpu3_memtree_l_l_l_l;
__SEC_RO tree_memarea const cpu3_memtree_l_l_l;
__SEC_RO tree_memarea const cpu3_memtree_l_l;
__SEC_RO tree_memarea const cpu3_memtree_l_l_r;
__SEC_RO tree_memarea const cpu3_memtree_l;
__SEC_RO tree_memarea const cpu3_memtree_l_r_l_l;
__SEC_RO tree_memarea const cpu3_memtree_l_r_l;
__SEC_RO tree_memarea const cpu3_memtree_l_r;
__SEC_RO tree_memarea const cpu3_memtree_l_r_r;
__SEC_RO tree_memarea const cpu3_memtree;
__SEC_RO tree_memarea const cpu3_memtree_r_l_l_l;
__SEC_RO tree_memarea const cpu3_memtree_r_l_l;
__SEC_RO tree_memarea const cpu3_memtree_r_l;
__SEC_RO tree_memarea const cpu3_memtree_r_l_r;
__SEC_RO tree_memarea const cpu3_memtree_r;
__SEC_RO tree_memarea const cpu3_memtree_r_r_l_l;
__SEC_RO tree_memarea const cpu3_memtree_r_r_l;
__SEC_RO tree_memarea const cpu3_memtree_r_r;
__SEC_RO tree_memarea const cpu3_memtree_r_r_r;
__SEC_RO vm_cpu * const cpu3_vm_cpus[0];
__SEC_RO memarea const cpu4_memareas[32];
__SEC_RO tree_memarea const cpu4_memtree_l_l_l_l;
__SEC_RO tree_memarea const cpu4_memtree_l_l_l;
__SEC_RO tree_memarea const cpu4_memtree_l_l;
__SEC_RO tree_memarea const cpu4_memtree_l_l_r;
__SEC_RO tree_memarea const cpu4_memtree_l;
__SEC_RO tree_memarea const cpu4_memtree_l_r_l_l;
__SEC_RO tree_memarea const cpu4_memtree_l_r_l;
__SEC_RO tree_memarea const cpu4_memtree_l_r;
__SEC_RO tree_memarea const cpu4_memtree_l_r_r;
__SEC_RO tree_memarea const cpu4_memtree;
__SEC_RO tree_memarea const cpu4_memtree_r_l_l_l;
__SEC_RO tree_memarea const cpu4_memtree_r_l_l;
__SEC_RO tree_memarea const cpu4_memtree_r_l;
__SEC_RO tree_memarea const cpu4_memtree_r_l_r;
__SEC_RO tree_memarea const cpu4_memtree_r;
__SEC_RO tree_memarea const cpu4_memtree_r_r_l_l;
__SEC_RO tree_memarea const cpu4_memtree_r_r_l;
__SEC_RO tree_memarea const cpu4_memtree_r_r;
__SEC_RO tree_memarea const cpu4_memtree_r_r_r;
__SEC_RO vm_cpu * const cpu4_vm_cpus[0];
__SEC_RO memarea const cpu5_memareas[32];
__SEC_RO tree_memarea const cpu5_memtree_l_l_l_l;
__SEC_RO tree_memarea const cpu5_memtree_l_l_l;
__SEC_RO tree_memarea const cpu5_memtree_l_l;
__SEC_RO tree_memarea const cpu5_memtree_l_l_r;
__SEC_RO tree_memarea const cpu5_memtree_l;
__SEC_RO tree_memarea const cpu5_memtree_l_r_l_l;
__SEC_RO tree_memarea const cpu5_memtree_l_r_l;
__SEC_RO tree_memarea const cpu5_memtree_l_r;
__SEC_RO tree_memarea const cpu5_memtree_l_r_r;
__SEC_RO tree_memarea const cpu5_memtree;
__SEC_RO tree_memarea const cpu5_memtree_r_l_l_l;
__SEC_RO tree_memarea const cpu5_memtree_r_l_l;
__SEC_RO tree_memarea const cpu5_memtree_r_l;
__SEC_RO tree_memarea const cpu5_memtree_r_l_r;
__SEC_RO tree_memarea const cpu5_memtree_r;
__SEC_RO tree_memarea const cpu5_memtree_r_r_l_l;
__SEC_RO tree_memarea const cpu5_memtree_r_r_l;
__SEC_RO tree_memarea const cpu5_memtree_r_r;
__SEC_RO tree_memarea const cpu5_memtree_r_r_r;
__SEC_RO vm_cpu * const cpu5_vm_cpus[0];
__SEC_RO memarea const cpu6_memareas[32];
__SEC_RO tree_memarea const cpu6_memtree_l_l_l_l;
__SEC_RO tree_memarea const cpu6_memtree_l_l_l;
__SEC_RO tree_memarea const cpu6_memtree_l_l;
__SEC_RO tree_memarea const cpu6_memtree_l_l_r;
__SEC_RO tree_memarea const cpu6_memtree_l;
__SEC_RO tree_memarea const cpu6_memtree_l_r_l_l;
__SEC_RO tree_memarea const cpu6_memtree_l_r_l;
__SEC_RO tree_memarea const cpu6_memtree_l_r;
__SEC_RO tree_memarea const cpu6_memtree_l_r_r;
__SEC_RO tree_memarea const cpu6_memtree;
__SEC_RO tree_memarea const cpu6_memtree_r_l_l_l;
__SEC_RO tree_memarea const cpu6_memtree_r_l_l;
__SEC_RO tree_memarea const cpu6_memtree_r_l;
__SEC_RO tree_memarea const cpu6_memtree_r_l_r;
__SEC_RO tree_memarea const cpu6_memtree_r;
__SEC_RO tree_memarea const cpu6_memtree_r_r_l_l;
__SEC_RO tree_memarea const cpu6_memtree_r_r_l;
__SEC_RO tree_memarea const cpu6_memtree_r_r;
__SEC_RO tree_memarea const cpu6_memtree_r_r_r;
__SEC_RO vm_cpu * const cpu6_vm_cpus[0];
__SEC_RO memarea const cpu7_memareas[32];
__SEC_RO tree_memarea const cpu7_memtree_l_l_l_l;
__SEC_RO tree_memarea const cpu7_memtree_l_l_l;
__SEC_RO tree_memarea const cpu7_memtree_l_l;
__SEC_RO tree_memarea const cpu7_memtree_l_l_r;
__SEC_RO tree_memarea const cpu7_memtree_l;
__SEC_RO tree_memarea const cpu7_memtree_l_r_l_l;
__SEC_RO tree_memarea const cpu7_memtree_l_r_l;
__SEC_RO tree_memarea const cpu7_memtree_l_r;
__SEC_RO tree_memarea const cpu7_memtree_l_r_r;
__SEC_RO tree_memarea const cpu7_memtree;
__SEC_RO tree_memarea const cpu7_memtree_r_l_l_l;
__SEC_RO tree_memarea const cpu7_memtree_r_l_l;
__SEC_RO tree_memarea const cpu7_memtree_r_l;
__SEC_RO tree_memarea const cpu7_memtree_r_l_r;
__SEC_RO tree_memarea const cpu7_memtree_r;
__SEC_RO tree_memarea const cpu7_memtree_r_r_l_l;
__SEC_RO tree_memarea const cpu7_memtree_r_r_l;
__SEC_RO tree_memarea const cpu7_memtree_r_r;
__SEC_RO tree_memarea const cpu7_memtree_r_r_r;
__SEC_RO vm_cpu * const cpu7_vm_cpus[0];
__SEC_RW uintptr_t __placeholder_rw;
__SEC_RWS uintptr_t __placeholder_rws;
__SEC_RO vm const vm_linux1;
__SEC_RW vm_cpu vm_linux1_cpus[1];
__SEC_RO vm_copyin const vm_linux1_copyins[3];
__SEC_RO capability const vm_linux1_capabilities[0];
__SEC_RW scheduler_entity vm_linux1_cpu0_scheds[1];
__SEC_RO memarea const vm_linux1_cpu0_memareas[5];
__SEC_RO tree_memarea const vm_linux1_cpu0_memtree_l_l;
__SEC_RO tree_memarea const vm_linux1_cpu0_memtree_l;
__SEC_RO tree_memarea const vm_linux1_cpu0_memtree;
__SEC_RO tree_memarea const vm_linux1_cpu0_memtree_r_l;
__SEC_RO tree_memarea const vm_linux1_cpu0_memtree_r;
__SEC_RO emulate const vm_linux1_cpu0_emulates[15];
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_l_l_l;
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_l_l;
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_l_l_r;
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_l;
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_l_r_l;
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_l_r;
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_l_r_r;
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree;
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_r_l_l;
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_r_l;
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_r_l_r;
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_r;
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_r_r_l;
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_r_r;
__SEC_RWS emulate_uart_pl011 vdev_linux1_uart;
__SEC_RW emulate_irq_gic vdev_linux1_gic_cpu0;
__SEC_RWS emulate_irq_gic_distributor vdev_linux1_gic_dist;
__SEC_RWS emulate_timer_sp804 vdev_linux1_sp804;
__SEC_RW emulate_timer_armcp14 vdev_linux1_armcp14_cpu0;
__SEC_RO emulate_memory const vdev_linux1_mmio_mediactrl;
__SEC_RO emulate_memory const vdev_linux1_mmio1;
__SEC_RO emulate_memory const vdev_linux1_mmio_dwmmc;
__SEC_RO emulate_memory const vdev_linux1_mmio_xrange;
__SEC_RO emulate_memory const vdev_linux1_mmio_aoctrl;
__SEC_RO emulate_memory const vdev_linux1_mmio3;
__SEC_RO emulate_memory const vdev_linux1_mmio_uart1;
__SEC_RO emulate_memory const vdev_linux1_mmio_uart2;
__SEC_RO emulate_memory const vdev_linux1_mmio_uart4;
__SEC_RO emulate_memory const vdev_linux1_mmio4;
__SEC_RO emulate_memory const vdev_linux1_mmio2;
__SEC_RO const emulate * const vm_linux1_hw_emulates[2];


__SEC_ROH specification const _specification = {
  "PHIDSPEC", 0x0, 0x0, 0x0, 8, _specification_cpus, _specification_irq_owners, &_specification_arch, "2017/06/28 09:35:18"
};
__SEC_RO const vm * const _specification_irq_owners[IRQID_MAXIMUM] = {
};
__SEC_RO specification_arch const _specification_arch = {};
__SEC_RO specification_cpu const _specification_cpus[8] = {
  { 0x0, 34, cpu0_memareas, &cpu0_memtree, 1, cpu0_vm_cpus, {} },
  { 0x0, 32, cpu1_memareas, &cpu1_memtree, 0, NULL, {} },
  { 0x0, 32, cpu2_memareas, &cpu2_memtree, 0, NULL, {} },
  { 0x0, 32, cpu3_memareas, &cpu3_memtree, 0, NULL, {} },
  { 0x0, 32, cpu4_memareas, &cpu4_memtree, 0, NULL, {} },
  { 0x0, 32, cpu5_memareas, &cpu5_memtree, 0, NULL, {} },
  { 0x0, 32, cpu6_memareas, &cpu6_memtree, 0, NULL, {} },
  { 0x0, 32, cpu7_memareas, &cpu7_memtree, 0, NULL, {} },
};
__SEC_RO memarea const cpu0_memareas[34] = {
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_X|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0, 0, 0, 0, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x40000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x0, 0x0, 0x40000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf7113000, 0x0, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf6800000, 0x0, 0x8000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf7020000, 0x0, 0x10000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf8008000, 0x0, 0x9000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf7030000, 0x0, 0x2000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf0000000, 0x0, 0xfff0000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0x0, 0x0, 0x40000000, MEMAREA_FLAG_R|MEMAREA_FLAG_W, NULL },
  { 0x0, 0x0, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
};
__SEC_RO tree_memarea const cpu0_memtree_l_l_l_l = { NULL, NULL, cpu0_memareas + 16 };
__SEC_RO tree_memarea const cpu0_memtree_l_l_l = { &cpu0_memtree_l_l_l_l, NULL, cpu0_memareas + 17 };
__SEC_RO tree_memarea const cpu0_memtree_l_l = { &cpu0_memtree_l_l_l, &cpu0_memtree_l_l_r, cpu0_memareas + 25 };
__SEC_RO tree_memarea const cpu0_memtree_l_l_r_l = { NULL, NULL, cpu0_memareas + 26 };
__SEC_RO tree_memarea const cpu0_memtree_l_l_r = { &cpu0_memtree_l_l_r_l, NULL, cpu0_memareas + 27 };
__SEC_RO tree_memarea const cpu0_memtree_l = { &cpu0_memtree_l_l, &cpu0_memtree_l_r, cpu0_memareas + 31 };
__SEC_RO tree_memarea const cpu0_memtree_l_r_l_l = { NULL, NULL, cpu0_memareas + 0 };
__SEC_RO tree_memarea const cpu0_memtree_l_r_l = { &cpu0_memtree_l_r_l_l, NULL, cpu0_memareas + 1 };
__SEC_RO tree_memarea const cpu0_memtree_l_r = { &cpu0_memtree_l_r_l, &cpu0_memtree_l_r_r, cpu0_memareas + 3 };
__SEC_RO tree_memarea const cpu0_memtree_l_r_r = { NULL, NULL, cpu0_memareas + 4 };
__SEC_RO tree_memarea const cpu0_memtree = { &cpu0_memtree_l, &cpu0_memtree_r, cpu0_memareas + 2 };
__SEC_RO tree_memarea const cpu0_memtree_r_l_l_l = { NULL, NULL, cpu0_memareas + 8 };
__SEC_RO tree_memarea const cpu0_memtree_r_l_l = { &cpu0_memtree_r_l_l_l, NULL, cpu0_memareas + 9 };
__SEC_RO tree_memarea const cpu0_memtree_r_l = { &cpu0_memtree_r_l_l, &cpu0_memtree_r_l_r, cpu0_memareas + 10 };
__SEC_RO tree_memarea const cpu0_memtree_r_l_r_l = { NULL, NULL, cpu0_memareas + 11 };
__SEC_RO tree_memarea const cpu0_memtree_r_l_r = { &cpu0_memtree_r_l_r_l, NULL, cpu0_memareas + 6 };
__SEC_RO tree_memarea const cpu0_memtree_r = { &cpu0_memtree_r_l, &cpu0_memtree_r_r, cpu0_memareas + 7 };
__SEC_RO tree_memarea const cpu0_memtree_r_r_l_l = { NULL, NULL, cpu0_memareas + 13 };
__SEC_RO tree_memarea const cpu0_memtree_r_r_l = { &cpu0_memtree_r_r_l_l, NULL, cpu0_memareas + 12 };
__SEC_RO tree_memarea const cpu0_memtree_r_r = { &cpu0_memtree_r_r_l, &cpu0_memtree_r_r_r, cpu0_memareas + 32 };
__SEC_RO tree_memarea const cpu0_memtree_r_r_r = { NULL, NULL, cpu0_memareas + 33 };
__SEC_RO vm_cpu * const cpu0_vm_cpus[1] = {
  vm_linux1_cpus + 0,
};
__SEC_RO memarea const cpu1_memareas[32] = {
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_X|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0, 0, 0, 0, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x40000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x0, 0x0, 0x40000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf7113000, 0x0, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf6800000, 0x0, 0x8000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf7020000, 0x0, 0x10000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf8008000, 0x0, 0x9000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf7030000, 0x0, 0x2000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf0000000, 0x0, 0xfff0000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
};
__SEC_RO tree_memarea const cpu1_memtree_l_l_l_l = { NULL, NULL, cpu1_memareas + 16 };
__SEC_RO tree_memarea const cpu1_memtree_l_l_l = { &cpu1_memtree_l_l_l_l, NULL, cpu1_memareas + 17 };
__SEC_RO tree_memarea const cpu1_memtree_l_l = { &cpu1_memtree_l_l_l, &cpu1_memtree_l_l_r, cpu1_memareas + 25 };
__SEC_RO tree_memarea const cpu1_memtree_l_l_r = { NULL, NULL, cpu1_memareas + 26 };
__SEC_RO tree_memarea const cpu1_memtree_l = { &cpu1_memtree_l_l, &cpu1_memtree_l_r, cpu1_memareas + 27 };
__SEC_RO tree_memarea const cpu1_memtree_l_r_l_l = { NULL, NULL, cpu1_memareas + 31 };
__SEC_RO tree_memarea const cpu1_memtree_l_r_l = { &cpu1_memtree_l_r_l_l, NULL, cpu1_memareas + 0 };
__SEC_RO tree_memarea const cpu1_memtree_l_r = { &cpu1_memtree_l_r_l, &cpu1_memtree_l_r_r, cpu1_memareas + 1 };
__SEC_RO tree_memarea const cpu1_memtree_l_r_r = { NULL, NULL, cpu1_memareas + 3 };
__SEC_RO tree_memarea const cpu1_memtree = { &cpu1_memtree_l, &cpu1_memtree_r, cpu1_memareas + 4 };
__SEC_RO tree_memarea const cpu1_memtree_r_l_l_l = { NULL, NULL, cpu1_memareas + 2 };
__SEC_RO tree_memarea const cpu1_memtree_r_l_l = { &cpu1_memtree_r_l_l_l, NULL, cpu1_memareas + 8 };
__SEC_RO tree_memarea const cpu1_memtree_r_l = { &cpu1_memtree_r_l_l, &cpu1_memtree_r_l_r, cpu1_memareas + 9 };
__SEC_RO tree_memarea const cpu1_memtree_r_l_r = { NULL, NULL, cpu1_memareas + 10 };
__SEC_RO tree_memarea const cpu1_memtree_r = { &cpu1_memtree_r_l, &cpu1_memtree_r_r, cpu1_memareas + 11 };
__SEC_RO tree_memarea const cpu1_memtree_r_r_l_l = { NULL, NULL, cpu1_memareas + 6 };
__SEC_RO tree_memarea const cpu1_memtree_r_r_l = { &cpu1_memtree_r_r_l_l, NULL, cpu1_memareas + 7 };
__SEC_RO tree_memarea const cpu1_memtree_r_r = { &cpu1_memtree_r_r_l, &cpu1_memtree_r_r_r, cpu1_memareas + 13 };
__SEC_RO tree_memarea const cpu1_memtree_r_r_r = { NULL, NULL, cpu1_memareas + 12 };
__SEC_RO vm_cpu * const cpu1_vm_cpus[0] = {
};
__SEC_RO memarea const cpu2_memareas[32] = {
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_X|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0, 0, 0, 0, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x40000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x0, 0x0, 0x40000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf7113000, 0x0, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf6800000, 0x0, 0x8000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf7020000, 0x0, 0x10000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf8008000, 0x0, 0x9000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf7030000, 0x0, 0x2000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf0000000, 0x0, 0xfff0000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
};
__SEC_RO tree_memarea const cpu2_memtree_l_l_l_l = { NULL, NULL, cpu2_memareas + 16 };
__SEC_RO tree_memarea const cpu2_memtree_l_l_l = { &cpu2_memtree_l_l_l_l, NULL, cpu2_memareas + 17 };
__SEC_RO tree_memarea const cpu2_memtree_l_l = { &cpu2_memtree_l_l_l, &cpu2_memtree_l_l_r, cpu2_memareas + 25 };
__SEC_RO tree_memarea const cpu2_memtree_l_l_r = { NULL, NULL, cpu2_memareas + 26 };
__SEC_RO tree_memarea const cpu2_memtree_l = { &cpu2_memtree_l_l, &cpu2_memtree_l_r, cpu2_memareas + 27 };
__SEC_RO tree_memarea const cpu2_memtree_l_r_l_l = { NULL, NULL, cpu2_memareas + 31 };
__SEC_RO tree_memarea const cpu2_memtree_l_r_l = { &cpu2_memtree_l_r_l_l, NULL, cpu2_memareas + 0 };
__SEC_RO tree_memarea const cpu2_memtree_l_r = { &cpu2_memtree_l_r_l, &cpu2_memtree_l_r_r, cpu2_memareas + 1 };
__SEC_RO tree_memarea const cpu2_memtree_l_r_r = { NULL, NULL, cpu2_memareas + 3 };
__SEC_RO tree_memarea const cpu2_memtree = { &cpu2_memtree_l, &cpu2_memtree_r, cpu2_memareas + 4 };
__SEC_RO tree_memarea const cpu2_memtree_r_l_l_l = { NULL, NULL, cpu2_memareas + 2 };
__SEC_RO tree_memarea const cpu2_memtree_r_l_l = { &cpu2_memtree_r_l_l_l, NULL, cpu2_memareas + 8 };
__SEC_RO tree_memarea const cpu2_memtree_r_l = { &cpu2_memtree_r_l_l, &cpu2_memtree_r_l_r, cpu2_memareas + 9 };
__SEC_RO tree_memarea const cpu2_memtree_r_l_r = { NULL, NULL, cpu2_memareas + 10 };
__SEC_RO tree_memarea const cpu2_memtree_r = { &cpu2_memtree_r_l, &cpu2_memtree_r_r, cpu2_memareas + 11 };
__SEC_RO tree_memarea const cpu2_memtree_r_r_l_l = { NULL, NULL, cpu2_memareas + 6 };
__SEC_RO tree_memarea const cpu2_memtree_r_r_l = { &cpu2_memtree_r_r_l_l, NULL, cpu2_memareas + 7 };
__SEC_RO tree_memarea const cpu2_memtree_r_r = { &cpu2_memtree_r_r_l, &cpu2_memtree_r_r_r, cpu2_memareas + 13 };
__SEC_RO tree_memarea const cpu2_memtree_r_r_r = { NULL, NULL, cpu2_memareas + 12 };
__SEC_RO vm_cpu * const cpu2_vm_cpus[0] = {
};
__SEC_RO memarea const cpu3_memareas[32] = {
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_X|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0, 0, 0, 0, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x40000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x0, 0x0, 0x40000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf7113000, 0x0, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf6800000, 0x0, 0x8000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf7020000, 0x0, 0x10000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf8008000, 0x0, 0x9000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf7030000, 0x0, 0x2000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf0000000, 0x0, 0xfff0000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
};
__SEC_RO tree_memarea const cpu3_memtree_l_l_l_l = { NULL, NULL, cpu3_memareas + 16 };
__SEC_RO tree_memarea const cpu3_memtree_l_l_l = { &cpu3_memtree_l_l_l_l, NULL, cpu3_memareas + 17 };
__SEC_RO tree_memarea const cpu3_memtree_l_l = { &cpu3_memtree_l_l_l, &cpu3_memtree_l_l_r, cpu3_memareas + 25 };
__SEC_RO tree_memarea const cpu3_memtree_l_l_r = { NULL, NULL, cpu3_memareas + 26 };
__SEC_RO tree_memarea const cpu3_memtree_l = { &cpu3_memtree_l_l, &cpu3_memtree_l_r, cpu3_memareas + 27 };
__SEC_RO tree_memarea const cpu3_memtree_l_r_l_l = { NULL, NULL, cpu3_memareas + 31 };
__SEC_RO tree_memarea const cpu3_memtree_l_r_l = { &cpu3_memtree_l_r_l_l, NULL, cpu3_memareas + 0 };
__SEC_RO tree_memarea const cpu3_memtree_l_r = { &cpu3_memtree_l_r_l, &cpu3_memtree_l_r_r, cpu3_memareas + 1 };
__SEC_RO tree_memarea const cpu3_memtree_l_r_r = { NULL, NULL, cpu3_memareas + 3 };
__SEC_RO tree_memarea const cpu3_memtree = { &cpu3_memtree_l, &cpu3_memtree_r, cpu3_memareas + 4 };
__SEC_RO tree_memarea const cpu3_memtree_r_l_l_l = { NULL, NULL, cpu3_memareas + 2 };
__SEC_RO tree_memarea const cpu3_memtree_r_l_l = { &cpu3_memtree_r_l_l_l, NULL, cpu3_memareas + 8 };
__SEC_RO tree_memarea const cpu3_memtree_r_l = { &cpu3_memtree_r_l_l, &cpu3_memtree_r_l_r, cpu3_memareas + 9 };
__SEC_RO tree_memarea const cpu3_memtree_r_l_r = { NULL, NULL, cpu3_memareas + 10 };
__SEC_RO tree_memarea const cpu3_memtree_r = { &cpu3_memtree_r_l, &cpu3_memtree_r_r, cpu3_memareas + 11 };
__SEC_RO tree_memarea const cpu3_memtree_r_r_l_l = { NULL, NULL, cpu3_memareas + 6 };
__SEC_RO tree_memarea const cpu3_memtree_r_r_l = { &cpu3_memtree_r_r_l_l, NULL, cpu3_memareas + 7 };
__SEC_RO tree_memarea const cpu3_memtree_r_r = { &cpu3_memtree_r_r_l, &cpu3_memtree_r_r_r, cpu3_memareas + 13 };
__SEC_RO tree_memarea const cpu3_memtree_r_r_r = { NULL, NULL, cpu3_memareas + 12 };
__SEC_RO vm_cpu * const cpu3_vm_cpus[0] = {
};
__SEC_RO memarea const cpu4_memareas[32] = {
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_X|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0, 0, 0, 0, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x40000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x0, 0x0, 0x40000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf7113000, 0x0, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf6800000, 0x0, 0x8000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf7020000, 0x0, 0x10000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf8008000, 0x0, 0x9000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf7030000, 0x0, 0x2000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf0000000, 0x0, 0xfff0000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
};
__SEC_RO tree_memarea const cpu4_memtree_l_l_l_l = { NULL, NULL, cpu4_memareas + 16 };
__SEC_RO tree_memarea const cpu4_memtree_l_l_l = { &cpu4_memtree_l_l_l_l, NULL, cpu4_memareas + 17 };
__SEC_RO tree_memarea const cpu4_memtree_l_l = { &cpu4_memtree_l_l_l, &cpu4_memtree_l_l_r, cpu4_memareas + 25 };
__SEC_RO tree_memarea const cpu4_memtree_l_l_r = { NULL, NULL, cpu4_memareas + 26 };
__SEC_RO tree_memarea const cpu4_memtree_l = { &cpu4_memtree_l_l, &cpu4_memtree_l_r, cpu4_memareas + 27 };
__SEC_RO tree_memarea const cpu4_memtree_l_r_l_l = { NULL, NULL, cpu4_memareas + 31 };
__SEC_RO tree_memarea const cpu4_memtree_l_r_l = { &cpu4_memtree_l_r_l_l, NULL, cpu4_memareas + 0 };
__SEC_RO tree_memarea const cpu4_memtree_l_r = { &cpu4_memtree_l_r_l, &cpu4_memtree_l_r_r, cpu4_memareas + 1 };
__SEC_RO tree_memarea const cpu4_memtree_l_r_r = { NULL, NULL, cpu4_memareas + 3 };
__SEC_RO tree_memarea const cpu4_memtree = { &cpu4_memtree_l, &cpu4_memtree_r, cpu4_memareas + 4 };
__SEC_RO tree_memarea const cpu4_memtree_r_l_l_l = { NULL, NULL, cpu4_memareas + 2 };
__SEC_RO tree_memarea const cpu4_memtree_r_l_l = { &cpu4_memtree_r_l_l_l, NULL, cpu4_memareas + 8 };
__SEC_RO tree_memarea const cpu4_memtree_r_l = { &cpu4_memtree_r_l_l, &cpu4_memtree_r_l_r, cpu4_memareas + 9 };
__SEC_RO tree_memarea const cpu4_memtree_r_l_r = { NULL, NULL, cpu4_memareas + 10 };
__SEC_RO tree_memarea const cpu4_memtree_r = { &cpu4_memtree_r_l, &cpu4_memtree_r_r, cpu4_memareas + 11 };
__SEC_RO tree_memarea const cpu4_memtree_r_r_l_l = { NULL, NULL, cpu4_memareas + 6 };
__SEC_RO tree_memarea const cpu4_memtree_r_r_l = { &cpu4_memtree_r_r_l_l, NULL, cpu4_memareas + 7 };
__SEC_RO tree_memarea const cpu4_memtree_r_r = { &cpu4_memtree_r_r_l, &cpu4_memtree_r_r_r, cpu4_memareas + 13 };
__SEC_RO tree_memarea const cpu4_memtree_r_r_r = { NULL, NULL, cpu4_memareas + 12 };
__SEC_RO vm_cpu * const cpu4_vm_cpus[0] = {
};
__SEC_RO memarea const cpu5_memareas[32] = {
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_X|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0, 0, 0, 0, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x40000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x0, 0x0, 0x40000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf7113000, 0x0, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf6800000, 0x0, 0x8000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf7020000, 0x0, 0x10000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf8008000, 0x0, 0x9000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf7030000, 0x0, 0x2000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf0000000, 0x0, 0xfff0000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
};
__SEC_RO tree_memarea const cpu5_memtree_l_l_l_l = { NULL, NULL, cpu5_memareas + 16 };
__SEC_RO tree_memarea const cpu5_memtree_l_l_l = { &cpu5_memtree_l_l_l_l, NULL, cpu5_memareas + 17 };
__SEC_RO tree_memarea const cpu5_memtree_l_l = { &cpu5_memtree_l_l_l, &cpu5_memtree_l_l_r, cpu5_memareas + 25 };
__SEC_RO tree_memarea const cpu5_memtree_l_l_r = { NULL, NULL, cpu5_memareas + 26 };
__SEC_RO tree_memarea const cpu5_memtree_l = { &cpu5_memtree_l_l, &cpu5_memtree_l_r, cpu5_memareas + 27 };
__SEC_RO tree_memarea const cpu5_memtree_l_r_l_l = { NULL, NULL, cpu5_memareas + 31 };
__SEC_RO tree_memarea const cpu5_memtree_l_r_l = { &cpu5_memtree_l_r_l_l, NULL, cpu5_memareas + 0 };
__SEC_RO tree_memarea const cpu5_memtree_l_r = { &cpu5_memtree_l_r_l, &cpu5_memtree_l_r_r, cpu5_memareas + 1 };
__SEC_RO tree_memarea const cpu5_memtree_l_r_r = { NULL, NULL, cpu5_memareas + 3 };
__SEC_RO tree_memarea const cpu5_memtree = { &cpu5_memtree_l, &cpu5_memtree_r, cpu5_memareas + 4 };
__SEC_RO tree_memarea const cpu5_memtree_r_l_l_l = { NULL, NULL, cpu5_memareas + 2 };
__SEC_RO tree_memarea const cpu5_memtree_r_l_l = { &cpu5_memtree_r_l_l_l, NULL, cpu5_memareas + 8 };
__SEC_RO tree_memarea const cpu5_memtree_r_l = { &cpu5_memtree_r_l_l, &cpu5_memtree_r_l_r, cpu5_memareas + 9 };
__SEC_RO tree_memarea const cpu5_memtree_r_l_r = { NULL, NULL, cpu5_memareas + 10 };
__SEC_RO tree_memarea const cpu5_memtree_r = { &cpu5_memtree_r_l, &cpu5_memtree_r_r, cpu5_memareas + 11 };
__SEC_RO tree_memarea const cpu5_memtree_r_r_l_l = { NULL, NULL, cpu5_memareas + 6 };
__SEC_RO tree_memarea const cpu5_memtree_r_r_l = { &cpu5_memtree_r_r_l_l, NULL, cpu5_memareas + 7 };
__SEC_RO tree_memarea const cpu5_memtree_r_r = { &cpu5_memtree_r_r_l, &cpu5_memtree_r_r_r, cpu5_memareas + 13 };
__SEC_RO tree_memarea const cpu5_memtree_r_r_r = { NULL, NULL, cpu5_memareas + 12 };
__SEC_RO vm_cpu * const cpu5_vm_cpus[0] = {
};
__SEC_RO memarea const cpu6_memareas[32] = {
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_X|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0, 0, 0, 0, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x40000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x0, 0x0, 0x40000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf7113000, 0x0, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf6800000, 0x0, 0x8000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf7020000, 0x0, 0x10000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf8008000, 0x0, 0x9000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf7030000, 0x0, 0x2000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf0000000, 0x0, 0xfff0000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
};
__SEC_RO tree_memarea const cpu6_memtree_l_l_l_l = { NULL, NULL, cpu6_memareas + 16 };
__SEC_RO tree_memarea const cpu6_memtree_l_l_l = { &cpu6_memtree_l_l_l_l, NULL, cpu6_memareas + 17 };
__SEC_RO tree_memarea const cpu6_memtree_l_l = { &cpu6_memtree_l_l_l, &cpu6_memtree_l_l_r, cpu6_memareas + 25 };
__SEC_RO tree_memarea const cpu6_memtree_l_l_r = { NULL, NULL, cpu6_memareas + 26 };
__SEC_RO tree_memarea const cpu6_memtree_l = { &cpu6_memtree_l_l, &cpu6_memtree_l_r, cpu6_memareas + 27 };
__SEC_RO tree_memarea const cpu6_memtree_l_r_l_l = { NULL, NULL, cpu6_memareas + 31 };
__SEC_RO tree_memarea const cpu6_memtree_l_r_l = { &cpu6_memtree_l_r_l_l, NULL, cpu6_memareas + 0 };
__SEC_RO tree_memarea const cpu6_memtree_l_r = { &cpu6_memtree_l_r_l, &cpu6_memtree_l_r_r, cpu6_memareas + 1 };
__SEC_RO tree_memarea const cpu6_memtree_l_r_r = { NULL, NULL, cpu6_memareas + 3 };
__SEC_RO tree_memarea const cpu6_memtree = { &cpu6_memtree_l, &cpu6_memtree_r, cpu6_memareas + 4 };
__SEC_RO tree_memarea const cpu6_memtree_r_l_l_l = { NULL, NULL, cpu6_memareas + 2 };
__SEC_RO tree_memarea const cpu6_memtree_r_l_l = { &cpu6_memtree_r_l_l_l, NULL, cpu6_memareas + 8 };
__SEC_RO tree_memarea const cpu6_memtree_r_l = { &cpu6_memtree_r_l_l, &cpu6_memtree_r_l_r, cpu6_memareas + 9 };
__SEC_RO tree_memarea const cpu6_memtree_r_l_r = { NULL, NULL, cpu6_memareas + 10 };
__SEC_RO tree_memarea const cpu6_memtree_r = { &cpu6_memtree_r_l, &cpu6_memtree_r_r, cpu6_memareas + 11 };
__SEC_RO tree_memarea const cpu6_memtree_r_r_l_l = { NULL, NULL, cpu6_memareas + 6 };
__SEC_RO tree_memarea const cpu6_memtree_r_r_l = { &cpu6_memtree_r_r_l_l, NULL, cpu6_memareas + 7 };
__SEC_RO tree_memarea const cpu6_memtree_r_r = { &cpu6_memtree_r_r_l, &cpu6_memtree_r_r_r, cpu6_memareas + 13 };
__SEC_RO tree_memarea const cpu6_memtree_r_r_r = { NULL, NULL, cpu6_memareas + 12 };
__SEC_RO vm_cpu * const cpu6_vm_cpus[0] = {
};
__SEC_RO memarea const cpu7_memareas[32] = {
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_X|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0, 0, 0, 0, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x0, 0x0, 0x0, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x40000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x0, 0x0, 0x40000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf7113000, 0x0, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf6800000, 0x0, 0x8000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf7020000, 0x0, 0x10000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf8008000, 0x0, 0x9000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf7030000, 0x0, 0x2000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf0000000, 0x0, 0xfff0000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
};
__SEC_RO tree_memarea const cpu7_memtree_l_l_l_l = { NULL, NULL, cpu7_memareas + 16 };
__SEC_RO tree_memarea const cpu7_memtree_l_l_l = { &cpu7_memtree_l_l_l_l, NULL, cpu7_memareas + 17 };
__SEC_RO tree_memarea const cpu7_memtree_l_l = { &cpu7_memtree_l_l_l, &cpu7_memtree_l_l_r, cpu7_memareas + 25 };
__SEC_RO tree_memarea const cpu7_memtree_l_l_r = { NULL, NULL, cpu7_memareas + 26 };
__SEC_RO tree_memarea const cpu7_memtree_l = { &cpu7_memtree_l_l, &cpu7_memtree_l_r, cpu7_memareas + 27 };
__SEC_RO tree_memarea const cpu7_memtree_l_r_l_l = { NULL, NULL, cpu7_memareas + 31 };
__SEC_RO tree_memarea const cpu7_memtree_l_r_l = { &cpu7_memtree_l_r_l_l, NULL, cpu7_memareas + 0 };
__SEC_RO tree_memarea const cpu7_memtree_l_r = { &cpu7_memtree_l_r_l, &cpu7_memtree_l_r_r, cpu7_memareas + 1 };
__SEC_RO tree_memarea const cpu7_memtree_l_r_r = { NULL, NULL, cpu7_memareas + 3 };
__SEC_RO tree_memarea const cpu7_memtree = { &cpu7_memtree_l, &cpu7_memtree_r, cpu7_memareas + 4 };
__SEC_RO tree_memarea const cpu7_memtree_r_l_l_l = { NULL, NULL, cpu7_memareas + 2 };
__SEC_RO tree_memarea const cpu7_memtree_r_l_l = { &cpu7_memtree_r_l_l_l, NULL, cpu7_memareas + 8 };
__SEC_RO tree_memarea const cpu7_memtree_r_l = { &cpu7_memtree_r_l_l, &cpu7_memtree_r_l_r, cpu7_memareas + 9 };
__SEC_RO tree_memarea const cpu7_memtree_r_l_r = { NULL, NULL, cpu7_memareas + 10 };
__SEC_RO tree_memarea const cpu7_memtree_r = { &cpu7_memtree_r_l, &cpu7_memtree_r_r, cpu7_memareas + 11 };
__SEC_RO tree_memarea const cpu7_memtree_r_r_l_l = { NULL, NULL, cpu7_memareas + 6 };
__SEC_RO tree_memarea const cpu7_memtree_r_r_l = { &cpu7_memtree_r_r_l_l, NULL, cpu7_memareas + 7 };
__SEC_RO tree_memarea const cpu7_memtree_r_r = { &cpu7_memtree_r_r_l, &cpu7_memtree_r_r_r, cpu7_memareas + 13 };
__SEC_RO tree_memarea const cpu7_memtree_r_r_r = { NULL, NULL, cpu7_memareas + 12 };
__SEC_RO vm_cpu * const cpu7_vm_cpus[0] = {
};
__SEC_RW uintptr_t __placeholder_rw = 0xbeef;
__SEC_RWS uintptr_t __placeholder_rws = 0xf4eebeef;
__SEC_RO vm const vm_linux1 = {
  1, vm_linux1_cpus,
  0, vm_linux1_capabilities,
  3, vm_linux1_copyins,
  0x80000
};
__SEC_RW vm_cpu vm_linux1_cpus[1] = {
  { &vm_linux1, (vm_cpu_state *)0x0, 0,
    0x0, 1,
    5, vm_linux1_cpu0_memareas, &vm_linux1_cpu0_memtree,
    15, vm_linux1_cpu0_emulates, &vm_linux1_cpu0_emulatetree,
    2, vm_linux1_hw_emulates,
    NULL,
    vm_linux1_cpu0_emulates + 1,
    vm_linux1_cpu0_emulates + 0,
    1, vm_linux1_cpu0_scheds },
};
__SEC_RO vm_copyin const vm_linux1_copyins[3] = {
  { 0x80000, 0x0, 0x0 },
  { 0xa000000, 0x0, 0x0 },
  { 0x8000, 0x0, 0x0 },
};
__SEC_RO capability const vm_linux1_capabilities[0] = {
};
__SEC_RW scheduler_entity vm_linux1_cpu0_scheds[1] = {
  { vm_linux1_cpus + 0, SCHEDULER_CLASS_FAIR_SHARE, 0, 0, 100, SCHEDULER_STATE_READY, NULL }
};
__SEC_RO memarea const vm_linux1_cpu0_memareas[5] = {
  { 0x0, 0x0, 0x40000000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_X, cpu0_memareas + 32 },
  { 0xfff80000, 0xfff80000, 0x11000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_X, NULL },
  { 0x0, 0xfee00000, 0x100000, MEMAREA_FLAG_R|MEMAREA_FLAG_S, NULL },
  { 0x0, 0xfef00000, 0x100000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_S, NULL },
  { 0xf6806000, 0xf6802000, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W, cpu0_memareas + 17 },
};
__SEC_RO tree_memarea const vm_linux1_cpu0_memtree_l_l = { NULL, NULL, vm_linux1_cpu0_memareas + 0 };
__SEC_RO tree_memarea const vm_linux1_cpu0_memtree_l = { &vm_linux1_cpu0_memtree_l_l, NULL, vm_linux1_cpu0_memareas + 4 };
__SEC_RO tree_memarea const vm_linux1_cpu0_memtree = { &vm_linux1_cpu0_memtree_l, &vm_linux1_cpu0_memtree_r, vm_linux1_cpu0_memareas + 2 };
__SEC_RO tree_memarea const vm_linux1_cpu0_memtree_r_l = { NULL, NULL, vm_linux1_cpu0_memareas + 3 };
__SEC_RO tree_memarea const vm_linux1_cpu0_memtree_r = { &vm_linux1_cpu0_memtree_r_l, NULL, vm_linux1_cpu0_memareas + 1 };
__SEC_RO emulate const vm_linux1_cpu0_emulates[15] = {
  { 0xf7113000, 0x1000, EMULATE_TYPE_UART_PL011, { &vdev_linux1_uart }, 0 },
  { 0xf6801000, 0x1000, EMULATE_TYPE_IRQ_GIC_VIRTEXT, { &vdev_linux1_gic_cpu0 }, 0 },
  { 0xf8008000, 0x1000, EMULATE_TYPE_TIMER_SP804, { &vdev_linux1_sp804 }, 0 },
  { 0, 0, EMULATE_TYPE_TIMER_ARMCP14, { &vdev_linux1_armcp14_cpu0 }, 0 },
  { 0xf4410000, 0x1000, EMULATE_TYPE_MEMORY_32BIT, { &vdev_linux1_mmio_mediactrl }, 0 },
  { 0xf7010000, 0x24000, EMULATE_TYPE_MEMORY_32BIT, { &vdev_linux1_mmio1 }, 0 },
  { 0xf723d000, 0x3000, EMULATE_TYPE_MEMORY_32BIT, { &vdev_linux1_mmio_dwmmc }, 0 },
  { 0xf7500000, 0x300000, EMULATE_TYPE_MEMORY_32BIT, { &vdev_linux1_mmio_xrange }, 0 },
  { 0xf7800000, 0x2000, EMULATE_TYPE_MEMORY_32BIT, { &vdev_linux1_mmio_aoctrl }, 0 },
  { 0xf8011000, 0x5000, EMULATE_TYPE_MEMORY_32BIT, { &vdev_linux1_mmio3 }, 0 },
  { 0xf7111000, 0x1000, EMULATE_TYPE_MEMORY_32BIT, { &vdev_linux1_mmio_uart1 }, 0 },
  { 0xf7112000, 0x1000, EMULATE_TYPE_MEMORY_32BIT, { &vdev_linux1_mmio_uart2 }, 0 },
  { 0xf7114000, 0x1000, EMULATE_TYPE_MEMORY_32BIT, { &vdev_linux1_mmio_uart4 }, 0 },
  { 0xf7100000, 0x8000, EMULATE_TYPE_MEMORY_32BIT, { &vdev_linux1_mmio4 }, 0 },
  { 0xf8000000, 0x8000, EMULATE_TYPE_MEMORY_32BIT, { &vdev_linux1_mmio2 }, 0 },
};
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_l_l_l = { NULL, NULL, vm_linux1_cpu0_emulates + 4 };
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_l_l = { &vm_linux1_cpu0_emulatetree_l_l_l, &vm_linux1_cpu0_emulatetree_l_l_r, vm_linux1_cpu0_emulates + 1 };
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_l_l_r = { NULL, NULL, vm_linux1_cpu0_emulates + 5 };
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_l = { &vm_linux1_cpu0_emulatetree_l_l, &vm_linux1_cpu0_emulatetree_l_r, vm_linux1_cpu0_emulates + 13 };
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_l_r_l = { NULL, NULL, vm_linux1_cpu0_emulates + 10 };
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_l_r = { &vm_linux1_cpu0_emulatetree_l_r_l, &vm_linux1_cpu0_emulatetree_l_r_r, vm_linux1_cpu0_emulates + 11 };
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_l_r_r = { NULL, NULL, vm_linux1_cpu0_emulates + 0 };
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree = { &vm_linux1_cpu0_emulatetree_l, &vm_linux1_cpu0_emulatetree_r, vm_linux1_cpu0_emulates + 12 };
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_r_l_l = { NULL, NULL, vm_linux1_cpu0_emulates + 6 };
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_r_l = { &vm_linux1_cpu0_emulatetree_r_l_l, &vm_linux1_cpu0_emulatetree_r_l_r, vm_linux1_cpu0_emulates + 7 };
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_r_l_r = { NULL, NULL, vm_linux1_cpu0_emulates + 8 };
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_r = { &vm_linux1_cpu0_emulatetree_r_l, &vm_linux1_cpu0_emulatetree_r_r, vm_linux1_cpu0_emulates + 14 };
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_r_r_l = { NULL, NULL, vm_linux1_cpu0_emulates + 2 };
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_r_r = { &vm_linux1_cpu0_emulatetree_r_r_l, NULL, vm_linux1_cpu0_emulates + 9 };
__SEC_RWS emulate_uart_pl011 vdev_linux1_uart = {};
__SEC_RW emulate_irq_gic vdev_linux1_gic_cpu0 = { 0, 0, 0, 0, {}, {}, {}, {}, &vdev_linux1_gic_dist, {}, 0 };
__SEC_RWS emulate_irq_gic_distributor vdev_linux1_gic_dist = {};
__SEC_RWS emulate_timer_sp804 vdev_linux1_sp804 = {};
__SEC_RW emulate_timer_armcp14 vdev_linux1_armcp14_cpu0 = {};
__SEC_RO emulate_memory const vdev_linux1_mmio_mediactrl = {
  EMULATE_MEMORY_FLAG_SINGLE_VALUE|EMULATE_MEMORY_FLAG_SINGLE_MEM_RMASK|EMULATE_MEMORY_FLAG_SINGLE_MEM_WMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_RMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_WMASK,
  0x0, 0xffffffff, 0x0, 0x0, 0x0,
  NULL,
  (volatile uint32_t *)0x0,
  NULL,
  NULL,
  NULL,
  NULL
};
__SEC_RO emulate_memory const vdev_linux1_mmio1 = {
  EMULATE_MEMORY_FLAG_SINGLE_VALUE|EMULATE_MEMORY_FLAG_SINGLE_MEM_RMASK|EMULATE_MEMORY_FLAG_SINGLE_MEM_WMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_RMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_WMASK,
  0x0, 0xffffffff, 0x0, 0x0, 0x0,
  NULL,
  (volatile uint32_t *)0x0,
  NULL,
  NULL,
  NULL,
  NULL
};
__SEC_RO emulate_memory const vdev_linux1_mmio_dwmmc = {
  EMULATE_MEMORY_FLAG_SINGLE_VALUE|EMULATE_MEMORY_FLAG_SINGLE_MEM_RMASK|EMULATE_MEMORY_FLAG_SINGLE_MEM_WMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_RMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_WMASK,
  0x0, 0xffffffff, 0x0, 0x0, 0x0,
  NULL,
  (volatile uint32_t *)0x0,
  NULL,
  NULL,
  NULL,
  NULL
};
__SEC_RO emulate_memory const vdev_linux1_mmio_xrange = {
  EMULATE_MEMORY_FLAG_SINGLE_VALUE|EMULATE_MEMORY_FLAG_SINGLE_MEM_RMASK|EMULATE_MEMORY_FLAG_SINGLE_MEM_WMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_RMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_WMASK,
  0x0, 0xffffffff, 0x0, 0x0, 0x0,
  NULL,
  (volatile uint32_t *)0x0,
  NULL,
  NULL,
  NULL,
  NULL
};
__SEC_RO emulate_memory const vdev_linux1_mmio_aoctrl = {
  EMULATE_MEMORY_FLAG_SINGLE_VALUE|EMULATE_MEMORY_FLAG_SINGLE_MEM_RMASK|EMULATE_MEMORY_FLAG_SINGLE_MEM_WMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_RMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_WMASK,
  0x0, 0xffffffff, 0x0, 0x0, 0x0,
  NULL,
  (volatile uint32_t *)0x0,
  NULL,
  NULL,
  NULL,
  NULL
};
__SEC_RO emulate_memory const vdev_linux1_mmio3 = {
  EMULATE_MEMORY_FLAG_SINGLE_VALUE|EMULATE_MEMORY_FLAG_SINGLE_MEM_RMASK|EMULATE_MEMORY_FLAG_SINGLE_MEM_WMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_RMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_WMASK,
  0x0, 0xffffffff, 0x0, 0x0, 0x0,
  NULL,
  (volatile uint32_t *)0x0,
  NULL,
  NULL,
  NULL,
  NULL
};
__SEC_RO emulate_memory const vdev_linux1_mmio_uart1 = {
  EMULATE_MEMORY_FLAG_SINGLE_VALUE|EMULATE_MEMORY_FLAG_SINGLE_MEM_RMASK|EMULATE_MEMORY_FLAG_SINGLE_MEM_WMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_RMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_WMASK,
  0x0, 0xffffffff, 0x0, 0x0, 0x0,
  NULL,
  (volatile uint32_t *)0x0,
  NULL,
  NULL,
  NULL,
  NULL
};
__SEC_RO emulate_memory const vdev_linux1_mmio_uart2 = {
  EMULATE_MEMORY_FLAG_SINGLE_VALUE|EMULATE_MEMORY_FLAG_SINGLE_MEM_RMASK|EMULATE_MEMORY_FLAG_SINGLE_MEM_WMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_RMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_WMASK,
  0x0, 0xffffffff, 0x0, 0x0, 0x0,
  NULL,
  (volatile uint32_t *)0x0,
  NULL,
  NULL,
  NULL,
  NULL
};
__SEC_RO emulate_memory const vdev_linux1_mmio_uart4 = {
  EMULATE_MEMORY_FLAG_SINGLE_VALUE|EMULATE_MEMORY_FLAG_SINGLE_MEM_RMASK|EMULATE_MEMORY_FLAG_SINGLE_MEM_WMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_RMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_WMASK,
  0x0, 0xffffffff, 0x0, 0x0, 0x0,
  NULL,
  (volatile uint32_t *)0x0,
  NULL,
  NULL,
  NULL,
  NULL
};
__SEC_RO emulate_memory const vdev_linux1_mmio4 = {
  EMULATE_MEMORY_FLAG_SINGLE_VALUE|EMULATE_MEMORY_FLAG_SINGLE_MEM_RMASK|EMULATE_MEMORY_FLAG_SINGLE_MEM_WMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_RMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_WMASK,
  0x0, 0xffffffff, 0x0, 0x0, 0x0,
  NULL,
  (volatile uint32_t *)0x0,
  NULL,
  NULL,
  NULL,
  NULL
};
__SEC_RO emulate_memory const vdev_linux1_mmio2 = {
  EMULATE_MEMORY_FLAG_SINGLE_VALUE|EMULATE_MEMORY_FLAG_SINGLE_MEM_RMASK|EMULATE_MEMORY_FLAG_SINGLE_MEM_WMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_RMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_WMASK,
  0x0, 0xffffffff, 0x0, 0x0, 0x0,
  NULL,
  (volatile uint32_t *)0x0,
  NULL,
  NULL,
  NULL,
  NULL
};
__SEC_RO const emulate * const vm_linux1_hw_emulates[2] = { vm_linux1_cpu0_emulates + 1, vm_linux1_cpu0_emulates + 3, };

