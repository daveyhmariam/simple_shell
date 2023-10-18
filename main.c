#include "header.h"
/**
 * main - This is a simple shell created by
 * for ALX Team Project
 * Return: 0 if success
 */
int main(void)
{
	ssize_t bytes_rd = 0;
	size_t bf_size = 0;
	char *entry = NULL, *arguments[20];
	int counter = 1, vf_stat = 0, isFile_stat = 0, exit_stat = 0, blt_stat = 0;

	prompt("$ ", 2);
	bytes_rd = getline(&entry, &bf_size, stdin);
	while (bytes_rd != -1)
	{
		if (*entry != '\n')
		{
			getArgs(entry, arguments);
			if (arguments[0] != NULL)
			{
				isFile_stat = isFile(arguments[0]);
				if (isFile_stat != 0)
				{
					vf_stat = checkPath(arguments);
					if (vf_stat == 0)
						exit_stat = _exec(arguments), free(entry), free(*arguments);
					else
					{
					blt_stat = checkBltin(arguments, exit_stat);
					if (blt_stat != 0)
						exit_stat = _perror(arguments, counter), free(entry);
					}
				}
				else
				{
					exit_stat = _exec(arguments);
					free(entry);
				}
			}
			else
				free(entry);
		}
		else if (*entry == '\n')
			free(entry);
		entry = NULL, counter++;
		prompt("$ ", 2), bytes_rd = getline(&entry, &bf_size, stdin);
	}
	fFree(entry);
	return (exit_stat);
}
