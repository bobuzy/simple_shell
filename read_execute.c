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
			free(buffer);
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

	tokenize_command(buffer);

	free(buffer);
}


/**
 * tokenize_command - Tokenize the command
 * @buffer: The input command to be tokenized
 *
 * Return: Nothing
 */

void tokenize_command(char *buffer)
{
	int argc = 0;
	char command[PATH_MAX];
	char *token, *path, *path_copy, *path_dir, *argv[20];

	token = strtok(buffer, " \n");
	while (token != NULL && argc < 20)
	{
		argv[argc++] = token;
		token = strtok(NULL, " \n");
	}
	argv[argc] = NULL;

	if (strchr(argv[0], '/') == NULL)
	{
		path = getenv("PATH");
		path_copy = strdup(path);
		path_dir = strtok(path_copy, ":");

		while (path_dir != NULL)
		{
			strcpy(command, "");
			snprintf(command, sizeof(command), "%s/%s", path_dir, argv[0]);

			if (access(command, X_OK) == 0)
			{
				execute_command(command, argv);
				free(path_copy);
				return;
			}
			path_dir = strtok(NULL, ":");
		}
		write(STDERR_FILENO, argv[0], strlen(argv[0]));
		write(STDERR_FILENO, ": command not found\n", 20);
		free(path_copy);
	}
	else
	{
		command = argv[0];
		execute_command(command, argv);
	}
}


/**
 * execute_command - Execute command from buffer
 * @command: An array of the command to be executed
 * @argv: The array of the list of the arguments tp be executed
 *
 * Return: Nothing
 */

void execute_command(char command[], char *argv[])
{
	int val;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork Unsuccessful");
	}
	else if (pid == 0)
	{
		val = execve(command, argv, environ);
		if (val == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
