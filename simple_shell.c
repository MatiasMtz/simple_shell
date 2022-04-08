#include "main.h"
/**
 */
int main(void)
{
	char *string = NULL;
	size_t input = 0, i = -1, buffer = 0;
	int flag = 0, aux = 0;

	while (flag == 0)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 2);
		input = getline(&string, &buffer, stdin);
		if (input == i)
		{
			if ((isatty(STDIN_FILENO) == 1))
				write(STDOUT_FILENO, "\n", 1);
			free(string);
			return (0);
		}
		if (characters(string) == -1)
			continue;
		terminated(string, "exit\n");
		aux = aux_exe(string);
		if (aux == 0)
			continue;
	}
	return (0);
}

