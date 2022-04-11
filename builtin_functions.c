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
		free(str);
		exit(0);
	}
}

/**
 */
void _env(void)
{
	int count = 0;

	while (environ[count])
	{
		write(1, environ[count], _strlen(environ[count]));
		write(1, "\n", 1);
		count++;
		break;
	}
}
