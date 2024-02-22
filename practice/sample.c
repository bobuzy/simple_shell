#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    char command[100];

    printf("Custom Shell > ");

    while (fgets(command, sizeof(command), stdin) != NULL) {
        // Remove newline character
        command[strcspn(command, "\n")] = 0;

        // Exit if user enters "exit"
        if (strcmp(command, "exit") == 0) {
            break;
        }

        // Execute the command
        system(command);

        printf("Custom Shell > ");
    }

    return 0;
}
