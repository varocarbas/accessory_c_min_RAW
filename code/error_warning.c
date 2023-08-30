#include "headers/error_warning.h"

error_warning* __get_new_error_warning_error(const type_error error_, void* further_) { return __get_new_error_warning_internal(error_, WRONG_WARNING, TRUE, further_); }

error_warning* __get_new_error_warning_warning(const type_warning warning_, void* further_) { return __get_new_error_warning_internal(WRONG_ERROR, warning_, FALSE, further_); }

error_warning* __get_wrong_error_warning() { return __get_new_error_warning_internal(WRONG_ERROR, WRONG_WARNING, FALSE, WRONG_POINTER); }

void free_error_warning(error_warning* in_h_)
{
	if (error_warning_is_ok_internal(in_h_, FALSE) == TRUE) free_string(in_h_->_message);

	free(in_h_);
}

error_warning* __update_error_warning(error_warning* out_, error_warning* value_)
{
	if (error_warning_is_ok_internal(out_, FALSE) == TRUE && error_warning_is_ok_internal(value_, FALSE) == TRUE)
	{
		*out_ = *value_;

		out_ = __assign_error_warning_internal(out_, value_);
	}

	return out_;
}

boolean error_warning_is_ok(error_warning* in_) { return error_warning_is_ok_internal(in_, DEFAULT_ERROR_WARNING_OK_PROPERTIES); }

boolean error_warnings_are_equal(error_warning* in1_, error_warning* in2_)
{
	boolean out = FALSE;

	boolean is_ok1 = error_warning_is_ok_internal(in1_, TRUE);
	boolean is_ok2 = error_warning_is_ok_internal(in2_, TRUE);

	if (is_ok1 == FALSE || is_ok2 == FALSE) out = (is_ok1 == is_ok2 ? TRUE : FALSE);
	else if (in1_->_is_error == in2_->_is_error)
	{
		out =
		(
			strings_are_equal(in1_->_message, in2_->_message) &&
			(
				(in1_->_is_error == TRUE && in1_->_error == in2_->_error) ||
				(in1_->_is_error == FALSE && in1_->_warning == in2_->_warning)
			)
		);
	}

	return out;
}

char* __error_warning_to_string(error_warning* in_) { return (void_type_is_ok(in_, ERROR_WARNING) == TRUE ? __assign_string(in_->_message) : __get_wrong_string_heap()); }

error_warning* __get_new_error_warning_internal(const type_error error_, const type_warning warning_, const boolean is_error_, void* further_)
{
	error_warning temp = { error_, warning_, is_error_, __get_error_warning_message_internal(error_, warning_, is_error_, further_) };

	return __initialise_custom(&temp, ERROR_WARNING);
}

error_warning* __initialise_error_warning_internal(error_warning instance_)
{
	error_warning* out = __initialise_void(ERROR_WARNING);

	*out = instance_;

	return out;
}

error_warning* __assign_error_warning_internal(error_warning* out_, error_warning* in_)
{
	if (error_warning_is_ok_internal(out_, FALSE) == TRUE && error_warning_is_ok_internal(in_, FALSE) == TRUE) out_->_message = __assign_string(in_->_message);

	return out_;
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

boolean error_warning_is_ok_internal(error_warning* in_, const boolean check_properties_)
{
	boolean out = void_type_is_ok(in_, ERROR_WARNING);

	if (out == TRUE && check_properties_ == TRUE)
	{
		if ((in_->_is_error == TRUE && in_->_error == WRONG_ERROR) || (in_->_is_error == FALSE && in_->_warning == WRONG_WARNING)) out = FALSE;
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

	free_string(key);

	return out;
}
