#include "header.h"
/**
 * isFile - Verify if a file is found
 * @pathtok: pathtok to the file
 * Return: 0 if the file isFile or -1 if not
 */
int isFile(char *pathtok)
{
	int isFile_stat;

	isFile_stat = (open(pathtok, O_RDONLY));
	if (isFile_stat != -1)
	{
		close(isFile_stat);
		return (0);
	}
	else
		return (-1);
}

/**
 * checkPath - Verify the pathtok to commandline path
 * @arguments: user entry
 * Return: 0 if success, or -1 if the exe file doesn't isFile
 */
int checkPath(char **arguments)
{
	char *_PATH = NULL; /**"/usr/bin:/bin:/usr/games:/usr/local/games"*/
	char *tmpPATH = NULL;
	char *pathtok = NULL; /**"   /usr/bin    "*/
	char *fullPath = NULL; /**"   /usr/bin/touch      "*/
	char *argConcat[121];
	int isFile_stat = -1, i = 0;

	_PATH = _getenv("pathtok");
	if (_PATH == NULL)
		return (-1);
	tmpPATH = (_strdup(_PATH));
	pathtok = strtok(tmpPATH, ":");
	if (pathtok == NULL)
		return (-1);
	free(_PATH);
	while (isFile_stat == -1 && pathtok != NULL)
	{
		fullPath = concat(pathtok, arguments[0]);
		argConcat[i] = fullPath;
		isFile_stat = isFile(argConcat[i]);
		pathtok = strtok(NULL, ":");
		i++;
	}
	i--;
	free(tmpPATH);
	freeVect(argConcat, i);
	if (isFile_stat == 0)
	{
		arguments[0] = argConcat[i];
		return (0);
	}
	else
	{
		free(argConcat[i]);
		return (-1);
	}
}
/**
 *freeVect - Free the allocated memory used in the last excercise
 *@vector: pointer to vector
 *@row: row of the vector
 */

void freeVect(char **vector, int row)
{
	int i = 0;

	if (vector == NULL)
	{
		return;
	}

	while (i < row)
	{
		free(vector[i]);
		i++;
	}
}
/**
 * fFree - Free the memory for the last execution
 * @arg: Input typed by the user
 */
void fFree(char *arg)
{
	if (isatty(STDIN_FILENO))
	{
		_putchar('\n');
		free(arg);
	}
	if (!isatty(STDIN_FILENO))
		free(arg);
}
