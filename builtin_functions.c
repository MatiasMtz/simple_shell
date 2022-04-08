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
 *
void env(char *str, char *str1)
{
	int a = 0, b = 0, aux = 0;
	char *string = NULL;
	
	printf("INPUT = %s\n", str);
	printf("ENV = %s\n", str1);
	aux = _strcmp(str, str1);
	if (aux == 0)
	{
		printf("AUX = %d\n", aux);
		while (environ[a] != NULL)
		{
			printf("ENVIRON[%d]", a);
			while (environ[a][b] != '\0')
			{
				printf("ENVIRON[%d][%d]", a, b);
				string = &(environ[a][b]);
				write(STDOUT_FILENO, string, _strlen(string));
				break;
				b++;
			}
			a++;
		}
	}
}*/
