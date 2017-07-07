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
__SEC_RO specification_cpu const _specification_cpus[1];
__SEC_RO memarea const cpu0_memareas[38];
__SEC_RO tree_memarea const cpu0_memtree_l_l_l_l;
__SEC_RO tree_memarea const cpu0_memtree_l_l_l;
__SEC_RO tree_memarea const cpu0_memtree_l_l_l_r;
__SEC_RO tree_memarea const cpu0_memtree_l_l;
__SEC_RO tree_memarea const cpu0_memtree_l_l_r_l;
__SEC_RO tree_memarea const cpu0_memtree_l_l_r;
__SEC_RO tree_memarea const cpu0_memtree_l;
__SEC_RO tree_memarea const cpu0_memtree_l_r_l_l;
__SEC_RO tree_memarea const cpu0_memtree_l_r_l;
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
__SEC_RO vm_cpu * const cpu0_vm_cpus[1];
__SEC_RW uintptr_t __placeholder_rw;
__SEC_RWS uintptr_t __placeholder_rws;
__SEC_RO vm const vm_lwip1;
__SEC_RW vm_cpu vm_lwip1_cpus[1];
__SEC_RO vm_copyin const vm_lwip1_copyins[1];
__SEC_RO capability const vm_lwip1_capabilities[0];
__SEC_RW scheduler_entity vm_lwip1_cpu0_scheds[1];
__SEC_RO memarea const vm_lwip1_cpu0_memareas[3];
__SEC_RO tree_memarea const vm_lwip1_cpu0_memtree_l;
__SEC_RO tree_memarea const vm_lwip1_cpu0_memtree;
__SEC_RO tree_memarea const vm_lwip1_cpu0_memtree_r;
__SEC_RO emulate const vm_lwip1_cpu0_emulates[6];
__SEC_RO tree_emulate const vm_lwip1_cpu0_emulatetree_l_l;
__SEC_RO tree_emulate const vm_lwip1_cpu0_emulatetree_l;
__SEC_RO tree_emulate const vm_lwip1_cpu0_emulatetree;
__SEC_RO tree_emulate const vm_lwip1_cpu0_emulatetree_r;
__SEC_RWS emulate_uart_pl011 vdev_lwip1_uart;
__SEC_RW emulate_vtlb vdev_lwip1_dummy_vtlb_cpu0;
__SEC_RW emulate_vtlb_instance vdev_lwip1_dummy_vtlb_cpu0_instances[8];
__SEC_RO emulate_vtlb_pool const vdev_lwip1_dummy_vtlb_cpu0_levelpools[4];
__SEC_RW uint32_t vdev_lwip1_dummy_vtlb_cpu0_levelpool0_bitmap[512];
__SEC_RW uint32_t vdev_lwip1_dummy_vtlb_cpu0_levelpool1_bitmap[2];
__SEC_RW uint32_t vdev_lwip1_dummy_vtlb_cpu0_levelpool2_bitmap[2];
__SEC_RW uint32_t vdev_lwip1_dummy_vtlb_cpu0_levelpool3_bitmap[2];
__SEC_RWS emulate_timer_sp804 vdev_lwip1_sp804;
__SEC_RW emulate_timer_armcp14 vdev_lwip1_armcp14_cpu0;
__SEC_RW emulate_irq_gic vdev_lwip1_gic_cpu0;
__SEC_RWS emulate_irq_gic_distributor vdev_lwip1_gic_dist;
__SEC_RO const emulate * const vm_lwip1_hw_emulates[1];


