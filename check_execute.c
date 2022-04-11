#include "main.h"
/**
 * check_and_execute - Function to check if file exists and execute.
 * @string: User input.
 * Return: 0 when executing or error found.
 */
int check_and_execute(char *string)
{
	struct stat buf;
	int check = 0, check2 = 0;
	char *s = NULL, *ret = NULL;
	char **token = NULL;

	tabs(string);
	s = string;
	if (s[0] != '\n')
	{
		token = tokenizer(s, " \n");
		check = check_dot_slash(token);
		if (check == 0)
			return (0);
		check2 = check_ddot_slash(token);
		if (check2 == 0)
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
 *
 */
int check_dot_slash(char **token)
{
	int cwd = 0;

	if (token[0][0] == '.' && token[0][1] == '/')
	{
		if (token[0][2] >= 'a' && token[0][2] <= 'z')
		{
			cwd = cwd_which(token);
			if (cwd == 0)
			{
				execute(token[0], token);
				free(token);
			}
			else
				perror(token[0]);
		}
		return (0);
	}
	return (-1);
}

int check_ddot_slash(char **token)
{
	int parent = 0;

	if (token[0][0] == '.' && token[0][1] == '.' && token[0][2])
	{
		if (token[0][3] >= 'a' && token[0][3] <= 'z')
		{
			parent = parent_which(token);
			if (parent == 0)
			{
				execute(token[0], token);
				free(token);
			}
			else
				perror(token[0]);
		}
		return (0);
	}
	return (-1);
}

