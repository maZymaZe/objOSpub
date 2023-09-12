#pragma once

#define KERNEL_BASE 0xffff000000000000
#define MMIO_BASE   (KERNEL_BASE + 0x3F000000)
#define LOCAL_BASE  (KERNEL_BASE + 0x40000000)