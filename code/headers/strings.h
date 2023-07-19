#ifndef STRINGS_H_
#define STRINGS_H_

#include "all.h"

char* assign_string(char*, char*);

char* __initialise_string(size_t);

char** __initialise_string_array(size_t);

char* __assign_string(char*);

char* __assign_free_in_string(char*);

char* __assign_free_out_string(char*, char*);

char* __assign_free_both_string(char*, char*);

char* __assign_wrong_string();

char* __assign_free_wrong_string(char*);

char* __assign_free_both_wrong_string(char*, char*);

void free_string_array(char**, size_t);

char* _get_wrong_string(boolean);

char* get_wrong_string_stack();

char* __get_wrong_string_heap();

size_t get_string_length(const char*);

boolean string_is_ok(const char*);

boolean strings_are_equal(const char*, const char*);

char* __trim_string(const char*);

char* __substring(const char*, size_t, size_t);

char* __concatenate_strings(char**, size_t);

char* __concatenate_two_strings(char*, char*);

void print_string(char*);

char* get_string_format();

char* _variable_to_string(void*, type);

char* _custom_variable_to_string(void*, type);

char* __native_variable_to_string(void*, type);

boolean variable_to_string_is_heap(type);

boolean custom_variable_to_string_is_heap(type);

boolean native_variable_to_string_is_heap(type);

char* type_to_string(type);

char* error_to_string(type_error);

char* __error_to_string_full(type_error);

char* warning_to_string(type_warning);

char* __warning_to_string_full(type_warning);

char* __error_warning_to_string(const error_warning*);

char* __output_to_string(const output*);

char* _output_value_to_string(const output*);

char* __output_value_to_string_full(const output*);

char* boolean_to_string(boolean);

char* __char_to_string(char);

char* __int_to_string(int);

char* __size_to_string(size_t);

char* __short_to_string(short);

char* __long_to_string(long);

char* __double_to_string(double);

char* __normalise_string(const char*);

char* __string_to_lower(const char*);

char* __string_to_upper(const char*);

output* __index_of_string(const char*, const char*, size_t);

size_t get_string_length_internal(const char*, boolean);

boolean string_is_ok_internal(const char*, boolean);

boolean strings_are_equal_internal(const char*, const char*, boolean);

char* __trim_string_internal(const char*, size_t);

size_t* __trim_string_start_length_internal(const char*, size_t);

char* _substring_internal(char*, const char*, size_t, size_t, boolean);

char* substring_common_internal(char*, const char*, size_t, size_t, size_t);

char* __concatenate_two_strings_internal(const char*, size_t, const char*, size_t);

char* __concatenate_strings_internal(char**, size_t, const char*);

char* __concatenate_strings_internal_add(char*, char**, const char*, size_t);

char* add_string_termination_internal(char*, size_t);

void print_string_internal(char*, boolean);

char* __normalise_string_internal(const char*, size_t);

char* __string_to_lower_upper_internal(const char*, size_t, boolean);

output* __index_of_string_internal(output*, const char*, const char*, boolean, size_t);

output* __index_of_string_common_internal(output*, const char*, const char*, boolean, size_t);

#endif
