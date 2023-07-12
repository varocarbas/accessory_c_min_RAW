#ifndef GENERIC_H_
#define GENERIC_H_

#include "all.h"

void* _get_wrong_generic(type, boolean);

void* get_wrong_generic_stack(type);

void* __get_wrong_generic_heap(type);

void* _get_wrong_generic_array(type, boolean);

void* get_wrong_generic_array_stack(type);

void* __get_wrong_generic_array_heap(type);

type generic_to_type(void*);

type_error generic_to_error(void*);

type_warning generic_to_warning(void*);

error_warning* generic_to_error_warning(void*);

output* generic_to_output(void*);

boolean generic_to_boolean(void*);

char* generic_to_string(void*);

char generic_to_char(void*);

int generic_to_int(void*);

size_t generic_to_size(void*);

short generic_to_short(void*);

long generic_to_long(void*);

double generic_to_double(void*);

type* generic_to_type_array(void*);

type_error* generic_to_error_array(void*);

type_warning* generic_to_warning_array(void*);

error_warning** generic_to_error_warning_array(void*);

output** generic_to_output_array(void*);

boolean* generic_to_boolean_array(void*);

char** generic_to_string_array(void*);

char* generic_to_char_array(void*);

int* generic_to_int_array(void*);

size_t* generic_to_size_array(void*);

short* generic_to_short_array(void*);

long* generic_to_long_array(void*);

double* generic_to_double_array(void*);

void* get_generic_array_value(void*, size_t, type);

void* __type_to_generic(type);

void* __error_to_generic(type_error);

void* __warning_to_generic(type_warning);

void* error_warning_to_generic(error_warning*);

void* output_to_generic(output*);

void* __boolean_to_generic(boolean);

void* string_to_generic(char*);

void* __char_to_generic(char);

void* __int_to_generic(int);

void* __size_to_generic(size_t);

void* __short_to_generic(short);

void* __long_to_generic(long);

void* __double_to_generic(double);

void* pointer_to_generic(void*, type);

void* type_pointer_to_generic(type*);

void* error_pointer_to_generic(type_error*);

void* warning_pointer_to_generic(type_warning*);

void* error_warning_pointer_to_generic(error_warning*);

void* output_pointer_to_generic(output*);

void* boolean_pointer_to_generic(boolean*);

void* string_pointer_to_generic(char*);

void* char_pointer_to_generic(char*);

void* int_pointer_to_generic(int*);

void* size_pointer_to_generic(size_t*);

void* short_pointer_to_generic(short*);

void* long_pointer_to_generic(long*);

void* double_pointer_to_generic(double*);

#endif
