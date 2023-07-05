#ifndef VALUES_H_
#define VALUES_H_

#include "all.h"

void* __initialise_value(type);

void* __assign_value(void*, type);

void* __assign_free_in_value(void*, type);

void* __assign_free_out_value(void*, void*, type);

void* __assign_free_both_value(void*, void*, type);

void* __assign_wrong_value(type);

void* __assign_free_wrong_value(void*, type);

void* __assign_free_both_wrong_value(void*, void*, type);

char* _value_to_string(void*, type);

char* custom_value_to_string(void*, type);

char* __native_value_to_string(void*, type);

type pointer_to_type(void*);

type_error pointer_to_error(void*);

type_warning pointer_to_warning(void*);

error_warning* pointer_to_error_warning(void*);

output* pointer_to_output(void*);

boolean pointer_to_boolean(void*);

char* pointer_to_string(void*);

char pointer_to_char(void*);

int pointer_to_int(void*);

size_t pointer_to_size(void*);

short pointer_to_short(void*);

long pointer_to_long(void*);

double pointer_to_double(void*);

void* _get_wrong_value(type, boolean);

void* __get_wrong_value_heap(type);

void* get_wrong_value_stack(type);

#endif
