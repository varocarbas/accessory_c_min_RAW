#include "headers/output.h"

output* __get_new_output(void* value_, const size_t size_, const type type_)
{
	boolean is_array = output_value_is_array_size(size_);

	output temp = { (is_array == FALSE ? __assign_void(value_, type_) : __assign_array(value_, size_, type_)), size_, type_, TRUE, WRONG_ERROR_WARNING };

	output* out = __initialise_custom(&temp, OUTPUT);

	if (void_type_is_ok(out, OUTPUT) == TRUE && (value_ == WRONG_POINTER || type_ == WRONG_TYPE)) out = __update_output_error_warning_error(out, ERROR_WRONG_INPUTS, WRONG_POINTER);

	return out;
}

output* __get_new_output_type(const type type_) { return __get_new_output(get_wrong_void_stack(type_), WRONG_SIZE, type_); }

output* __get_new_output_array(void* value_, const size_t size_, const type type_, const boolean free_value_)
{
	output* out = __get_new_output(value_, size_, type_);

	if (free_value_) free_array(value_, size_, type_);

	return out;
}

output* __get_new_output_array_min(const size_t size_) { return __get_new_output(get_wrong_array_stack(), size_, WRONG_TYPE); }

output* __get_wrong_output() { return __get_wrong_output_error(WRONG_TYPE, WRONG_ERROR, WRONG_POINTER); }

output* __get_wrong_output_error(const type type_, const type_error error_, void* further_) { return __get_wrong_output_internal(type_, error_, WRONG_WARNING, TRUE, further_); }

output* __get_wrong_output_warning(const type type_, const type_warning warning_, void* further_) { return __get_wrong_output_internal(type_, WRONG_ERROR, warning_, FALSE, further_); }

void free_output(output* in_h_)
{
	if (output_is_ok(in_h_) == TRUE)
	{
		free_output_value_internal(in_h_);

		free_output_error_warning_internal(in_h_);
	}

	free(in_h_);
}

output* __update_output(output* out_, output* value_) { return __update_output_internal(out_, value_); }

boolean output_is_ok(output* in_) { return void_type_is_ok(in_, OUTPUT); }

boolean output_value_is_ok(output* in_) { return ((output_is_ok(in_) == TRUE && in_->_is_ok == TRUE) ? TRUE : FALSE); }

boolean output_array_value_is_ok(output* in_) { return ((output_value_is_array(in_) == TRUE && array_is_ok(in_->_value, in_->_size, in_->_type) == TRUE) ? TRUE : FALSE); }

boolean output_value_is_array(output* in_) { return ((output_is_ok(in_) == TRUE && output_value_is_array_size(in_->_size)) ? TRUE : FALSE); }

boolean output_value_is_array_size(const size_t size_) { return is_array(size_); }

