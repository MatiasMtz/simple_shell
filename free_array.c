#include "main.h"
/**
 * free_array - Function that free arrays.
 * @string: Array we want to free.
 */
void free_array(char **string)
{
	int count = 0;

	while (string[count])
	{
		free(string[count]);
		count++;
	}
	free(string);
}
