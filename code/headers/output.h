#ifndef OUTPUT_H_
#define OUTPUT_H_

#include "all.h"

output* __get_new_output(void*, type, size_t);

output* __get_new_output_type(type);

output* __get_new_output_array(size_t);

void free_output(output*);

boolean output_is_ok(output*);

boolean output_value_is_ok(output*);

boolean output_array_value_is_ok(output*);

boolean output_value_is_array(output*);

type get_output_type_value(output*, boolean);

type_error get_output_error_value(output*, boolean);

type_warning get_output_warning_value(output*, boolean);

error_warning* get_output_error_warning_value(output*, boolean);

output* get_output_output_value(output*, boolean);

boolean get_output_boolean_value(output*, boolean);

char* get_output_string_value(output*, boolean);

char get_output_char_value(output*, boolean);

int get_output_int_value(output*, boolean);

size_t get_output_size_value(output*, boolean);

short get_output_short_value(output*, boolean);

long get_output_long_value(output*, boolean);

double get_output_double_value(output*, boolean);

char* __output_to_string(output*);

char* _output_value_to_string(output*);

char* __output_value_to_string_full(output*);

output* __update_output_value(output*, void*, type);

output* remove_output_error_warning(output*);

output* __update_output_error_warning_error(output*, type_error, void*);

output* update_output_error_warning_warning(output*, type_warning, void*);

output* __update_output_error_warning_conversion(output*, void*, type, type);

output* __get_wrong_output_error(type, type_error, void*);

output* __get_wrong_output_warning(type, type_warning, void*);

void free_output_value_internal(output*);

void free_output_error_warning_internal(output*);

char* __output_array_value_to_string_internal(output*);

output* __get_wrong_output_internal(type, type_error, type_warning, boolean, void*);

output* _update_output_error_warning_internal(output*, type_error, type_warning, boolean, void*);

#endif
