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
int env(char *str, char *str1)
{
	int aux = 0, a = 0, b = 0;
	char *env = NULL;

	aux = _strcmp(str, str1);
	if (aux == 0)
	{
		while (environ[a] != NULL)
		{
			while (environ[a][b] != '\0')
			{
				env = &(environ[a][b]);
				write(STDOUT_FILENO, env, _strlen(env));
				break;
				b++;
			}
			putchar('\n');
			a++;
		}
	}
	return (0);
}
