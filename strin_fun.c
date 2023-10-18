#include "header.h"
/**
 * _strcmp - string comparison
 * @str1: String1
 * @str2: String2
 * Return: 0 if are the same, > 0 if str1 is greater, < 0 if str2 is greater
 */
int _strcmp(char *str1, char *str2)
{
	int idx;

	for (idx = 0; str1[idx] != '\0'; idx++)
		;
	for (idx = 0; str2[idx] != '\0'; idx++)
	{
		if (str1[idx] != str2[idx])
		{
			return (str1[idx] - str2[idx]);
		}
	}
	return (0);
}
/**
 * _strdup - Duplicates a string
 * @str: String to be duplicated
 * Return: Pointer to new String
 */
char *_strdup(char *str)
{
	unsigned int i, len;
	char *dup;

	if (str == NULL)
		return (NULL);

	for (len = 0; str[len] != '\0'; len++)
		;
	dup = (char *) malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
	{
		dup[i] = str[i];
	}
	return (dup);
}
/**
 * _strlen - Sizes the length of a string
 * @string: String to be sized
 * Return: The length ot the string
 */
	int _strlen(const char *string)
	{
		int len = 0;

		if (string == NULL)
			return (0);

		while (string[len] != '\0')
			len++;
		return (len);
	}
