#include "headers/error_warning.h"

error_warning* __get_new_error_warning_error(const type_error error_, void* further_) { return __get_new_error_warning_internal(error_, WRONG_WARNING, TRUE, further_); }

error_warning* __get_new_error_warning_warning(const type_warning warning_, void* further_) { return __get_new_error_warning_internal(WRONG_ERROR, warning_, FALSE, further_); }

void free_error_warning(error_warning* in_h_)
{
	if (error_warning_is_ok(in_h_) == TRUE) free(in_h_->_message);

	free(in_h_);
}

boolean error_warning_is_ok(error_warning* in_) { return void_type_is_ok(in_, ERROR_WARNING); }

char* error_warning_to_string(error_warning* in_) { return (void_type_is_ok(in_, ERROR_WARNING) == TRUE ? in_->_message : __get_wrong_string_heap()); }

error_warning* __get_new_error_warning_internal(const type_error error_, const type_warning warning_, const boolean is_error_, void* further_)
{
	error_warning temp = { error_, warning_, is_error_, __get_error_warning_message_internal(error_, warning_, is_error_, further_) };

	error_warning* out = __assign_void(&temp, ERROR_WARNING);

	return out;
}

char* __get_error_warning_message_internal(const type_error error_, const type_warning warning_, const boolean is_error_, void* further_) { return (is_error_ ? __get_error_message(error_, further_) : __get_warning_message(warning_, further_)); }

char* __get_error_warning_message_common_internal(const type_error error_, const type_warning warning_, const boolean is_error_, void* further_)
{
	if ((is_error_ == TRUE && error_ == WRONG_ERROR) || (is_error_ == FALSE && warning_ == WRONG_WARNING)) return __get_wrong_string_heap();

	char* out = (is_error_ == TRUE ? __error_to_string_full(error_) : __warning_to_string_full(warning_));

	char* further;

	if (string_is_ok(further_) == TRUE) further = void_to_string(further_);
	else further = WRONG_STRING;

	if (string_is_ok(further) == TRUE)
	{
		char* items[] = { out, further };

		out = __assign_free_both_string(out, __concatenate_strings_internal(items, 2, DEFAULT_SEPARATOR));
	}

	return out;
}

char* __error_warning_to_string_full_internal(const type_error error_, const type_warning warning_, const boolean is_error_)
{
	char* key;
	char* error_warning;

	if (is_error_ == TRUE)
	{
		key = __string_to_upper(KEY_ERROR);
		error_warning = error_to_string(error_);
	}
	else
	{
		key = __string_to_upper(KEY_WARNING);
		error_warning = warning_to_string(warning_);
	}

	char* items[2];

	items[0] = key;
	items[1] = error_warning;

	char* out = __concatenate_strings_internal(items, 2, DEFAULT_SEPARATOR);

	free_(key, STRING);

	return out;
}
