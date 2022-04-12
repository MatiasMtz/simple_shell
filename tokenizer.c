#include "main.h"
/**
 * wc - Word counting function.
 * @string: String to be tokenized.
 * @delim: Tokenization delimiter.
 * Return: Returns how many words are in *string..
*/
int wc(char *string, const char *delim)
{
	char *dup_string = NULL, *token = NULL;
	int count = 0;

	if (string == NULL || delim == NULL)
	{
	return (0);
	}
	dup_string = _strdup(string);
	token = strtok(dup_string, delim);
	while (token != NULL)
	{
	count++;
	token = strtok(NULL, delim);
	}
	count++;
	free(dup_string);
	return (count);
}

/**
 * tokenizer - Function that breaks a string into a
 * sequence of zero or more nonempty tokens.
 * @string: String to be tokenized.
 * @delim: Tokenization delimiter.
 * Return: Null if it fails or pointer to a 2d array.
 */
char **tokenizer(char *string, const char *delim)
{
	char *dup_str = NULL, *token = NULL;
	char **buffer = NULL;
	int word_count, count = 0;

	dup_str = string;
	if (dup_str == NULL || delim == NULL)
	{
		return (NULL);
	}
	word_count = wc(dup_str, delim);
	buffer = calloc(1, (word_count + 1) * sizeof(char *));
	if (buffer == NULL)
	{
		return (NULL);
	}
	token = strtok(dup_str, delim);
	while (token != NULL)
	{
		buffer[count] = token;
		token = strtok(NULL, delim);
		count++;
	}
	buffer[count] = NULL;
	free(token);
	return (buffer);
}
