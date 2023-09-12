#pragma once

#include <common/defines.h>
#include <aarch64/mmu.h>
#include <common/list.h>
#include <common/rc.h>

extern char end[];// start of usalbe memory

#define REVERSED_PAGES 1024 //Reversed pages

struct page{
	RefCount ref;
};

WARN_RESULT void* kalloc_4page();
void kfree_4page(void*);
WARN_RESULT void* kalloc_page();
void kfree_page(void*);

WARN_RESULT void* kalloc(isize);
void kfree(void*);

typedef struct mem_block { // (sizeof(void*) + sizeof(isize) + sizeof(ListNode)) = 32
    void* s_addr;
    isize size;
    ListNode block_node;
    char place_holder;
} mem_block;

#define get_memsize(size) ((isize)(size) - 32) //from blocksize to memsize
#define get_block_p(s_addr) (void*)((u64)(s_addr) - 32) //from s_addr to block start addr (block pointer)
#define get_s_addr(bs_addr) (void*)((u64)(bs_addr) + 32) //from block start addr to s_addr
ALWAYS_INLINE i64 PREF_INDEX(u64 pg_base){
    if((u64)(pg_base) < (PAGE_BASE(end) + PAGE_SIZE)) return -1;
    else return (i64)(P2N((u64)(pg_base) - PAGE_BASE(end) - PAGE_SIZE));
} // vpg_base to pyhsical pg_num

u64 left_page_cnt();
WARN_RESULT void* get_zero_page();
bool check_zero_page();
u32 write_page_to_disk(void* ka);
void read_page_from_disk(void* ka, u32 bno);
