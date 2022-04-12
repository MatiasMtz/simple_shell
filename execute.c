#include "main.h"
/**
 * execute - Function that creates chil processes and executes commands.
 * @str: Absolute command path.
 * @argv: user tokenized input to execute.
 * Return: 0 when error..
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
	return (0);
}
