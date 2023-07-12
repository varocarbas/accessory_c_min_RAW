#include "headers/variables.h"

void* assign_variable(void* out_, void* in_, const type type_) { return ((out_ != WRONG_POINTER && variable_is_ok(in_, type_) == TRUE) ? assign(out_, in_, type_, WRONG_SIZE) : get_wrong_variable_stack(type_)); }

void* __initialise_variable(const type type_) { return __initialise(1, type_, FALSE); }

void* __assign_variable(void* in_, const type type_) { return (variable_is_ok(in_, type_) == TRUE ? __assign(in_, 1, type_, FALSE) : __get_wrong_variable_heap(type_)); }

void* __assign_free_in_variable(void* in_h_, const type type_) { return (variable_is_ok(in_h_, type_) == TRUE ? __assign_free_in(in_h_, 1, type_, FALSE) : __assign_free_wrong_variable(in_h_, type_)); }

void* __assign_free_out_variable(void* out_h_, void* in_, const type type_) { return (variable_is_ok(in_, type_) == TRUE ? __assign_free_out(out_h_, in_, 1, type_, FALSE) : __assign_free_wrong_variable(out_h_, type_)); }

void* __assign_free_both_variable(void* out_h_, void* in_h_, const type type_) { return (variable_is_ok(in_h_, type_) == TRUE ? __assign_free_both(out_h_, in_h_, 1, type_, FALSE) : __assign_free_both_wrong_variable(out_h_, in_h_, type_)); }

void* __assign_wrong_variable(const type type_) { return __assign_wrong(0, type_, FALSE); }

void* __assign_free_wrong_variable(void* in_out_h_, const type type_) { return __assign_free_wrong(in_out_h_, 0, type_, FALSE); }

void* __assign_free_both_wrong_variable(void* out_h_, void* in_h_, const type type_) { return __assign_free_both_wrong(out_h_, in_h_, 0, type_, FALSE); }

void* _get_wrong_variable(const type type_, const boolean is_heap_) { return _get_wrong(type_, FALSE, is_heap_); }

void* get_wrong_variable_stack(const type type_) { return get_wrong_stack(type_, FALSE); }

void* __get_wrong_variable_heap(const type type_) { return __get_wrong_heap(type_, FALSE); }

boolean variable_is_ok(const void* in_, const type type_) { return (in_ != WRONG_POINTER && type_ != WRONG_TYPE); }
