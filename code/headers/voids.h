#ifndef VOIDS_H_
#define VOIDS_H_

#include "all.h"

void* assign_void(void*, void*, type);

void* __initialise_void(type);

void* __assign_void(void*, type);

void* __assign_free_in_void(void*, type);

void* __assign_free_out_void(void*, void*, type);

void* __assign_free_both_void(void*, void*, type);

void* __assign_wrong_void(type);

void* __assign_free_wrong_void(void*, type);

void* __assign_free_both_wrong_void(void*, void*, type);

void* get_wrong_void(type);

void* _get_wrong_void(type, boolean);

void* get_wrong_void_stack(type);

void* __get_wrong_void_heap(type);

void* _get_wrong_void_array(type, boolean);

void* get_wrong_void_array_stack(type);

void* __get_wrong_void_array_heap(type);

boolean void_is_ok(void*);

boolean void_type_is_ok(void*, type);

char* _void_to_string(void*, type);

char* _custom_void_to_string(void*, type);

char* __native_void_to_string(void*, type);

boolean void_to_string_is_heap(type);

boolean custom_void_to_string_is_heap(type);

boolean native_void_to_string_is_heap(type);

char* __concatenate_two_voids(void*, type, void*, type);

type void_to_type(void*);

type_error void_to_error(void*);

type_warning void_to_warning(void*);

error_warning* void_to_error_warning(void*);

output* void_to_output(void*);

boolean void_to_boolean(void*);

char* void_to_string(void*);

char void_to_char(void*);

int void_to_int(void*);

size_t void_to_size(void*);

short void_to_short(void*);

long void_to_long(void*);

double void_to_double(void*);

type* void_to_type_array(void*);

type_error* void_to_error_array(void*);

type_warning* void_to_warning_array(void*);

error_warning** void_to_error_warning_array(void*);

output** void_to_output_array(void*);

boolean* void_to_boolean_array(void*);

char** void_to_string_array(void*);

char* void_to_char_array(void*);

int* void_to_int_array(void*);

size_t* void_to_size_array(void*);

short* void_to_short_array(void*);

long* void_to_long_array(void*);

double* void_to_double_array(void*);

void* get_void_array_item(void*, size_t, type);

type get_void_array_type_item(void*, size_t);

type_error get_void_array_error_item(void*, size_t);

type_warning get_void_array_warning_item(void*, size_t);

error_warning* get_void_array_error_warning_item(void*, size_t);

output* get_void_array_output_item(void*, size_t);

boolean get_void_array_boolean_item(void*, size_t);

char* get_void_array_string_item(void*, size_t);

char get_void_array_char_item(void*, size_t);

int get_void_array_int_item(void*, size_t);

size_t get_void_array_size_item(void*, size_t);

short get_void_array_short_item(void*, size_t);

long get_void_array_long_item(void*, size_t);

double get_void_array_double_item(void*, size_t);

void* update_void_value(void*, void*, type);

void* __type_to_void(type);

void* __error_to_void(type_error);

void* __warning_to_void(type_warning);

void* error_warning_to_void(error_warning*);

void* output_to_void(output*);

void* __boolean_to_void(boolean);

void* string_to_void(char*);

void* __char_to_void(char);

void* __int_to_void(int);

void* __size_to_void(size_t);

void* __short_to_void(short);

void* __long_to_void(long);

void* __double_to_void(double);

void* pointer_to_void(void*, type);

void* type_pointer_to_void(type*);

void* error_pointer_to_void(type_error*);

void* warning_pointer_to_void(type_warning*);

void* error_warning_pointer_to_void(error_warning*);

void* output_pointer_to_void(output*);

void* boolean_pointer_to_void(boolean*);

void* string_pointer_to_void(char*);

void* char_pointer_to_void(char*);

void* int_pointer_to_void(int*);

void* size_pointer_to_void(size_t*);

void* short_pointer_to_void(short*);

void* long_pointer_to_void(long*);

void* double_pointer_to_void(double*);

#endif
