#ifndef OUTPUT_H_
#define OUTPUT_H_

#include "all.h"

output* __get_new_output(void*, size_t, type);

output* __get_new_output_type(type);

output* __get_new_output_array(void*, size_t, type, boolean);

output* __get_new_output_array_min(size_t);

output* __get_wrong_output();

output* __get_wrong_output_error(type, type_error, void*);

output* __get_wrong_output_warning(type, type_warning, void*);

void free_output(output*);

output* __update_output(output*, output*);

boolean output_is_ok(output*);

boolean output_variable_is_ok(output*);

boolean output_array_variable_is_ok(output*);

boolean output_variable_is_array(output*);

boolean output_variable_is_array_size(size_t);

boolean outputs_are_equal(output*, output*);

type get_output_type_variable(output*, boolean);

type_error get_output_error_variable(output*, boolean);

type_warning get_output_warning_variable(output*, boolean);

error_warning* get_output_error_warning_variable(output*, boolean);

output* get_output_output_variable(output*, boolean);

boolean get_output_boolean_variable(output*, boolean);

char* get_output_string_variable(output*, boolean);

char get_output_char_variable(output*, boolean);

int get_output_int_variable(output*, boolean);

size_t get_output_size_variable(output*, boolean);

short get_output_short_variable(output*, boolean);

long get_output_long_variable(output*, boolean);

double get_output_double_variable(output*, boolean);

void print_output(output*);

char* __output_to_string(output*);

char* _output_variable_to_string(output*);

char* __output_variable_to_string_full(output*);

output* __update_output_variable(output*, void*, type);

output* remove_output_error_warning(output*);

output* __update_output_error_warning_error(output*, type_error, void*);

output* update_output_error_warning_warning(output*, type_warning, void*);

output* __update_output_error_warning_conversion(output*, void*, type, type);

output* __initialise_output_internal(output);

void free_output_variable_internal(output*);

void free_output_error_warning_internal(output*);

output* __assign_output_internal(output*, output*);

boolean output_is_ok_internal(output*, boolean);

boolean output_variables_are_equal_internal(output*, output*);

char* __output_array_variable_to_string_internal(output*);

output* __get_wrong_output_internal(type, type_error, type_warning, boolean, void*);

output* _update_output_error_warning_internal(output*, type_error, type_warning, boolean, void*);

#endif
