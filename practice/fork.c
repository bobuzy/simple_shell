#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t n;

	printf("Before fork was called\n");

	n = fork();

	if (n < 0)
	{
		perror("Fork unsuccessful\n");
		return (1);
	}
	else if (n > 0)
	{
		printf("Parent process\n");
	}
	else
	{
		printf("Child process\n");
	}

	return (0);
}
