#ifndef FIRST_STRUCTS_H_
#define FIRST_STRUCTS_H_

#include "_first_all.h"

typedef struct error_warning
{
	type_error _error;
	type_warning _warning;
	boolean _is_error;
	char* _message;
}
error_warning;

typedef struct output
{
	void* _value;
	type _type;
	boolean _is_ok;
	error_warning* _error_warning;
}
output;

#endif
