#ifndef MEMORY_H_
#define MEMORY_H_

#include "all.h"

void* __malloc(size_t, type);

size_t get_heap_stack_size(size_t, type, boolean);

#endif
