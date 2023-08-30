#ifndef TESTS_H_
#define TESTS_H_

#include "code/headers/all.h"

void run_tests();

void run_tests_strings();

void run_tests_arrays();

void run_tests_structs();

char* get_assessment(boolean);

void print_start(char*);

void print_start_wrong();

void print_end(char*);

void print_end_wrong();

void print_start_end_internal(char*, boolean, boolean);

#endif
