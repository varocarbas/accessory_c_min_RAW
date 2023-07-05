#ifndef STRINGS_H_
#define STRINGS_H_

#include "all.h"

size_t get_string_length(const char*);

boolean string_is_ok(const char*);

boolean strings_are_equal(const char*, const char*);

char* __trim(const char*);

char* __substring(const char*, size_t, size_t);

char* __concatenate(const char*, const char*);

char* __initialise_string(size_t);

char* __assign_string(char*);

char* __assign_free_in_string(char*);

char* __assign_free_out_string(char*, char*);

char* __assign_free_both_string(char*, char*);

char* __assign_wrong_string();

char* __assign_free_wrong_string(char*);

char* __assign_free_both_wrong_string(char*, char*);

void print_string(char*);

char* get_string_format();

char* boolean_to_string(boolean);

char* __char_to_string(char);

char* __int_to_string(int);

char* __size_to_string(size_t);

char* __short_to_string(short);

char* __long_to_string(long);

char* __double_to_string(double);

char* __normalise_string(const char*);

char* __string_to_lower(const char*);

output* __index_of_string(const char*, const char*, size_t);

char* _get_wrong_string(boolean);

void* __get_wrong_string_heap();

void* get_wrong_string_stack();

size_t get_string_length_internal(const char*, boolean);

boolean string_is_ok_internal(const char*, boolean);

boolean strings_are_equal_internal(const char*, const char*, boolean);

char* __trim_internal(const char*, size_t);

size_t* __trim_start_length_internal(const char*, size_t);

char* _substring_internal(char*, const char*, size_t, size_t, boolean);

char* substring_common_internal(char*, const char*, size_t, size_t, size_t);

char* __concatenate_internal(const char*, size_t, const char*, size_t);

char* add_string_termination_internal(char*, size_t);

void print_string_internal(char*, boolean);

char* value_to_string_custom_internal(void*, type);

char* __value_to_string_native_internal(void*, type);

char* __normalise_string_internal(const char*, size_t);

char* __string_to_lower_internal(const char*, size_t);

output* __index_of_string_internal(output*, const char*, const char*, boolean, size_t);

output* __index_of_string_common_internal(output*, const char*, const char*, boolean, size_t);

#endif
