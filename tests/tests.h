#ifndef TESTS_H_
#define TESTS_H_

#include "code/headers/all.h"

int _tot_errors;

void run_all();

void run_strings();

void run_strings_wrong();

void run_arrays();

void run_arrays_wrong();

void run_structs();

void run_structs_wrong();

void run_io();

void run_io_wrong();

char* get_assessment(boolean);

void print_start(char*);

void print_start_wrong();

void print_end(char*);

void print_end_wrong();

void print_last();

void print_start_end_internal(char*, boolean, boolean);

#endif