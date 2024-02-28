#include "main.h"

/**
 * main - The main entry to the simple shell function
 *
 * Return: 0, if successful
 */

int main(void)
{
	while (1)
	{
		read_input();

		if (!isatty(fileno(stdin)))
		{
			break;
		}
	}
	return (0);
}
