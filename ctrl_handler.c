#include "main.h"
/**
 * ctrl_handler - prints the PS1 to continue entering commands after Ctrl+C.
 * @signum: unused arg.
 */
void ctrl_handler(__attribute__((unused))int signum)
{
	write(STDOUT_FILENO, "\n$ ", 3);
}
