#ifndef MEMORY_H_
#define MEMORY_H_

#include "all.h"

void* __initialise(size_t, type, boolean);

void* __initialise_custom(void*, type);

void* __assign(void*, size_t, type, boolean);

void* __assign_free_in(void*, size_t, type, boolean);

void* __assign_free_out(void*, void*, size_t, type, boolean);

void* __assign_free_both(void*, void*, size_t, type, boolean);

void free_(void*, size_t, type);

void* get_wrong(type, boolean);

void* _get_wrong(type, boolean, boolean);

void* __get_wrong_heap(type, boolean);

void* __get_wrong_free(void*, size_t, type);

void* __get_wrong_free_both(void*, void*, size_t, type);

void* get_wrong_stack(type, boolean);

boolean pointer_is_ok(void*);

size_t get_memory_size(size_t, type, boolean, boolean);

void free_internal(void*, type, boolean);

void* __assign_free_internal(void*, size_t, type, boolean, boolean);

void* __assign_free_custom_internal(void*, void*, size_t, type);

void* __assign_free_custom_item_internal(void*, void*, type);

void* _assign_internal(void*, void*, size_t, type, boolean);

void* __initialise_internal(size_t);

#endif
