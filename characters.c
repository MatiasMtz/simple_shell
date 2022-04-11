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

/**
 * tabs - Function that changes tabs to spaces.
 * @str: User input.
 */
void tabs(char *str)
{
	int count = 0;

	while (str[count] != '\0')
	{
		if (str[count] == 9)
		{
			str[count] = ' ';
			count++;
		}
		else
			count++;
	}
}
