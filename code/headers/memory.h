#ifndef MEMORY_H_
#define MEMORY_H_

#include "all.h"

boolean pointer_is_ok(void*);

void* assign(void*, void*, type, size_t);

void free_(void*, type);

void* __initialise(size_t, type, boolean);

void* __assign(void*, size_t, type, boolean);

void* __assign_free_in(void*, size_t, type, boolean);

void* __assign_free_out(void*, void*, size_t, type, boolean);

void* __assign_free_both(void*, void*, size_t, type, boolean);

void* __assign_wrong(size_t, type, boolean);

void* __assign_free_wrong(void*, size_t, type, boolean);

void* __assign_free_both_wrong(void*, void*, size_t, type, boolean);

size_t get_memory_size(size_t, type, boolean);

void* get_wrong(type, boolean);

void* _get_wrong(type, boolean, boolean);

void* __get_wrong_heap(type, boolean);

void* get_wrong_stack(type, boolean);

void* __assign_free_internal(void*, size_t, type, boolean, boolean);

void* _assign_internal(void*, void*, type, boolean, size_t, boolean);

void* __initialise_internal(size_t);

#endif
