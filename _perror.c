#include "header.h"
/**
 * _perror - Prints error message when a command is not found
 * @arguments: array of args typed by the user
 * @counter: Times that the shell has been executed
 * Return: Exit status
 */
int _perror(char **arguments, int counter)
{
	char *imode_shell_name = "hsh";
	char *non_i_mode_shell_name = "./hsh";

	if (isatty(STDIN_FILENO))
		write(2, imode_shell_name, 3);
	else
	{
		write(2, non_i_mode_shell_name, 5);
	}
	write(2, ": ", 2);
	printNums(counter);
	write(2, ": ", 2);
	write(2, arguments[0], _strlen(arguments[0]));
	write(2, ": not found\n", 12);
	return (127);
}
/**
 * printNums - Prints numbers, used to print the error message
 * @n: number to print
 * Return: Number
 */

int printNums(int n)
{
	unsigned int number;
	int i = 0;

	if (n < 0)
	{
		number = -n;
		i = i + _putchar('-');
	}
	else
	{
		number = n;
	}
	if (number / 10 != '\0')
		i = i + printNums(number / 10);
	i = i + _putchar(number % 10 + '0');
	return (i);
}
