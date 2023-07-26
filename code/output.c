#include "headers/output.h"

output* __get_new_output(void* value_, const type type_)
{
	output temp = { __assign_void(value_, type_), type_, TRUE, WRONG_ERROR_WARNING };

	if (void_type_is_ok(value_, type_) == FALSE) temp._value = update_void_value(temp._value, value_, type_);

	output* out = __assign_void(&temp, OUTPUT);

	if (void_type_is_ok(out, OUTPUT) == TRUE && (value_ == WRONG_POINTER || type_ == WRONG_TYPE)) out = __update_output_error_warning_error(out, ERROR_WRONG_INPUTS, WRONG_POINTER);

	return out;
}

output* __get_new_output_type(const type type_) { return __get_new_output(get_wrong_void_stack(type_), type_); }

char* __output_to_string(output* in_)
{
	char* out;

	if (void_type_is_ok(in_, OUTPUT) == TRUE)
	{
		if (void_type_is_ok(in_->_error_warning, ERROR_WARNING) == FALSE)
		{
			char* temp = __output_value_to_string_full(in_);

			char* items[] = { DEFAULT_SEPARATOR_START, temp, DEFAULT_SEPARATOR_END };

			out = __concatenate_strings(items, 3);

			free_(temp, STRING);
		}
		else out = __assign_string(error_warning_to_string(in_->_error_warning));
	}
	else out = __get_wrong_string_heap();

	return out;
}

char* _output_value_to_string(output* in_)
{
	char* out;

	if (void_type_is_ok(in_, OUTPUT) == TRUE) out = _void_to_string(in_->_value, in_->_type);
	else out = _get_wrong_string((in_ == WRONG_OUTPUT || void_to_string_is_heap(in_->_type) == TRUE));

	return out;
}

char* __output_value_to_string_full(output* in_)
{
	char* out;

	char* value = _output_value_to_string(in_);

	if (string_is_ok(value) == TRUE)
	{
		char* items[] = { value, " (", type_to_string(in_->_type), ")" };

		out = __concatenate_strings(items, 4);
	}
	else out = __get_wrong_string_heap();

	if (void_to_string_is_heap(in_->_type) == TRUE) free_(value, STRING);

	return out;
}

output* __update_output_value(output* out_, void* value_, const type type_)
{
	if (void_type_is_ok(out_, OUTPUT) == FALSE) return out_;

	out_->_value = __assign_free_out_void(out_->_value, value_, type_);

	return out_;
}

output* __get_wrong_output_error(const type type_, const type_error error_, void* further_) { return __get_wrong_output_internal(type_, error_, WRONG_WARNING, TRUE, further_); }

output* __get_wrong_output_warning(const type type_, const type_warning warning_, void* further_) { return __get_wrong_output_internal(type_, WRONG_ERROR, warning_, FALSE, further_); }

output* remove_output_error_warning(output* out_) { return _update_output_error_warning_internal(out_, WRONG_ERROR, WRONG_WARNING, FALSE, WRONG_POINTER); }

output* __update_output_error_warning_error(output* out_, const type_error error_, void* further_) { return _update_output_error_warning_internal(out_, error_, WRONG_WARNING, TRUE, further_); }

output* update_output_error_warning_warning(output* out_, const type_warning warning_, void* further_) { return _update_output_error_warning_internal(out_, WRONG_ERROR, warning_, FALSE, further_); }

output* __update_output_error_warning_conversion(output* out_, void* from_, const type type_from_, const type type_to_)
{
	char* temp = _void_to_string(from_, type_from_);

	char* items[] = { type_to_string(type_from_), " (", temp, ") can't be converted into ", type_to_string(type_to_) };

	char* temp2 = __concatenate_strings(items, 5);

	out_ = _update_output_error_warning_internal(out_, ERROR_WRONG_CONVERSION, WRONG_WARNING, TRUE, temp2);

	if (void_to_string_is_heap(type_from_)) free_(temp, STRING);
	free_(temp2, STRING);

	return out_;
}

output* __get_wrong_output_internal(const type type_, const type_error error_, const type_warning warning_, const boolean is_error_, void* further_)
{
	output* out = __get_new_output_type(type_);

	if (void_type_is_ok(out, OUTPUT) == TRUE) out = _update_output_error_warning_internal(out, error_, warning_, is_error_, further_);

	return out;
}

output* _update_output_error_warning_internal(output* out_, const type_error error_, const type_warning warning_, const boolean is_error_, void* further_)
{
	if (void_type_is_ok(out_, OUTPUT) == FALSE) return out_;

	free_output_error_warning(out_);

	boolean is_ok = (is_error_ == FALSE);

	out_->_is_ok = is_ok;

	if (is_ok == TRUE) out_->_error_warning = assign(out_->_error_warning, WRONG_ERROR_WARNING, ERROR_WARNING, 1);
	else out_->_error_warning = __get_new_error_warning_internal(error_, warning_, is_error_, further_);

	return out_;
}
