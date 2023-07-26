#include "headers/errors.h"

char* __get_error_message(const type_error type_, void* further_) { return __get_error_warning_message_common_internal(type_, WRONG_WARNING, TRUE, further_); }

char* error_to_string(const type_error type_)
{
	char* out;

	if (type_ == ERROR_WRONG_INPUTS) out = "WRONG_INPUTS";
	else if (type_ == ERROR_WRONG_CONVERSION) out = "WRONG_CONVERSION";
	else out = WRONG_STRING;

	return out;
}

char* __error_to_string_full(const type_error type_) { return __error_warning_to_string_full_internal(type_, WRONG_WARNING, TRUE); }
