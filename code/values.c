#include "headers/values.h"

void* __initialise_value(const type type_) { return __initialise(1, type_, FALSE); }

void* __assign_value(void* input_, const type type_) { return (type_ != WRONG_TYPE ? __assign(input_, 1, type_, FALSE) : __get_wrong_value_heap(type_)); }

void* __assign_free_in_value(void* input_h_, const type type_) { return (type_ != WRONG_TYPE ? __assign_free_in(input_h_, 1, type_, FALSE) : __get_wrong_value_heap(type_)); }

void* __assign_free_out_value(void* output_h_, void* input_, const type type_) { return (type_ != WRONG_TYPE ? __assign_free_out(output_h_, input_, 1, type_, FALSE) : __get_wrong_value_heap(type_)); }

void* __assign_free_both_value(void* output_h_, void* input_h_, const type type_) { return (type_ != WRONG_TYPE ? __assign_free_both(output_h_, input_h_, 1, type_, FALSE) : __get_wrong_value_heap(type_)); }

void* __assign_wrong_value(const type type_) { return __assign_wrong(0, type_, FALSE); }

void* __assign_free_wrong_value(void* input_output_h_, const type type_) { return __assign_free_wrong(input_output_h_, 0, type_, FALSE); }

void* __assign_free_both_wrong_value(void* output_h_, void* input_h_, const type type_) { return __assign_free_both_wrong(output_h_, input_h_, 0, type_, FALSE); }

char* _value_to_string(void* value_, const type type_) { return (type_is_custom(type_) == TRUE ? custom_value_to_string(value_, type_) : __native_value_to_string(value_, type_)); }

char* custom_value_to_string(void* value_, const type type_)
{
	if (type_ == TYPE) return type_to_string(pointer_to_type(value_));
	else if (type_ == ERROR) return get_error_message(pointer_to_error(value_), WRONG_POINTER);
	else if (type_ == WARNING) return get_warning_message(pointer_to_warning(value_), WRONG_POINTER);
	else if (type_ == ERROR_WARNING) return error_warning_to_string(pointer_to_error_warning(value_));
	else if (type_ == OUTPUT) return output_to_string(pointer_to_output(value_));
	else if (type_ == BOOLEAN) return boolean_to_string(pointer_to_boolean(value_));
	else return WRONG_STRING;
}

char* __native_value_to_string(void* value_, const type type_)
{
	if (type_ == STRING) return __assign_string(pointer_to_string(value_));
	else if (type_ == CHAR) return __char_to_string(pointer_to_char(value_));
	else if (type_ == INT) return __int_to_string(pointer_to_int(value_));
	else if (type_ == SIZE) return __size_to_string(pointer_to_size(value_));
	else if (type_ == SHORT) return __short_to_string(pointer_to_short(value_));
	else if (type_ == LONG) return __long_to_string(pointer_to_long(value_));
	else if (type_ == DOUBLE) return __double_to_string(pointer_to_double(value_));
	else return __get_wrong_string_heap();
}

type pointer_to_type(void* input_) { return (input_ != WRONG_POINTER ? *((type*)input_) : WRONG_TYPE); }

type_error pointer_to_error(void* input_) { return (input_ != WRONG_POINTER ? *((type_error*)input_) : WRONG_ERROR); }

type_warning pointer_to_warning(void* input_) { return (input_ != WRONG_POINTER ? *((type_warning*)input_) : WRONG_WARNING); }

error_warning* pointer_to_error_warning(void* input_) { return (input_ != WRONG_POINTER ? (error_warning*)input_ : WRONG_ERROR_WARNING); }

output* pointer_to_output(void* input_) { return (input_ != WRONG_POINTER ? (output*)input_ : WRONG_OUTPUT); }

boolean pointer_to_boolean(void* input_) { return (input_ != WRONG_POINTER ? *((boolean*)input_) : WRONG_BOOLEAN); }

char* pointer_to_string(void* input_) { return (input_ != WRONG_POINTER ? (char*)input_ : WRONG_STRING); }

char pointer_to_char(void* input_) { return (input_ != WRONG_POINTER ? *((char*)input_) : WRONG_CHAR); }

int pointer_to_int(void* input_) { return (input_ != WRONG_POINTER ? *((int*)input_) : WRONG_INT); }

size_t pointer_to_size(void* input_) { return (input_ != WRONG_POINTER ? *((size_t*)input_) : WRONG_SIZE); }

short pointer_to_short(void* input_) { return (input_ != WRONG_POINTER ? *((short*)input_) : WRONG_SHORT); }

long pointer_to_long(void* input_) { return (input_ != WRONG_POINTER ? *((long*)input_) : WRONG_LONG); }

double pointer_to_double(void* input_) { return (input_ != WRONG_POINTER ? *((double*)input_) : WRONG_DOUBLE); }

void* _get_wrong_value(const type type_, const boolean is_heap_) { return _get_wrong(type_, FALSE, is_heap_); }

void* __get_wrong_value_heap(const type type_) { return __get_wrong_heap(type_, FALSE); }

void* get_wrong_value_stack(const type type_) { return get_wrong_stack(type_, FALSE); }
