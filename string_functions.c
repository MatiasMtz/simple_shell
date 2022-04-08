#include "main.h"
/**
 * _strlen - function that counts characters.
 * @s: string to count its chars.
 * Return: length of string.
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

/**
 * _strcmp - Compares 2 strings.
 * @s1:  String 1.
 * @s2: String 2.
 * Return: if s1 < s2 -> int <0, if s1 > s2 -> int >0, if s1 = s2 -> 0.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int n = 0;
	int x = 0;

	while (s1[n] != '\0')
	{
		n++;
	}
	while (s2[x] != '\0')
	{
		x++;
	}
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (n > x)
	{
		return (s1[x]);
	}
	else if (x < n)
	{
		return (s2[n] * -1);
	}
	return (0);
}

/**
 * *_strcat - check the code
 * @dest:  Pointers to src
 * @src: pointer to a variable.
 * Return: Retorno
 */
char *_strcat(char *dest, char *src)
{
	int countdest = 0, countsrc = 0, count = 0;
	char *newstring = NULL;

	while (dest[countdest] != '\0')
	{
		countdest++;
	}
	while (src[countsrc] != '\0')
	{
		countsrc++;
	}
	newstring = calloc(2, (countdest + countsrc + 1) * sizeof(char));
	if (newstring == NULL)
	{
		return (NULL);
	}
	while (countdest > count)
	{
		newstring[count] = dest[count];
		count++;
	}
	count = 0;
	while (countsrc > count)
	{
		newstring[count + countdest] = src[count];
		count++;
	}
	newstring[countdest + count + 1] = '\0';
	return (newstring);
}

/**
 * _strdup - duplicates str in a newly space in memory.
 * @str: String you want to duplicate.
 * Return: String duplicated.
 */
char *_strdup(char *str)
{
	char *str2 = NULL;
	int n = 0;
	int x = 0;

	if (str == NULL)
	{
		return ('\0');
	}
	while (str[n] != '\0')
	{
		n++;
	}
	n++;
	str2 = calloc(1, n * sizeof(char));
	if (str2 == NULL)
	{
		free(str2);
		return ('\0');
	}
	for (x = 0; x < n; x++)
	{
		str2[x] = str[x];
	}
	return (str2);
}
