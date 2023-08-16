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

void free_string(char*);

void free_string_array(char**, size_t);

char* _get_wrong_string(boolean);

char* get_wrong_string_stack();

char* __get_wrong_string_heap();

char* __get_wrong_string_free(char*);

char* __get_wrong_string_free_both(char*, char*);

size_t get_string_length(char*);

boolean string_is_ok(char*);

boolean strings_are_equal(char*, char*);

char* __trim_string(char*);

char* __substring(char*, size_t, size_t);

char* __concatenate_strings(char**, size_t);

char* __concatenate_two_strings(char*, char*);

char* __normalise_string(char*);

char* __string_to_lower(char*);

char* __string_to_upper(char*);

output* __index_of_string(char*, char*, size_t);

int index_of_string_int(char*, char*, size_t);

size_t get_matches_in_string(char*, char*);

output* __split_string(char*, char*);

void print_string(char*);

char* get_string_format();

char* boolean_to_string(boolean);

char* __char_to_string(char);

char* __int_to_string(int);

char* __size_to_string(size_t);

char* __short_to_string(short);

char* __long_to_string(long);

char* __double_to_string(double);

char** __add_to_string_array(char**, char*, size_t);

char** update_string_array(char**, char*, size_t);

size_t get_string_length_internal(char*, boolean);

boolean string_is_ok_internal(char*, boolean);

boolean strings_are_equal_internal(char*, char*, boolean);

char* __trim_string_internal(char*, size_t);

size_t* __trim_string_start_length_internal(char*, size_t);

char* _substring_internal(char*, char*, size_t, size_t, boolean);

char* substring_common_internal(char*, char*, size_t, size_t, size_t);

char* __concatenate_two_strings_internal(char*, size_t, char*, size_t);

char* __concatenate_strings_internal(char**, size_t, char*);

char* __concatenate_strings_add_internal(char*, char**, char*, size_t);

char* add_string_termination_internal(char*, size_t);

void print_string_internal(char*, boolean);

char* __normalise_string_internal(char*, size_t);

char* __string_to_lower_upper_internal(char*, size_t, boolean);

int index_of_string_int_internal(char*, char*, boolean, size_t);

int index_of_string_int_common_internal(char*, char*, boolean, size_t);

size_t get_matches_in_string_internal(char*, char*, boolean);

output* __split_string_internal(char*, size_t, char*, size_t, boolean);

void* __split_matches_string_internal(char*, char*, boolean, boolean);

#endif
