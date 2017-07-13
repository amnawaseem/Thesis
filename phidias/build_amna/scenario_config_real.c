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
__SEC_RO specification_cpu const _specification_cpus[2];
__SEC_RO memarea const cpu0_memareas[39];
__SEC_RO tree_memarea const cpu0_memtree_l_l_l_l;
__SEC_RO tree_memarea const cpu0_memtree_l_l_l;
__SEC_RO tree_memarea const cpu0_memtree_l_l_l_r;
__SEC_RO tree_memarea const cpu0_memtree_l_l;
__SEC_RO tree_memarea const cpu0_memtree_l_l_r_l;
__SEC_RO tree_memarea const cpu0_memtree_l_l_r;
__SEC_RO tree_memarea const cpu0_memtree_l;
__SEC_RO tree_memarea const cpu0_memtree_l_r_l_l;
__SEC_RO tree_memarea const cpu0_memtree_l_r_l;
__SEC_RO tree_memarea const cpu0_memtree_l_r_l_r;
__SEC_RO tree_memarea const cpu0_memtree_l_r;
__SEC_RO tree_memarea const cpu0_memtree_l_r_r_l;
__SEC_RO tree_memarea const cpu0_memtree_l_r_r;
__SEC_RO tree_memarea const cpu0_memtree;
__SEC_RO tree_memarea const cpu0_memtree_r_l_l_l;
__SEC_RO tree_memarea const cpu0_memtree_r_l_l;
__SEC_RO tree_memarea const cpu0_memtree_r_l_l_r;
__SEC_RO tree_memarea const cpu0_memtree_r_l;
__SEC_RO tree_memarea const cpu0_memtree_r_l_r_l;
__SEC_RO tree_memarea const cpu0_memtree_r_l_r;
__SEC_RO tree_memarea const cpu0_memtree_r;
__SEC_RO tree_memarea const cpu0_memtree_r_r_l_l;
__SEC_RO tree_memarea const cpu0_memtree_r_r_l;
__SEC_RO tree_memarea const cpu0_memtree_r_r;
__SEC_RO tree_memarea const cpu0_memtree_r_r_r_l;
__SEC_RO tree_memarea const cpu0_memtree_r_r_r;
__SEC_RO vm_cpu * const cpu0_vm_cpus[2];
__SEC_RO memarea const cpu1_memareas[35];
__SEC_RO tree_memarea const cpu1_memtree_l_l_l_l;
__SEC_RO tree_memarea const cpu1_memtree_l_l_l;
__SEC_RO tree_memarea const cpu1_memtree_l_l;
__SEC_RO tree_memarea const cpu1_memtree_l_l_r_l;
__SEC_RO tree_memarea const cpu1_memtree_l_l_r;
__SEC_RO tree_memarea const cpu1_memtree_l;
__SEC_RO tree_memarea const cpu1_memtree_l_r_l_l;
__SEC_RO tree_memarea const cpu1_memtree_l_r_l;
__SEC_RO tree_memarea const cpu1_memtree_l_r;
__SEC_RO tree_memarea const cpu1_memtree_l_r_r_l;
__SEC_RO tree_memarea const cpu1_memtree_l_r_r;
__SEC_RO tree_memarea const cpu1_memtree;
__SEC_RO tree_memarea const cpu1_memtree_r_l_l_l;
__SEC_RO tree_memarea const cpu1_memtree_r_l_l;
__SEC_RO tree_memarea const cpu1_memtree_r_l;
__SEC_RO tree_memarea const cpu1_memtree_r_l_r_l;
__SEC_RO tree_memarea const cpu1_memtree_r_l_r;
__SEC_RO tree_memarea const cpu1_memtree_r;
__SEC_RO tree_memarea const cpu1_memtree_r_r_l_l;
__SEC_RO tree_memarea const cpu1_memtree_r_r_l;
__SEC_RO tree_memarea const cpu1_memtree_r_r;
__SEC_RO tree_memarea const cpu1_memtree_r_r_r;
__SEC_RO vm_cpu * const cpu1_vm_cpus[0];
__SEC_RW uintptr_t __placeholder_rw;
__SEC_RWS uintptr_t __placeholder_rws;
__SEC_RO vm const vm_linux1;
__SEC_RW vm_cpu vm_linux1_cpus[1];
__SEC_RO vm_copyin const vm_linux1_copyins[3];
__SEC_RO capability const vm_linux1_capabilities[1];
__SEC_RW scheduler_entity vm_linux1_cpu0_scheds[1];
__SEC_RO memarea const vm_linux1_cpu0_memareas[6];
__SEC_RO tree_memarea const vm_linux1_cpu0_memtree_l_l;
__SEC_RO tree_memarea const vm_linux1_cpu0_memtree_l;
__SEC_RO tree_memarea const vm_linux1_cpu0_memtree_l_r;
__SEC_RO tree_memarea const vm_linux1_cpu0_memtree;
__SEC_RO tree_memarea const vm_linux1_cpu0_memtree_r_l;
__SEC_RO tree_memarea const vm_linux1_cpu0_memtree_r;
__SEC_RO emulate const vm_linux1_cpu0_emulates[13];
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_l_l_l;
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_l_l;
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_l_l_r;
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_l;
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_l_r_l;
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_l_r;
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree;
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_r_l_l;
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_r_l;
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
__SEC_RO emulate_memory const vdev_linux1_mmio_aoctrl;
__SEC_RO emulate_memory const vdev_linux1_mmio3;
__SEC_RO emulate_memory const vdev_linux1_mmio_uart1;
__SEC_RO emulate_memory const vdev_linux1_mmio_uart2;
__SEC_RO emulate_memory const vdev_linux1_mmio_uart4;
__SEC_RO emulate_memory const vdev_linux1_mmio4;
__SEC_RO emulate_memory const vdev_linux1_mmio2;
__SEC_RO const emulate * const vm_linux1_hw_emulates[2];
__SEC_RO vm const vm_linux2;
__SEC_RW vm_cpu vm_linux2_cpus[1];
__SEC_RO vm_copyin const vm_linux2_copyins[3];
__SEC_RO capability const vm_linux2_capabilities[1];
__SEC_RW scheduler_entity vm_linux2_cpu0_scheds[1];
__SEC_RO memarea const vm_linux2_cpu0_memareas[5];
__SEC_RO tree_memarea const vm_linux2_cpu0_memtree_l_l;
__SEC_RO tree_memarea const vm_linux2_cpu0_memtree_l;
__SEC_RO tree_memarea const vm_linux2_cpu0_memtree;
__SEC_RO tree_memarea const vm_linux2_cpu0_memtree_r_l;
__SEC_RO tree_memarea const vm_linux2_cpu0_memtree_r;
__SEC_RO emulate const vm_linux2_cpu0_emulates[13];
__SEC_RO tree_emulate const vm_linux2_cpu0_emulatetree_l_l_l;
__SEC_RO tree_emulate const vm_linux2_cpu0_emulatetree_l_l;
__SEC_RO tree_emulate const vm_linux2_cpu0_emulatetree_l_l_r;
__SEC_RO tree_emulate const vm_linux2_cpu0_emulatetree_l;
__SEC_RO tree_emulate const vm_linux2_cpu0_emulatetree_l_r_l;
__SEC_RO tree_emulate const vm_linux2_cpu0_emulatetree_l_r;
__SEC_RO tree_emulate const vm_linux2_cpu0_emulatetree;
__SEC_RO tree_emulate const vm_linux2_cpu0_emulatetree_r_l_l;
__SEC_RO tree_emulate const vm_linux2_cpu0_emulatetree_r_l;
__SEC_RO tree_emulate const vm_linux2_cpu0_emulatetree_r;
__SEC_RO tree_emulate const vm_linux2_cpu0_emulatetree_r_r_l;
__SEC_RO tree_emulate const vm_linux2_cpu0_emulatetree_r_r;
__SEC_RWS emulate_uart_pl011 vdev_linux2_uart;
__SEC_RW emulate_irq_gic vdev_linux2_gic_cpu0;
__SEC_RWS emulate_irq_gic_distributor vdev_linux2_gic_dist;
__SEC_RWS emulate_timer_sp804 vdev_linux2_sp804;
__SEC_RW emulate_timer_armcp14 vdev_linux2_armcp14_cpu0;
__SEC_RO emulate_memory const vdev_linux2_mmio_mediactrl;
__SEC_RO emulate_memory const vdev_linux2_mmio1;
__SEC_RO emulate_memory const vdev_linux2_mmio_aoctrl;
__SEC_RO emulate_memory const vdev_linux2_mmio3;
__SEC_RO emulate_memory const vdev_linux2_mmio_uart1;
__SEC_RO emulate_memory const vdev_linux2_mmio_uart2;
__SEC_RO emulate_memory const vdev_linux2_mmio_uart4;
__SEC_RO emulate_memory const vdev_linux2_mmio4;
__SEC_RO emulate_memory const vdev_linux2_mmio2;
__SEC_RO const emulate * const vm_linux2_hw_emulates[2];


