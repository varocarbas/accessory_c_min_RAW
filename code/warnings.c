#include "headers/warnings.h"

char* __get_warning_message(const type_warning type_, void* further_) { return __get_error_warning_message_common_internal(WRONG_ERROR, type_, FALSE, further_); }

char* warning_to_string(const type_warning type_)
{
	char* out;

	if (type_ == WARNING_NOT_FOUND) out = "not_found";
	else out = WRONG_STRING;

	return out;
}

char* __warning_to_string_full(const type_warning type_) { return __error_warning_to_string_full_internal(WRONG_ERROR, type_, FALSE); }
