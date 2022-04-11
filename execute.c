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
	int status;

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
		wait(&status);
	}
	return (WEXITSTATUS(status));
}
