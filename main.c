#include "main.h"

/**
 * main - The main entry to the simple shell function
 *
 * Return: 0, if successful
 */

int main(void)
{
	int char_read;
	size_t len;
	char *buffer = NULL;

	while (1)
	{
		display_prompt();
		char_read = getline(&buffer, &len, stdin);

		if (char_read == -1)
		{
			perror("getline failed");
			exit(EXIT_FAILURE);
		}

		if (buffer == NULL)
		{
			print_out("\n");
		}

	}
	return (0);
}
