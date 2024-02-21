#include <stdio.h>
#include <stddef.h>

int main(int ac, char **av)
{
	int i = 0;

	while (av[i] != NULL)
	{
		printf("%s", av[i]);

		if (av[i + 1] != NULL)
		{
			printf(" ");
		}
		i++;
	}

	printf("\n");
	return (0);
}
