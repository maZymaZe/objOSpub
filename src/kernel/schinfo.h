#pragma once

#include "common/rbtree.h"
#include <common/list.h>
struct proc; // dont include proc.h here

enum schflag {GROUP, PROC};

// embedded data for cpus
struct sched
{
    // TODO: customize your sched info
    struct proc* thisproc;
    struct proc* idle;
};

// embeded data for procs
struct schinfo
{
    // TODO: customize your sched info
    struct rb_node_ node;
    // ListNode list_node;
    enum schflag flag;
    u64 vruntime;
    u64 slice;
};

// embedded data for containers
struct schqueue
{
    // TODO: customize your sched queue
    // ListNode run_list_head;//run_list is fifo
    // ListNode* run_list_last_node;
    struct rb_root_ root;
    int size;
};
