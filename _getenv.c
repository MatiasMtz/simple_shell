#include "main.h"
/**
 * _getenv - Searches for the desired env variable into the environ list.
 * @env: Name of the enviroment variable you want to get.
 * Return: Returns the tokenized environment variable.
 */
char **_getenv(char *env)
{
	int len = 0;
	int height = 0;
	char *name = NULL;

	for (len = 0; environ[len] != NULL; len++)
	{
		for (height = 0; environ[len][height] != '='; height++)
		{
			if (environ[len][height] != env[height])
				break;
			if (environ[len][height] == env[height])
			{
				if (env[height + 1] == '\0' && environ[len][height + 1] == '=')
				{
					name = _strdup(&(environ[len][height + 2]));
					return (envtokenizer(name));
				}
			}
		}
	}
	return (NULL);
}

/**
 * envtokenizer - Tokenizes env variables.
 * @name: The full PATH seperated by :'s.
 * Return: A 2d array of strings.
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
