#include "main.h"
/**
 * specialchars - Function that compares if there are "\n, , and \t"
 * in the string.
 * @str: User input.
 * Return: 0 if there is any special char, -1 if not.
 */
int specialchars(char *str)
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
 * tabs - Function that exchange tabs into spaces.
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
