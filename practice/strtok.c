#include <string.h>
#include <stdio.h>

int main(void)
{
        char str[] = "Jesus    loves       me";
        char *delim = " ";
        char *token;

        token = strtok(str, delim);

        while (token != NULL)
        {
                printf("%s\n", token);
                token = strtok(NULL, delim);
        }

        printf("%s", str);

	return (0);
}
