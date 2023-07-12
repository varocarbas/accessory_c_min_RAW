#ifndef VARIABLES_H_
#define VARIABLES_H_

#include "all.h"

void* assign_variable(void*, void*, type);

void* __initialise_variable(type);

void* __assign_variable(void*, type);

void* __assign_free_in_variable(void*, type);

void* __assign_free_out_variable(void*, void*, type);

void* __assign_free_both_variable(void*, void*, type);

void* __assign_wrong_variable(type);

void* __assign_free_wrong_variable(void*, type);

void* __assign_free_both_wrong_variable(void*, void*, type);

void* _get_wrong_variable(type, boolean);

void* get_wrong_variable_stack(type);

void* __get_wrong_variable_heap(type);

boolean variable_is_ok(const void*, type);

#endif
