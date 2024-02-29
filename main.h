#ifndef HEADER_FILE
#define HEADER_FILE

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <limits.h>
#include <stddef.h>

extern char **environ;

void print_out(char *str);
void display_prompt(void);
void read_input(void);
void execute_command(char command[], char *argv[]);
void tokenize_command(char *buffer);
void my_exit(void);

#endif