type get_output_type_value(output* in_, const boolean free_in_)
{
	type out = (output_value_is_ok(in_) == TRUE ? void_to_type(in_->_value) : WRONG_TYPE);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

type_error get_output_error_value(output* in_, const boolean free_in_)
{
	type_error out = (output_value_is_ok(in_) == TRUE ? void_to_error(in_->_value) : WRONG_ERROR);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

type_warning get_output_warning_value(output* in_, const boolean free_in_)
{
	type_warning out = (output_value_is_ok(in_) == TRUE ? void_to_warning(in_->_value) : WRONG_WARNING);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

error_warning* get_output_error_warning_value(output* in_, const boolean free_in_)
{
	error_warning* out = (output_value_is_ok(in_) == TRUE ? void_to_error_warning(in_->_value) : WRONG_ERROR_WARNING);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

output* get_output_output_value(output* in_, const boolean free_in_)
{
	output* out = (output_value_is_ok(in_) == TRUE ? void_to_output(in_->_value) : WRONG_OUTPUT);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

boolean get_output_boolean_value(output* in_, const boolean free_in_)
{
	boolean out = (output_value_is_ok(in_) == TRUE ? void_to_boolean(in_->_value) : WRONG_BOOLEAN);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

char* get_output_string_value(output* in_, const boolean free_in_)
{
	char* out = (output_value_is_ok(in_) == TRUE ? void_to_string(in_->_value) : WRONG_STRING);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

char get_output_char_value(output* in_, const boolean free_in_)
{
	char out = (output_value_is_ok(in_) == TRUE ? void_to_char(in_->_value) : WRONG_CHAR);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

int get_output_int_value(output* in_, const boolean free_in_)
{
	int out = (output_value_is_ok(in_) == TRUE ? void_to_int(in_->_value) : WRONG_INT);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

size_t get_output_size_value(output* in_, const boolean free_in_)
{
	size_t out = (output_value_is_ok(in_) == TRUE ? void_to_size(in_->_value) : WRONG_SIZE);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

short get_output_short_value(output* in_, const boolean free_in_)
{
	short out = (output_value_is_ok(in_) == TRUE ? void_to_short(in_->_value) : WRONG_SHORT);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

long get_output_long_value(output* in_, const boolean free_in_)
{
	long out = (output_value_is_ok(in_) == TRUE ? void_to_long(in_->_value) : WRONG_LONG);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

double get_output_double_value(output* in_, const boolean free_in_)
{
	double out = (output_value_is_ok(in_) == TRUE ? void_to_double(in_->_value) : WRONG_DOUBLE);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

char* __output_to_string(output* in_)
{
	char* out;

	if (output_is_ok(in_) == TRUE)
	{
		if (error_warning_is_ok(in_->_error_warning) == FALSE)
		{
			char* temp = __output_value_to_string_full(in_);

			char* items[] = { DEFAULT_ENCLOSURE_EXTERNAL_START, temp, DEFAULT_ENCLOSURE_EXTERNAL_END };

			out = __concatenate_strings(items, 3);

			free_string(temp);
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
	else if (output_is_ok(in_) == TRUE) out = _void_to_string(in_->_value, in_->_type);
	else out = _get_wrong_string(void_to_string_is_heap(in_->_type));

	return out;
}

char* __output_value_to_string_full(output* in_)
{
	char* out;

	char* value = _output_value_to_string(in_);
	boolean is_array = output_value_is_array(in_);

	char* type = type_to_string(in_->_type);
	if (is_array == TRUE) type = __concatenate_two_strings(type, " array");

	char* items[] = { value, " ", DEFAULT_ENCLOSURE_INTERNAL_START, type, DEFAULT_ENCLOSURE_INTERNAL_END };
	out = __concatenate_strings(items, 5);

	if (is_array == TRUE || void_to_string_is_heap(in_->_type) == TRUE)
	{
		free_string(value);

		if (is_array == TRUE) free_string(type);
	}

	return out;
}

output* __update_output_value(output* out_, void* value_, const type type_)
{
	if (output_is_ok(out_) == FALSE) return out_;

	out_->_value = __assign_free_out_void(out_->_value, value_, type_);

	return out_;
}

output* remove_output_error_warning(output* out_) { return _update_output_error_warning_internal(out_, WRONG_ERROR, WRONG_WARNING, FALSE, WRONG_POINTER); }

output* __update_output_error_warning_error(output* out_, const type_error error_, void* further_) { return _update_output_error_warning_internal(out_, error_, WRONG_WARNING, TRUE, further_); }

output* update_output_error_warning_warning(output* out_, const type_warning warning_, void* further_) { return _update_output_error_warning_internal(out_, WRONG_ERROR, warning_, FALSE, further_); }

output* __update_output_error_warning_conversion(output* out_, void* from_, const type type_from_, const type type_to_)
{
	char* temp = _void_to_string(from_, type_from_);

	char* items[] = { type_to_string(type_from_), " ", DEFAULT_ENCLOSURE_INTERNAL_START, temp, DEFAULT_ENCLOSURE_INTERNAL_END, " can't be converted into ", type_to_string(type_to_) };

	char* temp2 = __concatenate_strings(items, 7);

	out_ = _update_output_error_warning_internal(out_, ERROR_WRONG_CONVERSION, WRONG_WARNING, TRUE, temp2);

	if (void_to_string_is_heap(type_from_) == TRUE) free_string(temp);

	free_string(temp2);

	return out_;
}

output* __initialise_output_internal(output instance_)
{
	output* out = __initialise_void(OUTPUT);

	*out = instance_;

	return out;
}

void free_output_value_internal(output* in_) { free_(in_->_value, in_->_size, in_->_type); }

void free_output_error_warning_internal(output* in_) { free_error_warning(in_->_error_warning); }

output* __assign_free_output_item_internal(output* out_, output* in_) { return __update_output_internal(out_, in_); }

output* __update_output_internal(output* out_, output* in_)
{
	if (output_is_ok(out_) == TRUE && output_is_ok(in_) == TRUE)
	{
		out_->_value = (output_value_is_array(in_) == FALSE ? __assign_void(in_->_value, in_->_type) : __assign_array(in_->_value, in_->_size, in_->_type));
	}

	return out_;
}

char* __output_array_value_to_string_internal(output* in_)
{
	char* array = __array_to_string(in_->_value, in_->_size, in_->_type);
	char* size = __size_to_string(in_->_size);

	char* temp2[] = { DEFAULT_ENCLOSURE_EXTERNAL_START, size, DEFAULT_SEPARATOR_ITEMS, array, DEFAULT_ENCLOSURE_EXTERNAL_END };

	char* out = __concatenate_strings(temp2, 5);

	free_string(array);
	free_string(size);

	return out;
}

output* __get_wrong_output_internal(const type type_, const type_error error_, const type_warning warning_, const boolean is_error_, void* further_)
{
	output* out = __get_new_output_type(type_);

	if (output_is_ok(out) == TRUE) out = _update_output_error_warning_internal(out, error_, warning_, is_error_, further_);

	return out;
}

output* _update_output_error_warning_internal(output* out_, const type_error error_, const type_warning warning_, const boolean is_error_, void* further_)
{
	if (output_is_ok(out_) == FALSE) return out_;

	free_output_error_warning_internal(out_);

	boolean is_ok = (is_error_ == FALSE);

	out_->_is_ok = is_ok;

	if (is_ok == FALSE) out_->_error_warning = __get_new_error_warning_internal(error_, warning_, is_error_, further_);

	return out_;
}
