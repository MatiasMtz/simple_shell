#include "main.h"
/**
 * aux_exe - Function that complements the main.
 * @string: User input.
 * Return: 0.
 */
int aux_exe(char *string)
{
	struct stat buf;
	char *s = NULL, *ret = NULL;
	int cwd = 0;
	char **token = NULL;

	tabs(string);
	s = string;
	if (s[0] != '\n')
	{
		token = tokenizer(s, " \n");
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
				return (0);
			}
		}
		if (token[0][0] == '/')
		{
			if (token[0][1] >= 'a' && token[0][1] <= 'z')
			{
				if (stat(token[0], &buf) == 0)
				{
					execute(token[0], token), free(token);
				}
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
