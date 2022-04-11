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

/**
 */
int cwd_which(char **tknstring)
{
	struct stat buf;
	char *buffer = NULL, *strconcat = NULL, *cwd = NULL, *tkn = NULL;
	int aux = 0;

	cwd = getcwd(buffer, 1024);
	tkn = &tknstring[0][1];
	if (tkn != NULL)
	{
		strconcat = _strcat(cwd, tkn);
		aux = stat(strconcat, &buf);
		if (aux == 0)
		{
			free(strconcat);
			free(cwd);
			return (0);
		}
		else
		{
			free(strconcat);
			free(cwd);
			free(tknstring);
			return (-1);
		}
	}
	free(strconcat);
	free(cwd);
	return (-1);
}

int parent_which(char **token)
{
	struct stat buf;
	char *buffer = NULL, *strconcat = NULL, *cwd = NULL, *parent = NULL, *tkn = NULL, *strconcat2 = NULL;
	int aux = 0;

	cwd = getcwd(buffer, 1024);
	parent = dirname(cwd);
	tkn = &token[0][3];
	if (tkn != NULL)
	{
		strconcat = _strcat(parent, "/");
		strconcat2 = _strcat(strconcat, tkn);
		aux = stat(strconcat, &buf);
		if (aux == 0)
		{
			free(strconcat);
			free(strconcat2);
			free(cwd);
			return (0);
		}
		else
		{
			free(strconcat);
			free(strconcat2);
			free(cwd);
			return (-1);
		}
	}
	free(cwd);
	free(strconcat);
	return (-1);
}
