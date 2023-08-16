#include "headers/misc.h"

void print(void* value_, const type type_)
{
	char* format = get_type_format(type_);

	if (string_is_ok(format) == TRUE) print_internal(value_, format, type_, TRUE);
}

void print_new_line() { print_internal("\n", get_type_format(STRING), STRING, FALSE); }

void print_internal(void* value_, char* format_, const type type_, const boolean add_new_line_)
{
	if (type_is_custom(type_) == TRUE)
	{
		char* temp = _custom_void_to_string(value_, type_);

		printf(format_, temp);

		if (custom_void_to_string_is_heap(type_) == TRUE) free_string(temp);
	}
	else if (type_ == STRING) printf(format_, void_to_string(value_));
	else if (type_ == CHAR) printf(format_, void_to_char(value_));
	else if (type_ == INT) printf(format_, void_to_int(value_));
	else if (type_ == SIZE) printf(format_, void_to_size(value_));
	else if (type_ == SHORT) printf(format_, void_to_short(value_));
	else if (type_ == LONG) printf(format_, void_to_long(value_));
	else if (type_ == DOUBLE) printf(format_, void_to_double(value_));
	else return;

	if (add_new_line_) print_new_line();
}
