#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int _strlen(char *s);
void print_out(char *str);
void display_prompt(void);
void read_input(void);
void execute_command(char *buffer);


int main(void)
{
	while(1)
	{
		read_input();

		if (!isatty(fileno(stdin)))
		{
			break;
		}
	}
	return (0);
}

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

void execute_command(char *buffer)
{
	char *envp[] = {(char *) "PATH=/bin", NULL};
	
	char *token = strtok(buffer, " \n");
	
	if (token == NULL)
	{
		return;
	}

    char *argv[20];
    int argc = 0;

    while (token != NULL)
    {
	argv[argc++] = token;
	token = strtok(NULL, " \n");
    }

    argv[argc] = NULL;

    pid_t pid = fork();
    if (pid == -1)
    {
	perror("Fork Unsuccessful");
    }
    else if (pid == 0)
    {
	int val = execve(argv[0], argv, envp);
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



int _strlen(char *s)
{
	int n = 0;

	while (*s++)
	{
		n++;
	}

	return (n);
}


void print_out(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}


void display_prompt(void)
{
	print_out("$ ");
}
