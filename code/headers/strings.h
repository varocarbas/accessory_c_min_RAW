#ifndef STRINGS_H_
#define STRINGS_H_

#include "all.h"

#include <string.h>

size_t get_string_length(char*);

boolean string_is_ok(char*);

boolean strings_are_equal(char*, char*);

char* __trim(char*);

char* __substring(char*, size_t, size_t);

char* _get_wrong_string(boolean);

char* get_wrong_string_stack();

char* __get_wrong_string_heap();

char* __initialise_string(size_t);

char* __assign_string(char*);

char* __assign_free_string(char*);

char* __assign_free_output_string(char*, char*);

char* __assign_free_both_string(char*, char*);

void print_string(char*);

char* get_string_format();

char* boolean_to_string(boolean);

size_t get_string_length_internal(const char*);

boolean string_is_ok_internal(char*);

boolean strings_are_equal_internal(char*, char*, boolean);

void trim_start_length_internal(size_t*, char*);

void _substring_internal(char*, char*, size_t, size_t, boolean);

char* add_string_termination_internal(char*, size_t);

char* __assign_free_string_internal(char*, boolean);

void print_string_internal(char*, boolean);

#endif
