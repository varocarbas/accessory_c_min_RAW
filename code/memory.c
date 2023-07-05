#include "headers/memory.h"

void* __initialise(const size_t tot_elements_, const type type_, const boolean is_array_) { return ((type_ != WRONG_TYPE && (tot_elements_ > WRONG_SIZE || type_ == STRING)) ? __initialise_internal(get_memory_size(tot_elements_, type_, TRUE)) : __get_wrong_heap(type_, is_array_)); }

void* __assign(void* input_, const size_t tot_elements_, const type type_, const boolean is_array_) { return __assign_free_internal(input_, tot_elements_, type_, is_array_, FALSE); }

void* __assign_free_in(void* input_h_, const size_t tot_elements_, const type type_, const boolean is_array_) { return __assign_free_internal(input_h_, tot_elements_, type_, is_array_, TRUE); }

void* __assign_free_out(void* output_h_, void* input_, const size_t tot_elements_, const type type_, const boolean is_array_)
{
	free(output_h_);

	output_h_ = __assign_free_internal(input_, tot_elements_, type_, is_array_, FALSE);

	return output_h_;
}

void* __assign_free_both(void* output_h_, void* input_h_, const size_t tot_elements_, const type type_, const boolean is_array_)
{
	free(output_h_);

	output_h_ = __assign_free_internal(input_h_, tot_elements_, type_, is_array_, TRUE);

	return output_h_;
}

void* __assign_wrong(const size_t tot_elements_, const type type_, const boolean is_array_) { return __assign_free_in(__get_wrong_heap(type_, is_array_), tot_elements_, type_, is_array_); }

void* __assign_free_wrong(void* input_output_h_, const size_t tot_elements_, const type type_, const boolean is_array_)
{
	free(input_output_h_);

	return __assign_wrong(tot_elements_, type_, is_array_);
}

void* __assign_free_both_wrong(void* output_h_, void* input_h_, const size_t tot_elements_, const type type_, const boolean is_array_)
{
	free(output_h_);
	free(input_h_);

	return __assign_wrong(tot_elements_, type_, is_array_);
}

size_t get_memory_size(const size_t tot_elements_, const type type_, const boolean is_heap_)
{
    if (type_ == WRONG_TYPE || (tot_elements_ == WRONG_SIZE && type_ != STRING)) return (is_heap_ ? get_type_size(WRONG_SIZE) : WRONG_SIZE);

    size_t output = tot_elements_;
    if (type_ == STRING) output++;

    if (is_heap_) output *= get_type_size(type_);

    return output;
}

void* _get_wrong(const type type_, const boolean is_array_, const boolean is_heap_) { return (is_heap_ ? __get_wrong_heap(type_, is_array_) : get_wrong_stack(type_, is_array_)); }

void* __get_wrong_heap(const type type_, const boolean is_array_)
{
	void* output;

	if (type_ == STRING)
	{
		output = __initialise(0, type_, is_array_);

		if (output != WRONG_POINTER) ((char*)output)[0] = STRING_TERMINATION;
	}
	else
	{
		output = __initialise(1, type_, is_array_);

		if (output != WRONG_POINTER) output = get_wrong_stack(type_, is_array_);
	}

	return output;
}

void* get_wrong_stack(const type type_, const boolean is_array_)
{
	if (is_array_ == TRUE) return WRONG_POINTER;
	else if (type_ == TYPE) return &WRONG_TYPE;
	else if (type_ == ERROR) return &WRONG_ERROR;
	else if (type_ == WARNING) return &WRONG_WARNING;
	else if (type_ == ERROR_WARNING) return WRONG_ERROR_WARNING;
	else if (type_ == OUTPUT) return WRONG_OUTPUT;
	else if (type_ == BOOLEAN) return &WRONG_BOOLEAN;
	else if (type_ == STRING) return &WRONG_STRING;
	else if (type_ == CHAR) return &WRONG_CHAR;
	else if (type_ == INT) return &WRONG_INT;
	else if (type_ == SIZE) return &WRONG_SIZE;
	else if (type_ == SHORT) return &WRONG_SHORT;
	else if (type_ == LONG) return &WRONG_LONG;
	else if (type_ == DOUBLE) return &WRONG_DOUBLE;
	else return WRONG_POINTER;
}

void* __assign_free_internal(void* input_, const size_t tot_elements_, const type type_, const boolean is_array_, boolean free_input_)
{
	size_t size = get_memory_size(tot_elements_, type_, TRUE);

	void* output = __initialise_internal(size);

	if (output == WRONG_POINTER) output = __get_wrong_heap(type_, is_array_);
	else
	{
		if (type_ == STRING) output = strcpy(output, input_);
		else output = memcpy(output, input_, size);
	}

	if (free_input_) free(input_);

	return output;
}

void* __initialise_internal(const size_t size_) { return malloc(size_); }
