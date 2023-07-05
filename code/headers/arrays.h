#ifndef ARRAYS_H_
#define ARRAYS_H_

#include "all.h"

boolean array_is_ok(const void*, size_t, type);

void* __initialise_array(size_t, type);

void* __assign_array(void*, size_t, type);

void* __assign_free_in_array(void*, size_t, type);

void* __assign_free_out_array(void*, void*, size_t, type);

void* __assign_free_both_array(void*, void*, size_t, type);

void* __assign_wrong_array(size_t, type);

void* __assign_free_wrong_array(void*, size_t, type);

void* __assign_free_both_wrong_array(void*, void*, size_t, type);

size_t get_initial_array_size(size_t, type, boolean);

void print_array(void*, size_t, type);

void* get_array_value(const void*, size_t, type);

void* _get_wrong_array(type, boolean);

void* __get_wrong_array_heap(type);

void* get_wrong_array_stack(type);

boolean array_is_ok_internal(const void*);

void* get_array_value_internal(const void*, size_t, type);

void print_array_start_end_internal(boolean);

void print_array_item_internal(size_t, size_t, void*, const char*, type);

#endif
