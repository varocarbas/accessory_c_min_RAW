#include "headers/misc.h"

void print(void* value_, const type type_)
{
	char* format = get_type_format(type_);

	if (string_is_ok(format) == TRUE) print_internal(value_, format, type_, TRUE);
}

void print_new_line() { print_internal("\n", get_type_format(STRING), STRING, FALSE); }

void print_internal(void* value_, char* format_, const type type_, const boolean add_new_line_)
{
	if (type_ == TYPE) printf(format_, type_to_string((type)value_));
	else if (type_ == STRING) printf(format_, (char*)value_);
	else if (type_ == CHAR) printf(format_, *((char*)value_));
	else if (type_ == INT) printf(format_, *((int*)value_));
	else if (type_ == SIZE) printf(format_, *((size_t*)value_));
	else if (type_ == SHORT) printf(format_, *((short*)value_));
	else if (type_ == LONG) printf(format_, *((long*)value_));
	else if (type_ == DOUBLE) printf(format_, *((double*)value_));
	else if (type_ == BOOLEAN) printf(format_, boolean_to_string((boolean)value_));
	else return;

	if (add_new_line_) print_new_line();
}
