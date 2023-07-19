#include "headers/memory.h"

void* assign(void* out_, void* in_, const type type_, const size_t array_size_) { return _assign_internal(out_, in_, type_, (array_size_ > WRONG_SIZE), array_size_, FALSE); }

void free_(void* in_h_, const type type_)
{
	if (type_ == OUTPUT) free_output(in_h_);
	else free(in_h_);
}

void free_output(output* in_h_)
{
	if (in_h_ != WRONG_OUTPUT)
	{
		free(in_h_->_value);

		free_output_error_warning(in_h_);
	}

	free(in_h_);
}

void free_output_error_warning(output* in_h_)
{
	if (in_h_ != WRONG_OUTPUT && in_h_->_error_warning != WRONG_ERROR_WARNING) free(in_h_->_error_warning);
}

void* __initialise(const size_t tot_elements_, const type type_, const boolean is_array_) { return ((type_ != WRONG_TYPE && (tot_elements_ > WRONG_SIZE || type_ == STRING)) ? __initialise_internal(get_memory_size(tot_elements_, type_, TRUE)) : __get_wrong_heap(type_, is_array_)); }

void* __assign(void* in_, const size_t tot_elements_, const type type_, const boolean is_array_) { return __assign_free_internal(in_, tot_elements_, type_, is_array_, FALSE); }

void* __assign_free_in(void* in_h_, const size_t tot_elements_, const type type_, const boolean is_array_) { return __assign_free_internal(in_h_, tot_elements_, type_, is_array_, TRUE); }

void* __assign_free_out(void* out_h_, void* in_, const size_t tot_elements_, const type type_, const boolean is_array_)
{
	free_(out_h_, type_);

	out_h_ = __assign_free_internal(in_, tot_elements_, type_, is_array_, FALSE);

	return out_h_;
}

void* __assign_free_both(void* out_h_, void* in_h_, const size_t tot_elements_, const type type_, const boolean is_array_)
{
	free_(out_h_, type_);

	out_h_ = __assign_free_internal(in_h_, tot_elements_, type_, is_array_, TRUE);

	return out_h_;
}

void* __assign_wrong(const size_t tot_elements_, const type type_, const boolean is_array_) { return __assign_free_in(__get_wrong_heap(type_, is_array_), tot_elements_, type_, is_array_); }

void* __assign_free_wrong(void* in_out_h_, const size_t tot_elements_, const type type_, const boolean is_array_)
{
	free_(in_out_h_, type_);

	return __assign_wrong(tot_elements_, type_, is_array_);
}

void* __assign_free_both_wrong(void* out_h_, void* in_h_, const size_t tot_elements_, const type type_, const boolean is_array_)
{
	free_(out_h_, type_);
	free_(in_h_, type_);

	return __assign_wrong(tot_elements_, type_, is_array_);
}

size_t get_memory_size(const size_t tot_elements_, const type type_, const boolean is_heap_)
{
    if (type_ == WRONG_TYPE || (tot_elements_ == WRONG_SIZE && type_ != STRING)) return (is_heap_ ? get_type_size(WRONG_SIZE) : WRONG_SIZE);

    size_t out = tot_elements_;
    if (type_ == STRING) out++;

    if (is_heap_) out *= get_type_size(type_);

    return out;
}

void* get_wrong(const type type_, const boolean is_array_) { return get_wrong_stack(type_, is_array_); }

void* _get_wrong(const type type_, const boolean is_array_, const boolean is_heap_) { return (is_heap_ ? __get_wrong_heap(type_, is_array_) : get_wrong_stack(type_, is_array_)); }

void* __get_wrong_heap(const type type_, const boolean is_array_)
{
	void* out;

	size_t size = 0;

	if (type_ == STRING)
	{
		out = __initialise(size, type_, is_array_);

		if (out != WRONG_POINTER) ((char*)out)[size] = STRING_TERMINATION;
	}
	else
	{
		size = 1;

		out = _assign_internal(__initialise(size, type_, is_array_), get_wrong(type_, is_array_), type_, is_array_, size, TRUE);
	}

	return out;
}

void* get_wrong_stack(const type type_, const boolean is_array_)
{
	void* out;

	if (is_array_ == TRUE) out = WRONG_POINTER;
	else if (type_ == TYPE) out = &WRONG_TYPE;
	else if (type_ == ERROR) out = &WRONG_ERROR;
	else if (type_ == WARNING) out = &WRONG_WARNING;
	else if (type_ == ERROR_WARNING) out = WRONG_ERROR_WARNING;
	else if (type_ == OUTPUT) out = WRONG_OUTPUT;
	else if (type_ == BOOLEAN) out = &WRONG_BOOLEAN;
	else if (type_ == STRING) out = WRONG_STRING;
	else if (type_ == CHAR) out = &WRONG_CHAR;
	else if (type_ == INT) out = &WRONG_INT;
	else if (type_ == SIZE) out = &WRONG_SIZE;
	else if (type_ == SHORT) out = &WRONG_SHORT;
	else if (type_ == LONG) out = &WRONG_LONG;
	else if (type_ == DOUBLE) out = &WRONG_DOUBLE;
	else out = WRONG_POINTER;

	return out;
}

void* __assign_free_internal(void* in_, const size_t tot_elements_, const type type_, const boolean is_array_, const boolean free_in_)
{
	size_t size = get_memory_size(tot_elements_, type_, TRUE);

	void* out = _assign_internal(__initialise_internal(size), in_, type_, is_array_, size, TRUE);

	if (free_in_) free_(in_, type_);

	return out;
}

void* _assign_internal(void* out_, void* in_, const type type_, const boolean is_array_, const size_t size_, const boolean is_heap_)
{
	if (out_ == WRONG_POINTER && is_heap_ == TRUE) out_ = __get_wrong_heap(type_, is_array_);
	else
	{
		if (type_ == STRING) out_ = strcpy(out_, in_);
		else out_ = memcpy(out_, in_, size_);
	}

	return out_;
}

void* __initialise_internal(const size_t size_) { return malloc(size_); }
