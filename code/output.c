#include "headers/output.h"

output* __get_new_output(void* value_, const type type_, const size_t size_)
{
	output temp = { (size_ > WRONG_SIZE ? __assign_array(value_, size_, type_) : __assign_void(value_, type_)), type_, size_, TRUE, WRONG_ERROR_WARNING };

	if ((size_ == WRONG_SIZE && void_type_is_ok(value_, type_) == FALSE) || (size_ > WRONG_SIZE && array_is_ok_internal(value_) == FALSE)) temp._value = update_void_value(temp._value, value_, type_);

	output* out = __assign_void(&temp, OUTPUT);

	if (void_type_is_ok(out, OUTPUT) == TRUE && (value_ == WRONG_POINTER || type_ == WRONG_TYPE)) out = __update_output_error_warning_error(out, ERROR_WRONG_INPUTS, WRONG_POINTER);

	return out;
}

output* __get_new_output_type(const type type_) { return __get_new_output(get_wrong_void_stack(type_), type_, WRONG_SIZE); }

output* __get_new_output_array(const size_t size_) { return __get_new_output(get_wrong_array_stack(), WRONG_TYPE, size_); }

void free_output(output* in_h_)
{
	if (output_is_ok(in_h_) == TRUE)
	{
		free_output_value_internal(in_h_);

		free_output_error_warning_internal(in_h_);
	}

	free(in_h_);
}

boolean output_is_ok(output* in_) { return void_type_is_ok(in_, OUTPUT); }

boolean output_value_is_ok(output* in_) { return ((output_is_ok(in_) == TRUE && in_->_is_ok == TRUE) ? TRUE : FALSE); }

boolean output_array_value_is_ok(output* in_) { return ((output_is_ok(in_) == TRUE && in_->_size > WRONG_SIZE) ? TRUE : FALSE); }

boolean output_value_is_array(output* in_) { return output_array_value_is_ok(in_); }

type get_output_type_value(output* in_, const boolean free_in_)
{
	type out = (output_value_is_ok(in_) == TRUE ? void_to_type(in_->_value) : WRONG_TYPE);

	if (free_in_ == TRUE) free_(in_, OUTPUT);

	return out;
}

type_error get_output_error_value(output* in_, const boolean free_in_)
{
	type_error out = (output_value_is_ok(in_) == TRUE ? void_to_error(in_->_value) : WRONG_ERROR);

	if (free_in_ == TRUE) free_(in_, OUTPUT);

	return out;
}

type_warning get_output_warning_value(output* in_, const boolean free_in_)
{
	type_warning out = (output_value_is_ok(in_) == TRUE ? void_to_warning(in_->_value) : WRONG_WARNING);

	if (free_in_ == TRUE) free_(in_, OUTPUT);

	return out;
}

error_warning* get_output_error_warning_value(output* in_, const boolean free_in_)
{
	error_warning* out = (output_value_is_ok(in_) == TRUE ? void_to_error_warning(in_->_value) : WRONG_ERROR_WARNING);

	if (free_in_ == TRUE) free_(in_, OUTPUT);

	return out;
}

output* get_output_output_value(output* in_, const boolean free_in_)
{
	output* out = (output_value_is_ok(in_) == TRUE ? void_to_output(in_->_value) : WRONG_OUTPUT);

	if (free_in_ == TRUE) free_(in_, OUTPUT);

	return out;
}

boolean get_output_boolean_value(output* in_, const boolean free_in_)
{
	boolean out = (output_value_is_ok(in_) == TRUE ? void_to_boolean(in_->_value) : WRONG_BOOLEAN);

	if (free_in_ == TRUE) free_(in_, OUTPUT);

	return out;
}

char* get_output_string_value(output* in_, const boolean free_in_)
{
	char* out = (output_value_is_ok(in_) == TRUE ? void_to_string(in_->_value) : WRONG_STRING);

	if (free_in_ == TRUE) free_(in_, OUTPUT);

	return out;
}

char get_output_char_value(output* in_, const boolean free_in_)
{
	char out = (output_value_is_ok(in_) == TRUE ? void_to_char(in_->_value) : WRONG_CHAR);

	if (free_in_ == TRUE) free_(in_, OUTPUT);

	return out;
}

