#include "headers/arrays.h"

boolean array_is_ok(void* input_) { return (input_ != WRONG_POINTER); }

void print_array(void* input_, const size_t size_, const type type_)
{
	char* format = get_type_format(type_);
	if (input_ == WRONG_POINTER || size_ == WRONG_SIZE || string_is_ok(format) == FALSE) return;

	print_array_start_end_internal(TRUE);

	const size_t max_i = size_ - 1;

	for (size_t i = 0; i <= max_i; i++) { print_array_item_internal(i, max_i, get_array_value_internal(input_, i, type_), format, type_); }

	print_array_start_end_internal(FALSE);
}

void* get_array_value(void* array_, const size_t i_, const type type_) { return ((array_is_ok(array_) && type_is_ok(type_)) ? get_array_value_internal(array_, i_, type_) : WRONG_VALUE); }

void* get_array_value_internal(void* array_, const size_t i_, const type type_)
{
	void* output = WRONG_VALUE;

	if (type_ == STRING) output = (((char**)array_)[i_]);
	else if (type_ == CHAR) output = &(((char*)array_)[i_]);
	else if (type_ == INT) output = &(((int*)array_)[i_]);
	else if (type_ == SIZE) output = &(((size_t*)array_)[i_]);
	else if (type_ == SHORT) output = &(((short*)array_)[i_]);
	else if (type_ == LONG) output = &(((long*)array_)[i_]);
	else if (type_ == DOUBLE) output = &(((double*)array_)[i_]);
	else if (type_ == BOOLEAN) output = &(((boolean*)array_)[i_]);

	return output;
}

void print_array_start_end_internal(boolean is_start_)
{
	print_string_internal((is_start_ == TRUE ? SEPARATOR_PRINT_ARRAY_START : SEPARATOR_PRINT_ARRAY_END), FALSE);

	if (is_start_ == FALSE) print_new_line();
}

void print_array_item_internal(size_t i, size_t max_i, void* value_, char* format_, const type type_)
{
	print_internal(value_, format_, type_, FALSE);

	if (i < max_i) print_string_internal(SEPARATOR_PRINT_ARRAY_ITEMS, FALSE);
}
