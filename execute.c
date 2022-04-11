#include "main.h"
/**
 * execute - Function that creates children and executes commands.
 * @str: Full command path.
 * @argv: Array of arguments to execute.
 * Return: 0.
 */
int execute(char *str, char **argv)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		free(str);
		perror(str);
	}
	if (pid == 0)
	{
		if (execve(str, argv, environ) == -1)
			perror(str);
		exit(99);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}

/**
 * _which - Concatenates the arguments and compares
 *  them with the $PATH looking for a match.
 * @tknstring: Array of arguments.
 * Return: Return the complete path of the executables.
 */
char *_which(char **tknstring)
{
	struct stat buf;
	char *strconcat = NULL, *strconcat2 = NULL;
	char **path = NULL;
	int aux = 0, count = 0;

	path = _getenv("PATH");
	while (path[count] != NULL)
	{
		strconcat = _strcat(path[count], "/");
		strconcat2 = _strcat(strconcat, tknstring[0]);
		free(strconcat);
		aux = stat(strconcat2, &buf);
		if (aux == 0)
		{
			free(path[0]);
			free(path);
			return (strconcat2);
		}
		else
		{
			count++;
		}
		free(strconcat2);
	}
	free(path[0]);
	free(path);
	return (NULL);
}
