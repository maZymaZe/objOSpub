#pragma once

#include <aarch64/mmu.h>
#include <common/list.h>

struct pgdir
{
    PTEntriesPtr pt;
    SpinLock lock;
    ListNode section_head;
    bool online;
    u64 heap_begin;// only used in sbrk(when exec, used to mark the begin of heap section)
};

void init_pgdir(struct pgdir* pgdir);
void move_pgdir(struct pgdir* from_pgdir, struct pgdir* to_pgdir);
WARN_RESULT PTEntriesPtr get_pte(struct pgdir* pgdir, u64 va, bool alloc);
void vmmap(struct pgdir* pd, u64 va, void* ka, u64 flags);
void free_pgdir(struct pgdir* pgdir);
void attach_pgdir(struct pgdir* pgdir);
int copyout(struct pgdir* pd, void* va, void *p, usize len);
int cow_copyout(struct pgdir* pd, void* va, void *p, usize len);
