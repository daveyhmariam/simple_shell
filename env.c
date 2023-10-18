#include "header.h"
/**
 * _getenv - Get the content of a environment variable
 * @varName: Variable to extract from environ
 * Return: Pointer to the content of a variable, or NULL if fails
 */
char *_getenv(char *varName)
{
	int i = 0;
	const char delim[] = "=";
	char *token, *envCopy, *tokenCopy;

	if (varName != NULL)
	{
		if (environ == NULL)
			return (NULL);
		envCopy = _strdup(environ[i]);
		while (envCopy != NULL)
		{
			token = strtok(envCopy, delim);
			if (_strcmp(token, varName) == 0)
			{
				token = strtok(NULL, delim);
				/**printf("%s\n", token);*/
				tokenCopy = _strdup(token);
				free(envCopy);
				return (tokenCopy);
			}
			i++;
			free(envCopy);
			envCopy = _strdup(environ[i]);
		}
	}
	return (NULL);
}