__SEC_ROH specification const _specification = {
  "PHIDSPEC", 0x10016000, 0xf4000e000, 0x10022000, 2, _specification_cpus, _specification_irq_owners, &_specification_arch, "2017/07/13 16:58:36"
};
__SEC_RO const vm * const _specification_irq_owners[IRQID_MAXIMUM] = {
};
__SEC_RO specification_arch const _specification_arch = {};
__SEC_RO specification_cpu const _specification_cpus[2] = {
  { 0x10034000, 39, cpu0_memareas, &cpu0_memtree, 2, cpu0_vm_cpus, {} },
  { 0x10044000, 35, cpu1_memareas, &cpu1_memtree, 0, NULL, {} },
};
__SEC_RO memarea const cpu0_memareas[39] = {
  { 0x10008000, 0xf40000000, 0x9000, MEMAREA_FLAG_R|MEMAREA_FLAG_X|MEMAREA_FLAG_G, NULL },
  { 0x10011000, 0xf40009000, 0x3000, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x2e0000, 0xf4000d000, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x10014000, 0xf4000c000, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x10015000, 0xf401e3000, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0, 0, 0, 0, NULL },
  { 0x1006d000, 0xf50200000, 0x136d000, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x2e4000, 0xf401e7000, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x10016000, 0xf4000e000, 0x5000, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x2e2000, 0xf40013000, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x1001c000, 0xf40014000, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x1001b000, 0xf401e5000, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x280000, 0xf40158000, 0x40000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x200000, 0xf40117000, 0x40000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf7113000, 0xf401e1000, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf6800000, 0xf401d5000, 0x8000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf7020000, 0xf401ba000, 0x10000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf8008000, 0xf401cb000, 0x9000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf7030000, 0xf401de000, 0x2000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf0000000, 0xf40200000, 0xfff0000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0x0, 0xf40016000, 0x100000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x100000, 0xf5156e000, 0x100000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x2c0000, 0xf40199000, 0x20000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x11400000, 0x200000, 0x30000000, MEMAREA_FLAG_R|MEMAREA_FLAG_W, NULL },
  { 0x2e6000, 0xf401e9000, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x41400000, 0x30400000, 0x30000000, MEMAREA_FLAG_R|MEMAREA_FLAG_W, NULL },
  { 0x2e7000, 0xf401eb000, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
};
__SEC_RO tree_memarea const cpu0_memtree_l_l_l_l = { NULL, NULL, cpu0_memareas + 35 };
__SEC_RO tree_memarea const cpu0_memtree_l_l_l = { &cpu0_memtree_l_l_l_l, &cpu0_memtree_l_l_l_r, cpu0_memareas + 37 };
__SEC_RO tree_memarea const cpu0_memtree_l_l_l_r = { NULL, NULL, cpu0_memareas + 0 };
__SEC_RO tree_memarea const cpu0_memtree_l_l = { &cpu0_memtree_l_l_l, &cpu0_memtree_l_l_r, cpu0_memareas + 1 };
__SEC_RO tree_memarea const cpu0_memtree_l_l_r_l = { NULL, NULL, cpu0_memareas + 3 };
__SEC_RO tree_memarea const cpu0_memtree_l_l_r = { &cpu0_memtree_l_l_r_l, NULL, cpu0_memareas + 2 };
__SEC_RO tree_memarea const cpu0_memtree_l = { &cpu0_memtree_l_l, &cpu0_memtree_l_r, cpu0_memareas + 8 };
__SEC_RO tree_memarea const cpu0_memtree_l_r_l_l = { NULL, NULL, cpu0_memareas + 9 };
__SEC_RO tree_memarea const cpu0_memtree_l_r_l = { &cpu0_memtree_l_r_l_l, &cpu0_memtree_l_r_l_r, cpu0_memareas + 10 };
__SEC_RO tree_memarea const cpu0_memtree_l_r_l_r = { NULL, NULL, cpu0_memareas + 32 };
__SEC_RO tree_memarea const cpu0_memtree_l_r = { &cpu0_memtree_l_r_l, &cpu0_memtree_l_r_r, cpu0_memareas + 13 };
__SEC_RO tree_memarea const cpu0_memtree_l_r_r_l = { NULL, NULL, cpu0_memareas + 12 };
__SEC_RO tree_memarea const cpu0_memtree_l_r_r = { &cpu0_memtree_l_r_r_l, NULL, cpu0_memareas + 34 };
__SEC_RO tree_memarea const cpu0_memtree = { &cpu0_memtree_l, &cpu0_memtree_r, cpu0_memareas + 25 };
__SEC_RO tree_memarea const cpu0_memtree_r_l_l_l = { NULL, NULL, cpu0_memareas + 26 };
__SEC_RO tree_memarea const cpu0_memtree_r_l_l = { &cpu0_memtree_r_l_l_l, &cpu0_memtree_r_l_l_r, cpu0_memareas + 17 };
__SEC_RO tree_memarea const cpu0_memtree_r_l_l_r = { NULL, NULL, cpu0_memareas + 27 };
__SEC_RO tree_memarea const cpu0_memtree_r_l = { &cpu0_memtree_r_l_l, &cpu0_memtree_r_l_r, cpu0_memareas + 16 };
__SEC_RO tree_memarea const cpu0_memtree_r_l_r_l = { NULL, NULL, cpu0_memareas + 4 };
__SEC_RO tree_memarea const cpu0_memtree_r_l_r = { &cpu0_memtree_r_l_r_l, NULL, cpu0_memareas + 11 };
__SEC_RO tree_memarea const cpu0_memtree_r = { &cpu0_memtree_r_l, &cpu0_memtree_r_r, cpu0_memareas + 7 };
__SEC_RO tree_memarea const cpu0_memtree_r_r_l_l = { NULL, NULL, cpu0_memareas + 38 };
__SEC_RO tree_memarea const cpu0_memtree_r_r_l = { &cpu0_memtree_r_r_l_l, NULL, cpu0_memareas + 36 };
__SEC_RO tree_memarea const cpu0_memtree_r_r = { &cpu0_memtree_r_r_l, &cpu0_memtree_r_r_r, cpu0_memareas + 31 };
__SEC_RO tree_memarea const cpu0_memtree_r_r_r_l = { NULL, NULL, cpu0_memareas + 6 };
__SEC_RO tree_memarea const cpu0_memtree_r_r_r = { &cpu0_memtree_r_r_r_l, NULL, cpu0_memareas + 33 };
__SEC_RO vm_cpu * const cpu0_vm_cpus[2] = {
  vm_linux1_cpus + 0,
  vm_linux2_cpus + 0,
};
__SEC_RO memarea const cpu1_memareas[35] = {
  { 0x10008000, 0xf40000000, 0x9000, MEMAREA_FLAG_R|MEMAREA_FLAG_X|MEMAREA_FLAG_G, NULL },
  { 0x10011000, 0xf40009000, 0x3000, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x2e1000, 0xf4000d000, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x10014000, 0xf4000c000, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x10015000, 0xf401e3000, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0, 0, 0, 0, NULL },
  { 0x1006d000, 0xf50200000, 0x136d000, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x2e5000, 0xf401e7000, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x10016000, 0xf4000e000, 0x5000, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x2e3000, 0xf40013000, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x1001c000, 0xf40014000, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x1001b000, 0xf401e5000, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_G, NULL },
  { 0x280000, 0xf40158000, 0x40000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x240000, 0xf40117000, 0x40000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf7113000, 0xf401e1000, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf6800000, 0xf401d5000, 0x8000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf7020000, 0xf401ba000, 0x10000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf8008000, 0xf401cb000, 0x9000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0xf7030000, 0xf401de000, 0x2000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0, 0, 0, 0, NULL },
  { 0xf0000000, 0xf40200000, 0xfff0000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_D, NULL },
  { 0x0, 0xf40016000, 0x100000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x100000, 0xf5156e000, 0x100000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
  { 0x2c0000, 0xf40199000, 0x20000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G|MEMAREA_FLAG_S, NULL },
};
__SEC_RO tree_memarea const cpu1_memtree_l_l_l_l = { NULL, NULL, cpu1_memareas + 0 };
__SEC_RO tree_memarea const cpu1_memtree_l_l_l = { &cpu1_memtree_l_l_l_l, NULL, cpu1_memareas + 1 };
__SEC_RO tree_memarea const cpu1_memtree_l_l = { &cpu1_memtree_l_l_l, &cpu1_memtree_l_l_r, cpu1_memareas + 3 };
__SEC_RO tree_memarea const cpu1_memtree_l_l_r_l = { NULL, NULL, cpu1_memareas + 2 };
__SEC_RO tree_memarea const cpu1_memtree_l_l_r = { &cpu1_memtree_l_l_r_l, NULL, cpu1_memareas + 8 };
__SEC_RO tree_memarea const cpu1_memtree_l = { &cpu1_memtree_l_l, &cpu1_memtree_l_r, cpu1_memareas + 9 };
__SEC_RO tree_memarea const cpu1_memtree_l_r_l_l = { NULL, NULL, cpu1_memareas + 10 };
__SEC_RO tree_memarea const cpu1_memtree_l_r_l = { &cpu1_memtree_l_r_l_l, NULL, cpu1_memareas + 32 };
__SEC_RO tree_memarea const cpu1_memtree_l_r = { &cpu1_memtree_l_r_l, &cpu1_memtree_l_r_r, cpu1_memareas + 13 };
__SEC_RO tree_memarea const cpu1_memtree_l_r_r_l = { NULL, NULL, cpu1_memareas + 12 };
__SEC_RO tree_memarea const cpu1_memtree_l_r_r = { &cpu1_memtree_l_r_r_l, NULL, cpu1_memareas + 34 };
__SEC_RO tree_memarea const cpu1_memtree = { &cpu1_memtree_l, &cpu1_memtree_r, cpu1_memareas + 25 };
__SEC_RO tree_memarea const cpu1_memtree_r_l_l_l = { NULL, NULL, cpu1_memareas + 26 };
__SEC_RO tree_memarea const cpu1_memtree_r_l_l = { &cpu1_memtree_r_l_l_l, NULL, cpu1_memareas + 17 };
__SEC_RO tree_memarea const cpu1_memtree_r_l = { &cpu1_memtree_r_l_l, &cpu1_memtree_r_l_r, cpu1_memareas + 27 };
__SEC_RO tree_memarea const cpu1_memtree_r_l_r_l = { NULL, NULL, cpu1_memareas + 16 };
__SEC_RO tree_memarea const cpu1_memtree_r_l_r = { &cpu1_memtree_r_l_r_l, NULL, cpu1_memareas + 4 };
__SEC_RO tree_memarea const cpu1_memtree_r = { &cpu1_memtree_r_l, &cpu1_memtree_r_r, cpu1_memareas + 11 };
__SEC_RO tree_memarea const cpu1_memtree_r_r_l_l = { NULL, NULL, cpu1_memareas + 7 };
__SEC_RO tree_memarea const cpu1_memtree_r_r_l = { &cpu1_memtree_r_r_l_l, NULL, cpu1_memareas + 31 };
__SEC_RO tree_memarea const cpu1_memtree_r_r = { &cpu1_memtree_r_r_l, &cpu1_memtree_r_r_r, cpu1_memareas + 6 };
__SEC_RO tree_memarea const cpu1_memtree_r_r_r = { NULL, NULL, cpu1_memareas + 33 };
__SEC_RO vm_cpu * const cpu1_vm_cpus[0] = {
};
__SEC_RW uintptr_t __placeholder_rw = 0xbeef;
__SEC_RWS uintptr_t __placeholder_rws = 0xf4eebeef;
__SEC_RO vm const vm_linux1 = {
  1, vm_linux1_cpus,
  1, vm_linux1_capabilities,
  3, vm_linux1_copyins,
  0x80000
};
__SEC_RW vm_cpu vm_linux1_cpus[1] = {
  { &vm_linux1, (vm_cpu_state *)0xf401e9000, 0,
    0x10046000, 1,
    6, vm_linux1_cpu0_memareas, &vm_linux1_cpu0_memtree,
    13, vm_linux1_cpu0_emulates, &vm_linux1_cpu0_emulatetree,
    2, vm_linux1_hw_emulates,
    NULL,
    vm_linux1_cpu0_emulates + 1,
    vm_linux1_cpu0_emulates + 0,
    1, vm_linux1_cpu0_scheds },
};
__SEC_RO vm_copyin const vm_linux1_copyins[3] = {
  { 0x280000, 0xf50200000, 0x893808 },
  { 0xa200000, 0xf50a93808, 0xad1958 },
  { 0x208000, 0xf51565160, 0x7df7 },
};
__SEC_RO capability const vm_linux1_capabilities[1] = {
  { &vm_linux2, CAPABILITY_TYPE_IRQ, 0x9 },
};
__SEC_RW scheduler_entity vm_linux1_cpu0_scheds[1] = {
  { vm_linux1_cpus + 0, SCHEDULER_CLASS_FAIR_SHARE, 0, 0, 100, SCHEDULER_STATE_READY, NULL }
};
__SEC_RO memarea const vm_linux1_cpu0_memareas[6] = {
  { 0x11400000, 0x0, 0x30000000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_X, cpu0_memareas + 35 },
  { 0xfff80000, 0xfff80000, 0x11000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_X, NULL },
  { 0x100000, 0xfee00000, 0x100000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_S, cpu0_memareas + 33 },
  { 0x0, 0xfef00000, 0x100000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_S, cpu0_memareas + 32 },
  { 0x2c0000, 0xff000000, 0x20000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_S, cpu0_memareas + 34 },
  { 0xf6806000, 0xf6802000, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W, cpu0_memareas + 17 },
};
__SEC_RO tree_memarea const vm_linux1_cpu0_memtree_l_l = { NULL, NULL, vm_linux1_cpu0_memareas + 0 };
__SEC_RO tree_memarea const vm_linux1_cpu0_memtree_l = { &vm_linux1_cpu0_memtree_l_l, &vm_linux1_cpu0_memtree_l_r, vm_linux1_cpu0_memareas + 5 };
__SEC_RO tree_memarea const vm_linux1_cpu0_memtree_l_r = { NULL, NULL, vm_linux1_cpu0_memareas + 2 };
__SEC_RO tree_memarea const vm_linux1_cpu0_memtree = { &vm_linux1_cpu0_memtree_l, &vm_linux1_cpu0_memtree_r, vm_linux1_cpu0_memareas + 3 };
__SEC_RO tree_memarea const vm_linux1_cpu0_memtree_r_l = { NULL, NULL, vm_linux1_cpu0_memareas + 4 };
__SEC_RO tree_memarea const vm_linux1_cpu0_memtree_r = { &vm_linux1_cpu0_memtree_r_l, NULL, vm_linux1_cpu0_memareas + 1 };
__SEC_RO emulate const vm_linux1_cpu0_emulates[13] = {
  { 0xf7113000, 0x1000, EMULATE_TYPE_UART_PL011, { &vdev_linux1_uart }, 0 },
  { 0xf6801000, 0x1000, EMULATE_TYPE_IRQ_GIC_VIRTEXT, { &vdev_linux1_gic_cpu0 }, 0 },
  { 0xf8008000, 0x1000, EMULATE_TYPE_TIMER_SP804, { &vdev_linux1_sp804 }, 0 },
  { 0, 0, EMULATE_TYPE_TIMER_ARMCP14, { &vdev_linux1_armcp14_cpu0 }, 0 },
  { 0xf4410000, 0x1000, EMULATE_TYPE_MEMORY_32BIT, { &vdev_linux1_mmio_mediactrl }, 0 },
  { 0xf7020000, 0x14000, EMULATE_TYPE_MEMORY_32BIT, { &vdev_linux1_mmio1 }, 0 },
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
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_l = { &vm_linux1_cpu0_emulatetree_l_l, &vm_linux1_cpu0_emulatetree_l_r, vm_linux1_cpu0_emulates + 11 };
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_l_r_l = { NULL, NULL, vm_linux1_cpu0_emulates + 8 };
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_l_r = { &vm_linux1_cpu0_emulatetree_l_r_l, NULL, vm_linux1_cpu0_emulates + 9 };
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree = { &vm_linux1_cpu0_emulatetree_l, &vm_linux1_cpu0_emulatetree_r, vm_linux1_cpu0_emulates + 0 };
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_r_l_l = { NULL, NULL, vm_linux1_cpu0_emulates + 10 };
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_r_l = { &vm_linux1_cpu0_emulatetree_r_l_l, NULL, vm_linux1_cpu0_emulates + 6 };
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_r = { &vm_linux1_cpu0_emulatetree_r_l, &vm_linux1_cpu0_emulatetree_r_r, vm_linux1_cpu0_emulates + 12 };
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_r_r_l = { NULL, NULL, vm_linux1_cpu0_emulates + 2 };
__SEC_RO tree_emulate const vm_linux1_cpu0_emulatetree_r_r = { &vm_linux1_cpu0_emulatetree_r_r_l, NULL, vm_linux1_cpu0_emulates + 7 };
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
__SEC_RO vm const vm_linux2 = {
  1, vm_linux2_cpus,
  1, vm_linux2_capabilities,
  3, vm_linux2_copyins,
  0x80000
};
__SEC_RW vm_cpu vm_linux2_cpus[1] = {
  { &vm_linux2, (vm_cpu_state *)0xf401eb000, 0,
    0x1004e000, 2,
    5, vm_linux2_cpu0_memareas, &vm_linux2_cpu0_memtree,
    13, vm_linux2_cpu0_emulates, &vm_linux2_cpu0_emulatetree,
    2, vm_linux2_hw_emulates,
    NULL,
    vm_linux2_cpu0_emulates + 1,
    vm_linux2_cpu0_emulates + 0,
    1, vm_linux2_cpu0_scheds },
};
__SEC_RO vm_copyin const vm_linux2_copyins[3] = {
  { 0x30480000, 0xf50200000, 0x893808 },
  { 0x3a400000, 0xf50a93808, 0xad1958 },
  { 0x30408000, 0xf51565160, 0x7df7 },
};
__SEC_RO capability const vm_linux2_capabilities[1] = {
  { &vm_linux1, CAPABILITY_TYPE_IRQ, 0x9 },
};
__SEC_RW scheduler_entity vm_linux2_cpu0_scheds[1] = {
  { vm_linux2_cpus + 0, SCHEDULER_CLASS_FAIR_SHARE, 0, 0, 100, SCHEDULER_STATE_READY, NULL }
};
__SEC_RO memarea const vm_linux2_cpu0_memareas[5] = {
  { 0x41400000, 0x0, 0x30000000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_X, cpu0_memareas + 37 },
  { 0x100000, 0xfee00000, 0x100000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_S, cpu0_memareas + 33 },
  { 0x0, 0xfef00000, 0x100000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_S, cpu0_memareas + 32 },
  { 0x2c0000, 0xff000000, 0x20000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_S, cpu0_memareas + 34 },
  { 0xf6806000, 0xf6802000, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W, cpu0_memareas + 17 },
};
__SEC_RO tree_memarea const vm_linux2_cpu0_memtree_l_l = { NULL, NULL, vm_linux2_cpu0_memareas + 0 };
__SEC_RO tree_memarea const vm_linux2_cpu0_memtree_l = { &vm_linux2_cpu0_memtree_l_l, NULL, vm_linux2_cpu0_memareas + 4 };
__SEC_RO tree_memarea const vm_linux2_cpu0_memtree = { &vm_linux2_cpu0_memtree_l, &vm_linux2_cpu0_memtree_r, vm_linux2_cpu0_memareas + 1 };
__SEC_RO tree_memarea const vm_linux2_cpu0_memtree_r_l = { NULL, NULL, vm_linux2_cpu0_memareas + 2 };
__SEC_RO tree_memarea const vm_linux2_cpu0_memtree_r = { &vm_linux2_cpu0_memtree_r_l, NULL, vm_linux2_cpu0_memareas + 3 };
__SEC_RO emulate const vm_linux2_cpu0_emulates[13] = {
  { 0xf7113000, 0x1000, EMULATE_TYPE_UART_PL011, { &vdev_linux2_uart }, 0 },
  { 0xf6801000, 0x1000, EMULATE_TYPE_IRQ_GIC_VIRTEXT, { &vdev_linux2_gic_cpu0 }, 0 },
  { 0xf8008000, 0x1000, EMULATE_TYPE_TIMER_SP804, { &vdev_linux2_sp804 }, 0 },
  { 0, 0, EMULATE_TYPE_TIMER_ARMCP14, { &vdev_linux2_armcp14_cpu0 }, 0 },
  { 0xf4410000, 0x1000, EMULATE_TYPE_MEMORY_32BIT, { &vdev_linux2_mmio_mediactrl }, 0 },
  { 0xf7020000, 0x14000, EMULATE_TYPE_MEMORY_32BIT, { &vdev_linux2_mmio1 }, 0 },
  { 0xf7800000, 0x2000, EMULATE_TYPE_MEMORY_32BIT, { &vdev_linux2_mmio_aoctrl }, 0 },
  { 0xf8011000, 0x5000, EMULATE_TYPE_MEMORY_32BIT, { &vdev_linux2_mmio3 }, 0 },
  { 0xf7111000, 0x1000, EMULATE_TYPE_MEMORY_32BIT, { &vdev_linux2_mmio_uart1 }, 0 },
  { 0xf7112000, 0x1000, EMULATE_TYPE_MEMORY_32BIT, { &vdev_linux2_mmio_uart2 }, 0 },
  { 0xf7114000, 0x1000, EMULATE_TYPE_MEMORY_32BIT, { &vdev_linux2_mmio_uart4 }, 0 },
  { 0xf7100000, 0x8000, EMULATE_TYPE_MEMORY_32BIT, { &vdev_linux2_mmio4 }, 0 },
  { 0xf8000000, 0x8000, EMULATE_TYPE_MEMORY_32BIT, { &vdev_linux2_mmio2 }, 0 },
};
__SEC_RO tree_emulate const vm_linux2_cpu0_emulatetree_l_l_l = { NULL, NULL, vm_linux2_cpu0_emulates + 4 };
__SEC_RO tree_emulate const vm_linux2_cpu0_emulatetree_l_l = { &vm_linux2_cpu0_emulatetree_l_l_l, &vm_linux2_cpu0_emulatetree_l_l_r, vm_linux2_cpu0_emulates + 1 };
__SEC_RO tree_emulate const vm_linux2_cpu0_emulatetree_l_l_r = { NULL, NULL, vm_linux2_cpu0_emulates + 5 };
__SEC_RO tree_emulate const vm_linux2_cpu0_emulatetree_l = { &vm_linux2_cpu0_emulatetree_l_l, &vm_linux2_cpu0_emulatetree_l_r, vm_linux2_cpu0_emulates + 11 };
__SEC_RO tree_emulate const vm_linux2_cpu0_emulatetree_l_r_l = { NULL, NULL, vm_linux2_cpu0_emulates + 8 };
__SEC_RO tree_emulate const vm_linux2_cpu0_emulatetree_l_r = { &vm_linux2_cpu0_emulatetree_l_r_l, NULL, vm_linux2_cpu0_emulates + 9 };
__SEC_RO tree_emulate const vm_linux2_cpu0_emulatetree = { &vm_linux2_cpu0_emulatetree_l, &vm_linux2_cpu0_emulatetree_r, vm_linux2_cpu0_emulates + 0 };
__SEC_RO tree_emulate const vm_linux2_cpu0_emulatetree_r_l_l = { NULL, NULL, vm_linux2_cpu0_emulates + 10 };
__SEC_RO tree_emulate const vm_linux2_cpu0_emulatetree_r_l = { &vm_linux2_cpu0_emulatetree_r_l_l, NULL, vm_linux2_cpu0_emulates + 6 };
__SEC_RO tree_emulate const vm_linux2_cpu0_emulatetree_r = { &vm_linux2_cpu0_emulatetree_r_l, &vm_linux2_cpu0_emulatetree_r_r, vm_linux2_cpu0_emulates + 12 };
__SEC_RO tree_emulate const vm_linux2_cpu0_emulatetree_r_r_l = { NULL, NULL, vm_linux2_cpu0_emulates + 2 };
__SEC_RO tree_emulate const vm_linux2_cpu0_emulatetree_r_r = { &vm_linux2_cpu0_emulatetree_r_r_l, NULL, vm_linux2_cpu0_emulates + 7 };
__SEC_RWS emulate_uart_pl011 vdev_linux2_uart = {};
__SEC_RW emulate_irq_gic vdev_linux2_gic_cpu0 = { 0, 0, 0, 0, {}, {}, {}, {}, &vdev_linux2_gic_dist, {}, 0 };
__SEC_RWS emulate_irq_gic_distributor vdev_linux2_gic_dist = {};
__SEC_RWS emulate_timer_sp804 vdev_linux2_sp804 = {};
__SEC_RW emulate_timer_armcp14 vdev_linux2_armcp14_cpu0 = {};
__SEC_RO emulate_memory const vdev_linux2_mmio_mediactrl = {
  EMULATE_MEMORY_FLAG_SINGLE_VALUE|EMULATE_MEMORY_FLAG_SINGLE_MEM_RMASK|EMULATE_MEMORY_FLAG_SINGLE_MEM_WMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_RMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_WMASK,
  0x0, 0xffffffff, 0x0, 0x0, 0x0,
  NULL,
  (volatile uint32_t *)0x0,
  NULL,
  NULL,
  NULL,
  NULL
};
__SEC_RO emulate_memory const vdev_linux2_mmio1 = {
  EMULATE_MEMORY_FLAG_SINGLE_VALUE|EMULATE_MEMORY_FLAG_SINGLE_MEM_RMASK|EMULATE_MEMORY_FLAG_SINGLE_MEM_WMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_RMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_WMASK,
  0x0, 0xffffffff, 0x0, 0x0, 0x0,
  NULL,
  (volatile uint32_t *)0x0,
  NULL,
  NULL,
  NULL,
  NULL
};
__SEC_RO emulate_memory const vdev_linux2_mmio_aoctrl = {
  EMULATE_MEMORY_FLAG_SINGLE_VALUE|EMULATE_MEMORY_FLAG_SINGLE_MEM_RMASK|EMULATE_MEMORY_FLAG_SINGLE_MEM_WMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_RMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_WMASK,
  0x0, 0xffffffff, 0x0, 0x0, 0x0,
  NULL,
  (volatile uint32_t *)0x0,
  NULL,
  NULL,
  NULL,
  NULL
};
__SEC_RO emulate_memory const vdev_linux2_mmio3 = {
  EMULATE_MEMORY_FLAG_SINGLE_VALUE|EMULATE_MEMORY_FLAG_SINGLE_MEM_RMASK|EMULATE_MEMORY_FLAG_SINGLE_MEM_WMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_RMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_WMASK,
  0x0, 0xffffffff, 0x0, 0x0, 0x0,
  NULL,
  (volatile uint32_t *)0x0,
  NULL,
  NULL,
  NULL,
  NULL
};
__SEC_RO emulate_memory const vdev_linux2_mmio_uart1 = {
  EMULATE_MEMORY_FLAG_SINGLE_VALUE|EMULATE_MEMORY_FLAG_SINGLE_MEM_RMASK|EMULATE_MEMORY_FLAG_SINGLE_MEM_WMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_RMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_WMASK,
  0x0, 0xffffffff, 0x0, 0x0, 0x0,
  NULL,
  (volatile uint32_t *)0x0,
  NULL,
  NULL,
  NULL,
  NULL
};
__SEC_RO emulate_memory const vdev_linux2_mmio_uart2 = {
  EMULATE_MEMORY_FLAG_SINGLE_VALUE|EMULATE_MEMORY_FLAG_SINGLE_MEM_RMASK|EMULATE_MEMORY_FLAG_SINGLE_MEM_WMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_RMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_WMASK,
  0x0, 0xffffffff, 0x0, 0x0, 0x0,
  NULL,
  (volatile uint32_t *)0x0,
  NULL,
  NULL,
  NULL,
  NULL
};
__SEC_RO emulate_memory const vdev_linux2_mmio_uart4 = {
  EMULATE_MEMORY_FLAG_SINGLE_VALUE|EMULATE_MEMORY_FLAG_SINGLE_MEM_RMASK|EMULATE_MEMORY_FLAG_SINGLE_MEM_WMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_RMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_WMASK,
  0x0, 0xffffffff, 0x0, 0x0, 0x0,
  NULL,
  (volatile uint32_t *)0x0,
  NULL,
  NULL,
  NULL,
  NULL
};
__SEC_RO emulate_memory const vdev_linux2_mmio4 = {
  EMULATE_MEMORY_FLAG_SINGLE_VALUE|EMULATE_MEMORY_FLAG_SINGLE_MEM_RMASK|EMULATE_MEMORY_FLAG_SINGLE_MEM_WMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_RMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_WMASK,
  0x0, 0xffffffff, 0x0, 0x0, 0x0,
  NULL,
  (volatile uint32_t *)0x0,
  NULL,
  NULL,
  NULL,
  NULL
};
__SEC_RO emulate_memory const vdev_linux2_mmio2 = {
  EMULATE_MEMORY_FLAG_SINGLE_VALUE|EMULATE_MEMORY_FLAG_SINGLE_MEM_RMASK|EMULATE_MEMORY_FLAG_SINGLE_MEM_WMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_RMASK|EMULATE_MEMORY_FLAG_SINGLE_HW_WMASK,
  0x0, 0xffffffff, 0x0, 0x0, 0x0,
  NULL,
  (volatile uint32_t *)0x0,
  NULL,
  NULL,
  NULL,
  NULL
};
__SEC_RO const emulate * const vm_linux2_hw_emulates[2] = { vm_linux2_cpu0_emulates + 1, vm_linux2_cpu0_emulates + 3, };

