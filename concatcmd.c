#include "header.h"
/**
 * concat - Concatenates Path strings with execubles
 * @_dir: PATH strings
 * @cmd: cmd to be concatenated with the directory
 * Return: Buffer to concatenated path
 */
char *concat(char *_dir, char *cmd)
{
	int i, j = 0, len1, len2;
	char *cmdPath = NULL;

	if (_dir == NULL || cmd == NULL)
		return (NULL);

	len1 = _strlen(_dir);
	len2 = _strlen(cmd);
	cmdPath = malloc(len1 + len2 + 2);
	if (cmdPath == NULL)
		return (NULL);
	for (i = 0; _dir[i] != '\0'; i++)
	{
		cmdPath[i] = _dir[i];
	}
	if (_dir[i - 1] != '/')
	{
		cmdPath[i] = '/';
		i++;
	}
	while (cmd[j] != '\0')
	{
		cmdPath[i + j] = cmd[j];
		j++;
	}
	cmdPath[i + j] = '\0';
	return (cmdPath);
}
