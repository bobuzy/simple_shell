#include "main.h"

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

void my_exit(void)
{
	exit(EXIT_SUCCESS);
}
