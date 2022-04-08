#include "main.h"
/**
 * characters - Function that compares if there are characters in the string.
 * @str: User input.
 * Return: Flag.
 */
int characters(char *str)
{
	int count = 0, flag = -1;

	while (str[count])
	{
		if (str[count] != '\n' && str[count] != ' ' && str[count] != '\t')
		{
			flag = 0;
			break;
		}
		count++;
	}
	return (flag);
}
