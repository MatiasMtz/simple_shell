#include "main.h"
/**
 */
int main(void)
{
	char *string = NULL, *s = NULL, *ret = NULL;
	char **token = NULL;
	size_t input = 0, i = -1, buffer = 0;
	int flag = 0;
	struct stat buf;

	while (flag == 0)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			write(STDOUT_FILENO, "$ ", 2);
		}
		input = getline(&string, &buffer, stdin);
		if (input == i)
		{
			if ((isatty(STDIN_FILENO) == 1))
				write(STDOUT_FILENO, "\n", 1);
			free(string);
			return (0);
		}
		if (characters(string) == -1)
		{
			continue;
		}
		terminated(string, "EOF\n");
		terminated(string, "exit\n");
		s = string;
		if (s[0] != '\n')
		{
			token = tokenizer(s, " \n");
			if (string[0] == 47)
			{
				if (stat(token[0], &buf) == 0)
				{
					execute(token[0], token);
					free(token);
					free(string);
				}
				else
				{
					perror(token[0]);
					free(string);
					free(token[0]);
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
					continue;
				}
				execute(ret, token);
				free(token);
				free(ret);
			}
		}
	}
	return (0);
}

