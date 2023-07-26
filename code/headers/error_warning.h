#ifndef ERROR_WARNING_H_
#define ERROR_WARNING_H_

#include "all.h"

error_warning* __get_new_error_warning_error(type_error, void*);

error_warning* __get_new_error_warning_warning(type_warning, void*);

char* error_warning_to_string(error_warning*);

error_warning* __get_new_error_warning_internal(type_error, type_warning, boolean, void*);

char* __get_error_warning_message_internal(type_error, type_warning, boolean, void*);

char* __get_error_warning_message_common_internal(type_error, type_warning, boolean, void*);

char* __error_warning_to_string_full_internal(type_error, type_warning, boolean);

#endif
