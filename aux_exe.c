#include "main.h"
/**
 */
int aux_exe(char *string)
{
	struct stat buf;
	char *s = NULL, *ret = NULL;
	char **token = NULL;

	s = string;
	if (s[0] != '\n')
	{
		token = tokenizer(s, " \n");
		if (string[0] == '/')
		{
			if (token[0][1] >= 'a' && token[0][1] <= 'z')
			{
				if (stat(token[0], &buf) == 0)
				{
					execute(token[0], token);
					free(token);
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
				perror(token[0]);
				free(token);
				free(ret);
				return (0);
			}
			execute(ret, token);
			free(token), free(ret);
		}
		return (0);
	}
	return (0);
}
