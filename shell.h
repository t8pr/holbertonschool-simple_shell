#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Global environment variable */
extern char **environ;

/* Function prototype */
void execute_cmd(char **args, char *prog_name, char *line);
char *get_path(char *command);
void execute_command(char **argv);

#endif /* SHELL_H */
