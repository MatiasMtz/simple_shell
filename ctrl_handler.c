#include "main.h"
/**
 */
void ctrl_handler(__attribute__((unused))int signum)
{
	write(STDOUT_FILENO, "\n$ ", 3);
}
