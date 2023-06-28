#ifndef ARRAYS_H_
#define ARRAYS_H_

#include "all.h"

boolean array_is_ok(void*);

void print_array(void*, size_t, type);

void print_array_strings(char**, size_t);

void* get_array_value(void*, size_t, type);

void* get_array_value_internal(void*, size_t, type);

void print_array_start_end_internal(boolean);

void print_array_item_internal(size_t, size_t, void*, char*, type);

#endif
