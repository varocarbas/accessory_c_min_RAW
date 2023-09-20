#include "headers/_first_os.h"

os OS = LINUX;

boolean os_is_unix() { return (OS != WINDOWS); }

boolean os_is_posix() { return (OS != WINDOWS); }

char* os_to_string()
{
	char* out;

	if (OS == LINUX) out = "linux";
	else if (OS == WINDOWS) out = "windows";
	else if (OS == MAC) out = "mac";
	else if (OS == OTHER) out = "other";
	else out = WRONG_STRING;

	return out;
}
