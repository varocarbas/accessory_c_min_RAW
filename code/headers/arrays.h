#ifndef ARRAYS_H_
#define ARRAYS_H_

#include "all.h"

void* __initialise_array(size_t, type);

void* __assign_array(void*, size_t, type);

void* __assign_free_in_array(void*, size_t, type);

void* __assign_free_out_array(void*, void*, size_t, type);

void* __assign_free_both_array(void*, void*, size_t, type);

void free_array(void*, size_t, type);

void* _get_wrong_array(boolean);

void* get_wrong_array();

void* __get_wrong_array();

void* __get_wrong_array_free(void*, size_t, type);

void* __get_wrong_array_free_both(void*, void*, size_t, type);

boolean is_array(size_t);

boolean array_is_ok(void*, size_t, type);

boolean arrays_are_equal(void*, size_t, void*, size_t, type);

void* __shrink_array(void*, size_t, type);

void* __shrink_free_array(void*, size_t, type, size_t);

void* get_array_item(void*, size_t, type);

type* get_type_array_item(void*, size_t);

type_error* get_error_array_item(void*, size_t);

type_warning* get_warning_array_item(void*, size_t);

error_warning* get_error_warning_array_item(void*, size_t);

output* get_output_array_item(void*, size_t);

boolean* get_boolean_array_item(void*, size_t);

char* get_string_array_item(void*, size_t);

char* get_char_array_item(void*, size_t);

int* get_int_array_item(void*, size_t);

size_t* get_size_array_item(void*, size_t);

short* get_short_array_item(void*, size_t);

long* get_long_array_item(void*, size_t);

double* get_double_array_item(void*, size_t);

void* __get_array_value(void*, size_t, type);

type get_type_array_value(void*, size_t);

type_error get_error_array_value(void*, size_t);

type_warning get_warning_array_value(void*, size_t);

error_warning* __get_error_warning_array_value(void*, size_t);

output* __get_output_array_value(void*, size_t);

boolean get_boolean_array_value(void*, size_t);

char* __get_string_array_value(void*, size_t);

char get_char_array_value(void*, size_t);

int get_int_array_value(void*, size_t);

size_t get_size_array_value(void*, size_t);

short get_short_array_value(void*, size_t);

long get_long_array_value(void*, size_t);

double get_double_array_value(void*, size_t);

void* _update_array(void*, void*, size_t, type);

boolean update_array_is_heap(type);

void print_array(void*, size_t, type);

char* __array_to_string(void*, size_t, type);

void* __initialise_array_internal(size_t, type, size_t);

void* __assign_array_internal(void*, void*, size_t, type, boolean, boolean);

void* __initialise_update_2d_pointer_array_internal(void*, void*, size_t, type, size_t, action);

void* __initialise_2d_pointer_array_item_internal(void*, size_t, type, size_t);

void* __update_2d_pointer_array_item_internal(void*, void*, size_t, type);

void* __get_wrong_array_free_internal(void*, void*, size_t, type, boolean, boolean);

boolean array_is_ok_internal(void*, type);

boolean array_is_ok_min_internal(void*);

void* __shrink_array_internal(void*, size_t, type, boolean, size_t);

void* get_array_item_internal(void*, size_t, type);

void* get_default_array_item_internal(void*, size_t, type);

void* get_2d_pointer_array_item_internal(void*, size_t, type);

void* update_array_default_internal(void*, void*, size_t, type);

void* __update_2d_pointer_array_internal(void*, void*, size_t, type);

char* _print_array_to_string_internal(void*, size_t, type, boolean);

void print_array_start_end_internal(boolean);

void print_array_item_internal(size_t, size_t, void*, char*, type);

char* __array_to_string_internal(char*, void*, size_t, type, boolean);

#endif
