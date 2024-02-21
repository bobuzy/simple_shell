#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	size_t n = 20;
	char *buffer = NULL;

	printf("Enter your Command ");
	getline(&buffer, &n, stdin);

	printf("Output: %s", buffer); // Automatically adds a new line
	printf("Buffer size is %ld\n", n);

	free(buffer);
	return (0);
}
