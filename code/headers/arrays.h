#ifndef ARRAYS_H_
#define ARRAYS_H_

#include "all.h"

void* assign_array(void*, void*, size_t, type);

void* __initialise_array(size_t, type);

void* __assign_array(void*, size_t, type);

void* __assign_free_in_array(void*, size_t, type);

void* __assign_free_out_array(void*, void*, size_t, type);

void* __assign_free_both_array(void*, void*, size_t, type);

void free_array(void*, size_t, type);

void free_2d_array(void*, size_t, type);

void* _get_wrong_array(boolean);

void* get_wrong_array_stack();

void* __get_wrong_array_heap();

void* __get_wrong_array_free(void*, size_t, type);

void* __get_wrong_array_free_both(void*, void*, size_t, type);

boolean is_array(size_t);

boolean array_is_ok(void*, size_t, type);

void* __reduce_array_size(void*, size_t, type, boolean);

void* get_1d_array_item(void*, size_t, type);

void* get_2d_array_item(void*, size_t, type);

type get_array_type_value(void*, size_t);

type_error get_array_error_value(void*, size_t);

type_warning get_array_warning_value(void*, size_t);

error_warning* get_array_error_warning_value(void*, size_t);

output* get_array_output_value(void*, size_t);

boolean get_array_boolean_value(void*, size_t);

char* get_array_string_value(void*, size_t);

char get_array_char_value(void*, size_t);

int get_array_int_value(void*, size_t);

size_t get_array_size_value(void*, size_t);

short get_array_short_value(void*, size_t);

long get_array_long_value(void*, size_t);

double get_array_double_value(void*, size_t);

void* add_to_1d_array(void*, void*, size_t, type);

void* update_1d_array(void*, void* value_, size_t, type);

void* __add_to_2d_array(void*, void* value_, size_t, type);

void* update_2d_array(void*, void* value_, size_t, type);

void print_array(void*, size_t, type);

char* __array_to_string(void*, size_t, type);

boolean array_is_ok_internal(void*);

void* __assign_array_internal(void*, void*, size_t, type, boolean, boolean);

void* __get_wrong_array_internal(void*, void*, size_t, type, boolean, boolean);

void free_array_internal(void*, size_t, type);

void* _assign_add_update_2d_array_internal(void*, void*, void*, size_t, type, action, boolean, boolean);

void* add_update_1d_array_internal(void*, void*, size_t, type, action);

void* _add_update_2d_array_internal(void*, void* value_, size_t, type, action);

char* _print_array_to_string_internal(void*, size_t, type, boolean);

void print_array_start_end_internal(boolean);

void print_array_item_internal(size_t, size_t, void*, char*, type);

char* __array_to_string_internal(char*, void*, size_t, type, boolean);

#endif
