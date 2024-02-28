#include "main.h"

/**
 * read_input - Read the command input from stdin
 *
 * Return: Nothing
 */

void read_input(void)
{
	size_t len;
	char *buffer = NULL;
	int char_read;

	if (isatty(fileno(stdin)))
	{
		display_prompt();
	}

	char_read = getline(&buffer, &len, stdin);

	if (char_read == -1)
	{
		if (feof(stdin))
		{
			print_out("\n");
			exit(EXIT_SUCCESS);
		}
		perror("getline failed");
		free(buffer);
		exit(EXIT_FAILURE);
	}

	if (char_read == 1 && buffer[0] == '\n')
	{
		free(buffer);
		return;
	}

	execute_command(buffer);

	free(buffer);
}


/**
 * execute_command - Execute command from buffer
 * @buffer: The sring of arguments to be executed
 *
 * Return: Nothing
 */

void execute_command(char *buffer)
{
	pid_t pid;
	char *argv[20];
	int argc = 0;

	char *token = strtok(buffer, " \n");

	if (token == NULL)
	{
		return;
	}

	while (token != NULL)
	{
		argv[argc++] = token;
		token = strtok(NULL, " \n");
	}

	argv[argc] = NULL;

	pid = fork();

	if (pid == -1)
	{
		perror("Fork Unsuccessful");
	}
	else if (pid == 0)
	{
		int val = execve(argv[0], argv, NULL);

		if (val == -1)
		{
			perror("Error");
		}
	}
	else
	{
		wait(NULL);
	}
}
