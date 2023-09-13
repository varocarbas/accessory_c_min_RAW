#include "headers/types.h"

boolean type_is_native(const type in_) { return !type_is_custom(in_); }

boolean type_is_custom(const type in_) { return (type_is_enum(in_) || type_is_struct(in_)); }

boolean type_is_enum(const type in_) { return (in_ == TYPE || in_ == ERROR || in_ == WARNING || in_ == BOOLEAN); }

boolean type_is_struct(const type in_) { return (in_ == ERROR_WARNING || in_ == OUTPUT); }

boolean type_is_pointer(const type in_) { return (in_ == STRING || type_is_struct(in_)); }

boolean type_array_is_2d_pointer(const type in_) { return type_is_pointer(in_); }

char* type_to_string(const type in_)
{
	char* out;

	if (in_ == TYPE) out = "type";
	else if (in_ == ERROR) out = "error";
	else if (in_ == WARNING) out = "warning";
	else if (in_ == ERROR_WARNING) out = "error_warning";
	else if (in_ == OUTPUT) out = "output";
	else if (in_ == BOOLEAN) out = "boolean";
	else if (in_ == STRING) out = "string";
	else if (in_ == CHAR) out = "char";
	else if (in_ == INT) out = "int";
	else if (in_ == SIZE) out = "size";
	else if (in_ == SHORT) out = "short";
	else if (in_ == LONG) out = "long";
	else if (in_ == DOUBLE) out = "double";
	else out = WRONG_STRING;

	return out;
}

output* __int_to_size(const int in_)
{
	output* out = __get_new_output_type(SIZE);

	if (in_ >= 0)
	{
		size_t temp = (size_t)in_;

		out = __update_output_variable(out, size_pointer_to_void(&temp), SIZE);
	}
	else out = __update_output_error_warning_conversion(out, int_pointer_to_void((int*)&in_), INT, SIZE);

	return out;
}

output* __size_to_int(const size_t in_)
{
	output* out = __get_new_output_type(INT);

	if (in_ <= INT_MAX)
	{
		int temp = (int)in_;

		out = __update_output_variable(out, int_pointer_to_void(&temp), INT);
	}
	else out = __update_output_error_warning_conversion(out, size_pointer_to_void((size_t*)&in_), SIZE, INT);

	return out;
}

char* get_type_format(const type in_)
{
	char* out;

	if (in_ == STRING || type_is_custom(in_)) out = "%s";
	else if (in_ == CHAR) out = "%c";
	else if (in_ == INT) out = "%d";
	else if (in_ == SIZE) out = "%zu";
	else if (in_ == SHORT) out = "%hd";
	else if (in_ == LONG) out = "%ld";
	else if (in_ == DOUBLE) out = "%f";
	else out = WRONG_STRING;

	return out;
}

size_t get_type_size(const type in_, const boolean is_2d_pointer_)
{
	size_t out;

	if (in_ == TYPE) out = sizeof(type);
	else if (in_ == ERROR) out = sizeof(type_error);
	else if (in_ == WARNING) out = sizeof(type_warning);
	else if (in_ == ERROR_WARNING) out = (is_2d_pointer_ ? sizeof(error_warning*) : sizeof(error_warning));
	else if (in_ == OUTPUT) out = (is_2d_pointer_ ? sizeof(output*) : sizeof(output));
	else if (in_ == BOOLEAN) out = sizeof(boolean);
	else if (in_ == STRING) out = (is_2d_pointer_ ? sizeof(char*) : sizeof(char));
	else if (in_ == CHAR) out = sizeof(char);
	else if (in_ == INT) out = sizeof(int);
	else if (in_ == SIZE) out = sizeof(size_t);
	else if (in_ == SHORT) out = sizeof(short);
	else if (in_ == LONG) out = sizeof(long);
	else if (in_ == DOUBLE) out = sizeof(double);
	else out = sizeof(void*);

	return out;
}
