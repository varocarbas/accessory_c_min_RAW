#ifndef OUTPUT_H_
#define OUTPUT_H_

#include "all.h"

output* __get_new_output(void*, type);

output* __get_new_output_type(type);

output* __get_wrong_output_error(type, type_error, void*);

output* __get_wrong_output_warning(type, type_warning, void*);

output* remove_output_error_warning(output*);

output* __update_output_error_warning_error(output*, type_error, void*);

output* update_output_error_warning_warning(output*, type_warning, void*);

output* __get_wrong_output_internal(type, type_error, type_warning, boolean, void*);

output* _update_output_error_warning_internal(output*, type_error, type_warning, boolean, void*);

#endif
