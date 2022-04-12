#include "main.h"
/**
 * ctrl_handler - completar
 * @signum: completar
 */
void ctrl_handler(__attribute__((unused))int signum)
{
	write(STDOUT_FILENO, "\n$ ", 3);
}
