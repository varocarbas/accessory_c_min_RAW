#include "headers/common.h"

const char STRING_TERMINATION = '\0';

char* SEPARATOR_DEFAULT = " --- ";
char* SEPARATOR_PRINT_ARRAY_START = "{ ";
char* SEPARATOR_PRINT_ARRAY_END = " }";
char* SEPARATOR_PRINT_ARRAY_ITEMS = ", ";

error_warning* WRONG_ERROR_WARNING = (error_warning*)0;
output* WRONG_OUTPUT = (output*)0;
char* WRONG_STRING = "";
void* WRONG_POINTER = (void*)0;

type WRONG_TYPE = WRONG_TYPE0;
type_error WRONG_ERROR = WRONG_ERROR0;
type_warning WRONG_WARNING = WRONG_WARNING0;
boolean WRONG_BOOLEAN = FALSE;
char WRONG_CHAR = ' ';
int WRONG_INT = 0;
size_t WRONG_SIZE = 0;
short WRONG_SHORT = 0;
long WRONG_LONG = 0;
double WRONG_DOUBLE = 0;
