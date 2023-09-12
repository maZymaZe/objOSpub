#pragma once

#include "common/spinlock.h"
#include <kernel/proc.h>
#include <kernel/schinfo.h>
#include <common/list.h>

struct container
{
    struct container* parent;
    struct proc* rootproc;

    struct schinfo schinfo;
    struct schqueue schqueue;

    // TODO: namespace (local pid?)
    int pid_seed;
    SpinLock pid_lock;
    QueueNode* pid_head;
};

struct container* create_container(void (*root_entry)(), u64 arg);
void set_container_to_this(struct proc*);
