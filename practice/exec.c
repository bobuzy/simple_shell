#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
	char *argv[] = {"/bin/ls", "-la", NULL};

	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("Fork Unsuccessful");
	}

	if (pid == 0)
	{
		int val = execve(argv[0], argv, NULL);

		if (val == -1)
		{
			perror("Error\n");
		}
	}
	else
	{
		wait(NULL);
		printf("Execve successful\n");
	}

	return (0);
}