int get_output_int_value(output* in_, const boolean free_in_)
{
	int out = (output_value_is_ok(in_) == TRUE ? void_to_int(in_->_value) : WRONG_INT);

	if (free_in_ == TRUE) free_(in_, OUTPUT);

	return out;
}

size_t get_output_size_value(output* in_, const boolean free_in_)
{
	size_t out = (output_value_is_ok(in_) == TRUE ? void_to_size(in_->_value) : WRONG_SIZE);

	if (free_in_ == TRUE) free_(in_, OUTPUT);

	return out;
}

short get_output_short_value(output* in_, const boolean free_in_)
{
	short out = (output_value_is_ok(in_) == TRUE ? void_to_short(in_->_value) : WRONG_SHORT);

	if (free_in_ == TRUE) free_(in_, OUTPUT);

	return out;
}

long get_output_long_value(output* in_, const boolean free_in_)
{
	long out = (output_value_is_ok(in_) == TRUE ? void_to_long(in_->_value) : WRONG_LONG);

	if (free_in_ == TRUE) free_(in_, OUTPUT);

	return out;
}

double get_output_double_value(output* in_, const boolean free_in_)
{
	double out = (output_value_is_ok(in_) == TRUE ? void_to_double(in_->_value) : WRONG_DOUBLE);

	if (free_in_ == TRUE) free_(in_, OUTPUT);

	return out;
}

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

	if (output_value_is_array(in_) == TRUE) out = __output_array_value_to_string_internal(in_);
	else if (void_type_is_ok(in_, OUTPUT) == TRUE) out = _void_to_string(in_->_value, in_->_type);
	else out = _get_wrong_string((in_ == WRONG_OUTPUT || void_to_string_is_heap(in_->_type) == TRUE));

	return out;
}

char* __output_value_to_string_full(output* in_)
{
	char* out;

	char* value = _output_value_to_string(in_);

	if (string_is_ok(value) == TRUE)
	{
		char* type = type_to_string(in_->_type);

		if (output_value_is_array(in_) == TRUE)
		{
			char* items[] = { value, DEFAULT_SEPARATOR_ITEMS, type };

			out = __concatenate_strings(items, 3);
		}
		else
		{
			char* items[] = { value, " (", type, ")" };

			out = __concatenate_strings(items, 4);
		}
	}
	else out = __get_wrong_string_heap();

	if (output_value_is_array(in_) == TRUE) free_array(value, in_->_size, in_->_type);
	else if (void_to_string_is_heap(in_->_type) == TRUE) free_(value, STRING);

	return out;
}

output* __update_output_value(output* out_, void* value_, const type type_)
{
	if (void_type_is_ok(out_, OUTPUT) == FALSE) return out_;

	out_->_value = __assign_free_out_void(out_->_value, value_, type_);

	return out_;
}

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

output* __get_wrong_output_error(const type type_, const type_error error_, void* further_) { return __get_wrong_output_internal(type_, error_, WRONG_WARNING, TRUE, further_); }

output* __get_wrong_output_warning(const type type_, const type_warning warning_, void* further_) { return __get_wrong_output_internal(type_, WRONG_ERROR, warning_, FALSE, further_); }

void free_output_value_internal(output* in_)
{
	if (output_value_is_array(in_) == TRUE) free_array(in_->_value, in_->_size, in_->_type);
	else free_(in_->_value, in_->_type);
}

void free_output_error_warning_internal(output* in_) { free_error_warning(in_->_error_warning); }

char* __output_array_value_to_string_internal(output* in_)
{
	char* size = __size_to_string(in_->_size);
	char* array = __array_to_string(in_->_value, in_->_size, in_->_type);

	char* items[] = { DEFAULT_SEPARATOR_START, size, DEFAULT_SEPARATOR_ITEMS, array, DEFAULT_SEPARATOR_END };

	char* out = __concatenate_strings(items, 5);

	free_(size, STRING);
	free_(array, STRING);

	return out;
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

	free_output_error_warning_internal(out_);

	boolean is_ok = (is_error_ == FALSE);

	out_->_is_ok = is_ok;

	if (is_ok == TRUE) out_->_error_warning = assign(out_->_error_warning, WRONG_ERROR_WARNING, ERROR_WARNING, 1);
	else out_->_error_warning = __get_new_error_warning_internal(error_, warning_, is_error_, further_);

	return out_;
}
