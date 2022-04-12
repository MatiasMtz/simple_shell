#include "main.h"
/**
 * _getenv - Searches the enviroment list to find the enviroment variable name.
 * @env: Name of the enviroment variable.
 * Return: Returns the tokenized environment variable.
 */
char **_getenv(char *env)
{
	int a = 0;
	int b = 0;
	char *name = NULL;

	for (b = 0; environ[b] != NULL; b++)
	{
		for (a = 0; environ[b][a] != '='; a++)
		{
			if (environ[b][a] != env[a])
				break;
			if (environ[b][a] == env[a])
			{
				if (env[a + 1] == '\0' && environ[b][a + 1] == '=')
				{
					name = _strdup(&(environ[b][a + 2]));
					return (envtokenizer(name));
				}
			}
		}
	}
	return (NULL);
}

/**
 * envtokenizer - Tokenizes enviroment variables.
 * @name: The full PATH seperated by :'s.
 * Return: An array of strings
**/
char **envtokenizer(char *name)
{
	int tokdir, tokcount = 0, count = 0;
	char *tok = NULL, *dup = NULL;
	char **buffer = NULL;

	dup = _strdup(name);
	for (count = 0; name[count] != '\0'; count++)
	{
		if (name[count] == ':')
		{
			tokcount++;
		}
	}
	buffer = calloc(1, sizeof(char *) * (tokcount + 2));
	if (buffer != NULL)
	{
		tokdir = 0;
		tok = strtok(name, ":");
		while (tokdir < (tokcount + 1))
		{
			buffer[tokdir] = tok;
			tok = strtok(NULL, ":");
			tokdir++;
		}
	buffer[tokdir] = NULL;
	}
	free(dup);
	return (buffer);
}
