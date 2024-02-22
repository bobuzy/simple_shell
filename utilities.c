#include "main.h"

/**
 * _strlen - Counts the lenght of a string
 * @s: The pointer to the string
 *
 * Return: The lenght of the string
 */

int _strlen(char *s)
{
	int n = 0;

	while (*s++)
	{
		n++;
	}

	return (n);
}


/**
 * print_out - Print a string into standard output
 * @str: The pointer to the string to be printed
 *
 * Return: Nothing
 */

void print_out(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}

/**
 * display_prompt - Display the $ prompt
 *
 * Return: Nothing
 */

void display_prompt(void)
{
	print_out("$ ");
}
