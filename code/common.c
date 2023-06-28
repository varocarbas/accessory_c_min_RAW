#include "headers/common.h"

const size_t WRONG_SIZE = 0;

char* SEPARATOR_DEFAULT = " --- ";
char* SEPARATOR_PRINT_ARRAY_START = "{ ";
char* SEPARATOR_PRINT_ARRAY_END = " }";
char* SEPARATOR_PRINT_ARRAY_ITEMS = ", ";

void* WRONG_POINTER = ((void*)0);
void* WRONG_VALUE = ((void*)0);
char* WRONG_STRING = "";

const void* to_constant(void* input_) { return input_; }

void* get_wrong_value(const type type_)
{
	void* output = WRONG_VALUE;

	if (type_ == STRING) output = WRONG_STRING;

	return output;
}
