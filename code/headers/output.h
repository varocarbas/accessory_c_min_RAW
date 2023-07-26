#ifndef OUTPUT_H_
#define OUTPUT_H_

#include "all.h"

output* __get_new_output(void*, type);

output* __get_new_output_type(type);

char* __output_to_string(output*);

char* _output_value_to_string(output*);

char* __output_value_to_string_full(output*);

output* __update_output_value(output*, void*, type);

output* __get_wrong_output_error(type, type_error, void*);

output* __get_wrong_output_warning(type, type_warning, void*);

output* remove_output_error_warning(output*);

output* __update_output_error_warning_error(output*, type_error, void*);

output* update_output_error_warning_warning(output*, type_warning, void*);

output* __update_output_error_warning_conversion(output*, void*, type, type);

output* __get_wrong_output_internal(type, type_error, type_warning, boolean, void*);

output* _update_output_error_warning_internal(output*, type_error, type_warning, boolean, void*);

#endif
