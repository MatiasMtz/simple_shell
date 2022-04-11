#include "main.h"
/**
 * terminated - Exit shell.
 * @str: User input.
 * @str1: Keyword for exit.
 */
void terminated(char *str, char *str1)
{
	int aux = 0;

	aux = _strcmp(str, str1);
	if (aux == 0)
	{
		if (isatty(STDIN_FILENO == 1))
			write(STDOUT_FILENO, "\n", 1);
		free(str);
		exit(0);
	}
}
