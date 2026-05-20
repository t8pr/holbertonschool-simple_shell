#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
extern int shell_status;

char *get_path(char *command);
void execute_command(char **argv);
void print_env(void);
void process_command(char **argv, char *line);

#endif