__SEC_ROH specification const _specification = {
  "PHIDSPEC", 0x0, 0x0, 0x0, 1, _specification_cpus, _specification_irq_owners, &_specification_arch, "2017/07/03 14:31:34"
};
__SEC_RO const vm * const _specification_irq_owners[IRQID_MAXIMUM] = {
};
__SEC_RO specification_arch const _specification_arch = {};
__SEC_RO specification_cpu const _specification_cpus[1] = {
  { 0x0, 38, cpu0_memareas, &cpu0_memtree, 1, cpu0_vm_cpus, {} },
};
__SEC_RO memarea const cpu0_memareas[38] = {
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
  { 0x0, 0x0, 0x1000000, MEMAREA_FLAG_R|MEMAREA_FLAG_W, NULL },
  { 0x0, 0x0, 0x1000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x40000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x40000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x40000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
  { 0x0, 0x0, 0x40000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_G, NULL },
};
__SEC_RO tree_memarea const cpu0_memtree_l_l_l_l = { NULL, NULL, cpu0_memareas + 16 };
__SEC_RO tree_memarea const cpu0_memtree_l_l_l = { &cpu0_memtree_l_l_l_l, &cpu0_memtree_l_l_l_r, cpu0_memareas + 17 };
__SEC_RO tree_memarea const cpu0_memtree_l_l_l_r = { NULL, NULL, cpu0_memareas + 25 };
__SEC_RO tree_memarea const cpu0_memtree_l_l = { &cpu0_memtree_l_l_l, &cpu0_memtree_l_l_r, cpu0_memareas + 26 };
__SEC_RO tree_memarea const cpu0_memtree_l_l_r_l = { NULL, NULL, cpu0_memareas + 27 };
__SEC_RO tree_memarea const cpu0_memtree_l_l_r = { &cpu0_memtree_l_l_r_l, NULL, cpu0_memareas + 31 };
__SEC_RO tree_memarea const cpu0_memtree_l = { &cpu0_memtree_l_l, &cpu0_memtree_l_r, cpu0_memareas + 0 };
__SEC_RO tree_memarea const cpu0_memtree_l_r_l_l = { NULL, NULL, cpu0_memareas + 1 };
__SEC_RO tree_memarea const cpu0_memtree_l_r_l = { &cpu0_memtree_l_r_l_l, NULL, cpu0_memareas + 3 };
__SEC_RO tree_memarea const cpu0_memtree_l_r = { &cpu0_memtree_l_r_l, &cpu0_memtree_l_r_r, cpu0_memareas + 4 };
__SEC_RO tree_memarea const cpu0_memtree_l_r_r_l = { NULL, NULL, cpu0_memareas + 2 };
__SEC_RO tree_memarea const cpu0_memtree_l_r_r = { &cpu0_memtree_l_r_r_l, NULL, cpu0_memareas + 8 };
__SEC_RO tree_memarea const cpu0_memtree = { &cpu0_memtree_l, &cpu0_memtree_r, cpu0_memareas + 9 };
__SEC_RO tree_memarea const cpu0_memtree_r_l_l_l = { NULL, NULL, cpu0_memareas + 10 };
__SEC_RO tree_memarea const cpu0_memtree_r_l_l = { &cpu0_memtree_r_l_l_l, &cpu0_memtree_r_l_l_r, cpu0_memareas + 11 };
__SEC_RO tree_memarea const cpu0_memtree_r_l_l_r = { NULL, NULL, cpu0_memareas + 6 };
__SEC_RO tree_memarea const cpu0_memtree_r_l = { &cpu0_memtree_r_l_l, &cpu0_memtree_r_l_r, cpu0_memareas + 7 };
__SEC_RO tree_memarea const cpu0_memtree_r_l_r_l = { NULL, NULL, cpu0_memareas + 13 };
__SEC_RO tree_memarea const cpu0_memtree_r_l_r = { &cpu0_memtree_r_l_r_l, NULL, cpu0_memareas + 12 };
__SEC_RO tree_memarea const cpu0_memtree_r = { &cpu0_memtree_r_l, &cpu0_memtree_r_r, cpu0_memareas + 32 };
__SEC_RO tree_memarea const cpu0_memtree_r_r_l_l = { NULL, NULL, cpu0_memareas + 33 };
__SEC_RO tree_memarea const cpu0_memtree_r_r_l = { &cpu0_memtree_r_r_l_l, NULL, cpu0_memareas + 34 };
__SEC_RO tree_memarea const cpu0_memtree_r_r = { &cpu0_memtree_r_r_l, &cpu0_memtree_r_r_r, cpu0_memareas + 35 };
__SEC_RO tree_memarea const cpu0_memtree_r_r_r_l = { NULL, NULL, cpu0_memareas + 36 };
__SEC_RO tree_memarea const cpu0_memtree_r_r_r = { &cpu0_memtree_r_r_r_l, NULL, cpu0_memareas + 37 };
__SEC_RO vm_cpu * const cpu0_vm_cpus[1] = {
  vm_lwip1_cpus + 0,
};
__SEC_RW uintptr_t __placeholder_rw = 0xbeef;
__SEC_RWS uintptr_t __placeholder_rws = 0xf4eebeef;
__SEC_RO vm const vm_lwip1 = {
  1, vm_lwip1_cpus,
  0, vm_lwip1_capabilities,
  1, vm_lwip1_copyins,
  0x40010000
};
__SEC_RW vm_cpu vm_lwip1_cpus[1] = {
  { &vm_lwip1, (vm_cpu_state *)0x0, 0,
    0x0, 1,
    3, vm_lwip1_cpu0_memareas, &vm_lwip1_cpu0_memtree,
    6, vm_lwip1_cpu0_emulates, &vm_lwip1_cpu0_emulatetree,
    1, vm_lwip1_hw_emulates,
    vm_lwip1_cpu0_emulates + 1,
    vm_lwip1_cpu0_emulates + 4,
    vm_lwip1_cpu0_emulates + 0,
    1, vm_lwip1_cpu0_scheds },
};
__SEC_RO vm_copyin const vm_lwip1_copyins[1] = {
  { 0x0, 0x0, 0x0 },
};
__SEC_RO capability const vm_lwip1_capabilities[0] = {
};
__SEC_RW scheduler_entity vm_lwip1_cpu0_scheds[1] = {
  { vm_lwip1_cpus + 0, SCHEDULER_CLASS_FAIR_SHARE, 0, 0, 100, SCHEDULER_STATE_READY, NULL }
};
__SEC_RO memarea const vm_lwip1_cpu0_memareas[3] = {
  { 0x0, 0x40000000, 0x1000000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_X, cpu0_memareas + 32 },
  { 0x0, 0xfee00000, 0x100000, MEMAREA_FLAG_R|MEMAREA_FLAG_S, NULL },
  { 0x0, 0xfef00000, 0x100000, MEMAREA_FLAG_R|MEMAREA_FLAG_W|MEMAREA_FLAG_S, NULL },
};
__SEC_RO tree_memarea const vm_lwip1_cpu0_memtree_l = { NULL, NULL, vm_lwip1_cpu0_memareas + 0 };
__SEC_RO tree_memarea const vm_lwip1_cpu0_memtree = { &vm_lwip1_cpu0_memtree_l, &vm_lwip1_cpu0_memtree_r, vm_lwip1_cpu0_memareas + 1 };
__SEC_RO tree_memarea const vm_lwip1_cpu0_memtree_r = { NULL, NULL, vm_lwip1_cpu0_memareas + 2 };
__SEC_RO emulate const vm_lwip1_cpu0_emulates[6] = {
  { 0xf7113000, 0x1000, EMULATE_TYPE_UART_PL011, { &vdev_lwip1_uart }, 0 },
  { 0, 0, EMULATE_TYPE_VTLB, { &vdev_lwip1_dummy_vtlb_cpu0 }, 0 },
  { 0xf8008000, 0x1000, EMULATE_TYPE_TIMER_SP804, { &vdev_lwip1_sp804 }, 0 },
  { 0, 0, EMULATE_TYPE_TIMER_ARMCP14, { &vdev_lwip1_armcp14_cpu0 }, 0 },
  { 0xfedc1000, 0x1000, EMULATE_TYPE_IRQ_GIC, { &vdev_lwip1_gic_cpu0 }, 0 },
  { 0xfedc2000, 0x1000, EMULATE_TYPE_IRQ_GIC, { &vdev_lwip1_gic_cpu0 }, 1 },
};
__SEC_RO tree_emulate const vm_lwip1_cpu0_emulatetree_l_l = { NULL, NULL, vm_lwip1_cpu0_emulates + 0 };
__SEC_RO tree_emulate const vm_lwip1_cpu0_emulatetree_l = { &vm_lwip1_cpu0_emulatetree_l_l, NULL, vm_lwip1_cpu0_emulates + 2 };
__SEC_RO tree_emulate const vm_lwip1_cpu0_emulatetree = { &vm_lwip1_cpu0_emulatetree_l, &vm_lwip1_cpu0_emulatetree_r, vm_lwip1_cpu0_emulates + 4 };
__SEC_RO tree_emulate const vm_lwip1_cpu0_emulatetree_r = { NULL, NULL, vm_lwip1_cpu0_emulates + 5 };
__SEC_RWS emulate_uart_pl011 vdev_lwip1_uart = {};
__SEC_RW emulate_vtlb vdev_lwip1_dummy_vtlb_cpu0 = {
  VTLB_PAGING_FORMAT_ARM64_G4IO40, 0,
  8, vdev_lwip1_dummy_vtlb_cpu0_instances,
  4, vdev_lwip1_dummy_vtlb_cpu0_levelpools, VTLB_NO_ACTIVE_INSTANCE
};
__SEC_RW emulate_vtlb_instance vdev_lwip1_dummy_vtlb_cpu0_instances[8] = {};
__SEC_RO emulate_vtlb_pool const vdev_lwip1_dummy_vtlb_cpu0_levelpools[4] = {
  { 4, 3, 0x4000, vdev_lwip1_dummy_vtlb_cpu0_levelpool0_bitmap,
    39, 0x0, 0x0 },
  { 12, 3, 0x40, vdev_lwip1_dummy_vtlb_cpu0_levelpool1_bitmap,
    30, 0x0, 0x0 },
  { 12, 3, 0x40, vdev_lwip1_dummy_vtlb_cpu0_levelpool2_bitmap,
    21, 0x0, 0x0 },
  { 12, 3, 0x40, vdev_lwip1_dummy_vtlb_cpu0_levelpool3_bitmap,
    12, 0x0, 0x0 },
};
__SEC_RW uint32_t vdev_lwip1_dummy_vtlb_cpu0_levelpool0_bitmap[512] = {};
__SEC_RW uint32_t vdev_lwip1_dummy_vtlb_cpu0_levelpool1_bitmap[2] = {};
__SEC_RW uint32_t vdev_lwip1_dummy_vtlb_cpu0_levelpool2_bitmap[2] = {};
__SEC_RW uint32_t vdev_lwip1_dummy_vtlb_cpu0_levelpool3_bitmap[2] = {};
__SEC_RWS emulate_timer_sp804 vdev_lwip1_sp804 = {};
__SEC_RW emulate_timer_armcp14 vdev_lwip1_armcp14_cpu0 = {};
__SEC_RW emulate_irq_gic vdev_lwip1_gic_cpu0 = { 0, 0, 0, 0, {}, {}, {}, {}, &vdev_lwip1_gic_dist, {}, 0 };
__SEC_RWS emulate_irq_gic_distributor vdev_lwip1_gic_dist = {};
__SEC_RO const emulate * const vm_lwip1_hw_emulates[1] = { vm_lwip1_cpu0_emulates + 3, };

