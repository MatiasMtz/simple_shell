#include "main.h"
/**
 * check_and_execute - Function to check if file exists and execute it.
 * @string: User input.
 * Return: 0 when executing or error found.
 */
int check_and_execute(char *string)
{
	struct stat buf;
	int check = 0;
	char *s = NULL, *ret = NULL;
	char **token = NULL;

	tabs(string);
	s = string;
	if (s[0] != '\n')
	{
		token = tokenizer(s, " \n");
		check = file_check(token);
		if (check == 0)
			return (0);
		if (token[0][0] == '/')
		{
			if (token[0][1] >= 'a' && token[0][1] <= 'z')
			{
				if (stat(token[0], &buf) == 0)
					execute(token[0], token), free(token);
				else
				{
					perror(token[0]);
					free(string), free(token[0]);
				}
			}
		}
		else
		{
			ret = _which(token);
			if (ret == NULL)
			{
				perror(token[0]), free(token), free(ret);
				return (0);
			}
			execute(ret, token), free(token), free(ret);
		}
		return (0);
	}
	return (0);
}

/**
 * file_check - checks for files in parent and working directories.
 * @token: User tokenized input.
 * Return: 0 if executed, -1 if error.
 */
int file_check(char **token)
{
	struct stat buf;
	int count = 0, aux = 0;

	while (token[0][count] != '\0')
		count++;
	if (token[0][0] == '.' && token[0][count] != '/')
	{
		aux = stat(token[0], &buf);
		if (aux == 0)
		{
			execute(token[0], token);
			free(token);
			return (0);
		}
		else
		{
			perror(token[0]);
			return (-1);
		}
	}
	return (-1);
}

/**
 * _which - Looks if a file exist in the PATH env variable.
 * @tknstring: User tokenized input.
 * Return: Return the absolute path of the program or NULL if error.
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
