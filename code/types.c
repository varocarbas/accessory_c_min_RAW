#include "headers/types.h"

boolean type_is_ok(const type input_) { return ((input_ >= TYPE_MIN && input_ <= TYPE_MAX) ? TRUE : FALSE); }

char* get_type_format(const type input_)
{
	if (input_ == STRING || input_ == BOOLEAN || input_ == TYPE) return "%s";
	else if (input_ == CHAR) return "%c";
	else if (input_ == INT) return "%d";
	else if (input_ == SIZE) return "%zu";
	else if (input_ == SHORT) return "%hd";
	else if (input_ == LONG) return "%ld";
	else if (input_ == DOUBLE) return "%f";
	else return WRONG_STRING;
}

size_t get_type_size(const type input_)
{
	size_t output = WRONG_SIZE;

	if (input_ == STRING || input_ == CHAR) output = sizeof(char);
	else if (input_ == INT || input_ == BOOLEAN || input_ == TYPE) output = sizeof(int);
	else if (input_ == SIZE) output = sizeof(size_t);
	else if (input_ == SHORT) output = sizeof(short);
	else if (input_ == LONG) output = sizeof(long);
	else if (input_ == DOUBLE) output = sizeof(double);

	return output;
}

char* type_to_string(type input_)
{
	if (input_ == TYPE) return "type";
	else if (input_ == STRING) return "string";
	else if (input_ == CHAR) return "char";
	else if (input_ == INT) return "int";
	else if (input_ == SIZE) return "size";
	else if (input_ == SHORT) return "short";
	else if (input_ == LONG) return "long";
	else if (input_ == DOUBLE) return "double";
	else if (input_ == BOOLEAN) return "boolean";
	else return WRONG_STRING;
}

