#include "headers/variables.h"

void* assign_variable(void* out_, void* in_, const type type_) { return (variable_is_ok(in_, type_) == TRUE ? assign(out_, in_, type_, WRONG_SIZE) : get_wrong_variable_stack(type_)); }

void* __initialise_variable(const type type_) { return __initialise(1, type_, FALSE); }

void* __assign_variable(void* in_, const type type_) { return (variable_is_ok(in_, type_) == TRUE ? __assign(in_, 1, type_, FALSE) : __get_wrong_variable_heap(type_)); }

void* __assign_free_in_variable(void* in_h_, const type type_) { return (variable_is_ok(in_h_, type_) == TRUE ? __assign_free_in(in_h_, 1, type_, FALSE) : __assign_free_wrong_variable(in_h_, type_)); }

void* __assign_free_out_variable(void* out_h_, void* in_, const type type_) { return (variable_is_ok(in_, type_) == TRUE ? __assign_free_out(out_h_, in_, 1, type_, FALSE) : __assign_free_wrong_variable(out_h_, type_)); }

void* __assign_free_both_variable(void* out_h_, void* in_h_, const type type_) { return (variable_is_ok(in_h_, type_) == TRUE ? __assign_free_both(out_h_, in_h_, 1, type_, FALSE) : __assign_free_both_wrong_variable(out_h_, in_h_, type_)); }

void* __assign_wrong_variable(const type type_) { return __assign_wrong(0, type_, FALSE); }

void* __assign_free_wrong_variable(void* in_out_h_, const type type_) { return __assign_free_wrong(in_out_h_, 0, type_, FALSE); }

void* __assign_free_both_wrong_variable(void* out_h_, void* in_h_, const type type_) { return __assign_free_both_wrong(out_h_, in_h_, 0, type_, FALSE); }

void* get_wrong_variable(const type type_) { return get_wrong_variable_stack(type_); }

void* _get_wrong_variable(const type type_, const boolean is_heap_) { return _get_wrong(type_, FALSE, is_heap_); }

void* get_wrong_variable_stack(const type type_) { return get_wrong_stack(type_, FALSE); }

void* __get_wrong_variable_heap(const type type_) { return __get_wrong_heap(type_, FALSE); }

boolean variable_is_ok(const void* in_, const type type_) { return (in_ != get_wrong_variable(type_)); }

char* __concatenate_two_variables(void* in1_, const type type1_, void* in2_, const type type2_)
{
	char* in1 = _variable_to_string((void*)in1_, type1_);
	char* in2 = _variable_to_string((void*)in2_, type2_);

	size_t length1 = get_string_length_internal(in1, FALSE);
	size_t length2 = get_string_length_internal(in2, FALSE);

	char* out = ((length1 > WRONG_SIZE && length2 > WRONG_SIZE) ? __concatenate_two_strings_internal(in1, length1, in2, length2) : __get_wrong_string_heap());

	if (variable_to_string_is_heap(type1_)) free(in1);
	if (variable_to_string_is_heap(type2_)) free(in2);

	return out;
}
