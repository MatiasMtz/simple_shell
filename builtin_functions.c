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
 * env - COMPLETAR.
 * @str: COMPLETAR.
 * @str1: COMPLETAR.
 * Return: 0.
 */
void env(char *str, char *str1)
{
	int aux = 0, a = 0;
	char *env = NULL;

	aux = _strcmp(str, str1);
	if (aux == 0)
	{
		while (environ[a] != NULL)
		{
			env = environ[a];
			write(STDOUT_FILENO, env, _strlen(env));
			a++;
		}
		write(STDOUT_FILENO, "\n", 1);
	}
}
