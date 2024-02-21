#include <stdio.h>
#include <unistd.h> // For getpid() and getppid()

int main(void)
{
	pid_t pid, ppid;

	pid = getpid();
	ppid = getppid();

	printf("PID = %u\nPPID = %u\n", pid, ppid);
	return (0);
}
