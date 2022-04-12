#include "main.h"
/**
 * terminated - exit built-in.
 * @str: User input.
 * @str1: Keyword for "exit".
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
 * _env - env built-in.
 * @str: User input.
 * Return: 1 if the input its the same as "env\n", 0 if not.
 */
int _env(char *str)
{
	int count = 0;
	char *aux = _strdup(str);

	if (_strcmp(strtok(aux, " "), "env\n") == 0)
	{
		while (environ[count] != NULL)
		{
			write(1, environ[count], _strlen(environ[count]));
			write(1, "\n", 1);
			count++;
		}
		free(aux);
		return (1);
	}
	free(aux);
	return (0);
}
