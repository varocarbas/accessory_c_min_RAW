#include "headers/arrays.h"

boolean array_is_ok(const void* input_, const size_t size_, const type type_) { return (array_is_ok_internal(input_) && size_ > WRONG_SIZE && type_ != WRONG_TYPE); }

void* __initialise_array(const size_t size_, const type type_) { return __initialise(size_, type_, TRUE); }

void* __assign_array(void* input_, const size_t size_, const type type_) { return (array_is_ok(input_, size_, type_) == TRUE ? __assign(input_, size_, type_, TRUE) : __assign_wrong_array(size_, type_)); }

void* __assign_free_in_array(void* input_h_, const size_t size_, const type type_) { return (array_is_ok(input_h_, size_, type_) == TRUE? __assign_free_in(input_h_, size_, type_, TRUE) : __assign_free_wrong_array(input_h_, size_, type_)); }

void* __assign_free_out_array(void* output_h_, void* input_, const size_t size_, const type type_) { return (array_is_ok(input_, size_, type_) == TRUE ? __assign_free_out(output_h_, input_, size_, type_, TRUE) : __assign_free_wrong_array(output_h_, size_, type_)); }

void* __assign_free_both_array(void* output_h_, void* input_h_, const size_t size_, const type type_) { return (array_is_ok(input_h_, size_, type_) == TRUE ? __assign_free_both(output_h_, input_h_, size_, type_, TRUE) : __assign_free_both_wrong_array(output_h_, input_h_, size_, type_)); }

void* __assign_wrong_array(const size_t size_, const type type_) { return __assign_wrong(size_, type_, TRUE); }

void* __assign_free_wrong_array(void* input_output_h_, const size_t size_, const type type_) { return __assign_free_wrong(input_output_h_, size_, type_, TRUE); }

void* __assign_free_both_wrong_array(void* output_h_, void* input_h_, const size_t size_, const type type_) { return __assign_free_both_wrong(output_h_, input_h_, size_, type_, TRUE); }

size_t get_initial_array_size(const size_t size_, const type type_, const boolean is_heap_) { return get_memory_size(size_, type_, is_heap_); }

void print_array(void* input_, const size_t size_, const type type_)
{
	if (array_is_ok(input_, size_, type_) == FALSE) return;

	print_array_start_end_internal(TRUE);

	const size_t max_i = size_ - 1;

	for (size_t i = 0; i <= max_i; i++) { print_array_item_internal(i, max_i, get_array_value_internal(input_, i, type_), get_type_format(type_), type_); }

	print_array_start_end_internal(FALSE);
}

void* get_array_value(const void* array_, const size_t i_, const type type_) { return ((array_is_ok_internal(array_) && type_ != WRONG_TYPE) ? get_array_value_internal(array_, i_, type_) : get_wrong_value_stack(type_)); }

void* _get_wrong_array(const type type_, const boolean is_heap_) { return _get_wrong(type_, TRUE, is_heap_); }

void* __get_wrong_array_heap(const type type_) { return __get_wrong_heap(type_, TRUE); }

void* get_wrong_array_stack(const type type_) { return get_wrong_stack(type_, TRUE); }

boolean array_is_ok_internal(const void* input_) { return (input_ != WRONG_POINTER); }

void* get_array_value_internal(const void* array_, const size_t i_, const type type_)
{
	if (type_ == TYPE) return &(((type*)array_)[i_]);
	else if (type_ == ERROR) return &(((type_error*)array_)[i_]);
	else if (type_ == WARNING) return &(((type_warning*)array_)[i_]);
	else if (type_ == ERROR_WARNING) return &(((error_warning*)array_)[i_]);
	else if (type_ == OUTPUT) return &(((output*)array_)[i_]);
	else if (type_ == BOOLEAN) return &(((boolean*)array_)[i_]);
	else if (type_ == STRING) return (((char**)array_)[i_]);
	else if (type_ == CHAR) return &(((char*)array_)[i_]);
	else if (type_ == INT) return &(((int*)array_)[i_]);
	else if (type_ == SIZE) return &(((size_t*)array_)[i_]);
	else if (type_ == SHORT) return &(((short*)array_)[i_]);
	else if (type_ == LONG) return &(((long*)array_)[i_]);
	else if (type_ == DOUBLE) return &(((double*)array_)[i_]);
	else if (type_ == BOOLEAN) return &(((boolean*)array_)[i_]);
	else return WRONG_POINTER;
}

void print_array_start_end_internal(const boolean is_start_)
{
	print_string_internal((is_start_ == TRUE ? SEPARATOR_PRINT_ARRAY_START : SEPARATOR_PRINT_ARRAY_END), FALSE);

	if (is_start_ == FALSE) print_new_line();
}

void print_array_item_internal(const size_t i, const size_t max_i, void* value_, const char* format_, const type type_)
{
	print_internal(value_, format_, type_, FALSE);

	if (i < max_i) print_string_internal(SEPARATOR_PRINT_ARRAY_ITEMS, FALSE);
}
