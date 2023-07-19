#include "headers/types.h"

boolean type_is_native(const type in_) { return (type_is_custom(in_) == FALSE); }

boolean type_is_custom(const type in_) { return (type_is_enum(in_) == TRUE || type_is_struct(in_) == TRUE); }

boolean type_is_enum(const type in_) { return (in_ == TYPE || in_ == ERROR || in_ == WARNING || in_ == BOOLEAN); }

boolean type_is_struct(const type in_) { return (in_ == ERROR_WARNING || in_ == OUTPUT); }

boolean type_is_pointer(const type in_) { return (in_ == STRING || type_is_struct(in_) == TRUE); }

char* get_type_format(const type in_)
{
	char* out;

	if (in_ == STRING || type_is_custom(in_) == TRUE) out = "%s";
	else if (in_ == CHAR) out = "%c";
	else if (in_ == INT) out = "%d";
	else if (in_ == SIZE) out = "%zu";
	else if (in_ == SHORT) out = "%hd";
	else if (in_ == LONG) out = "%ld";
	else if (in_ == DOUBLE) out = "%f";
	else out = WRONG_STRING;

	return out;
}

size_t get_type_size(const type in_)
{
	size_t out;

	if (in_ == TYPE) out = sizeof(type);
	else if (in_ == ERROR) out = sizeof(type_error);
	else if (in_ == WARNING) out = sizeof(type_warning);
	else if (in_ == ERROR_WARNING) out = sizeof(error_warning);
	else if (in_ == OUTPUT) out = sizeof(output);
	else if (in_ == BOOLEAN) out = sizeof(boolean);
	else if (in_ == STRING || in_ == CHAR) out = sizeof(char);
	else if (in_ == INT) out = sizeof(int);
	else if (in_ == SIZE) out = sizeof(size_t);
	else if (in_ == SHORT) out = sizeof(short);
	else if (in_ == LONG) out = sizeof(long);
	else if (in_ == DOUBLE) out = sizeof(double);
	else out = sizeof(void*);

	return out;
}
