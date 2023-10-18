#include "header.h"
/**
 * prompt - Prints the $ in consol
 * @prompt: Pointer to the string to be printed
 * @size: Length ot the string
 * Return: 0 if success or -1 if fails
 */
int prompt(const char *prompt, unsigned int size)
{
	int len;

	if (isatty(STDIN_FILENO))
	{
		len = write(1, prompt, size);
		if (len == -1)
			return (-1);
	}
		return (0);
}
/**
 * getArgs - Fill an array with user console input
 * @buf: input
 * @arguments: Array to be filled
 * Return: Length of the array
 */

int getArgs(char *buf, char **arguments)
{
	int idx = 0;
	char *token, *temp = buf, *cmd;

	cmd = strtok(buf, "\n\t\r ");
	arguments[idx] = cmd;
	while (temp != NULL)
	{
		++idx;
		token = strtok(NULL, "\n\t\r ");
		temp = token;
		arguments[idx] = token;
	}
	arguments[idx] = NULL;
	return (idx);
}
