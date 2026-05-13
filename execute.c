#include "shell.h"

/**
 * execute_cmd - Creates a child process to execute a command
 * @command: The string containing the command path
 * @prog_name: The name of the shell (argv[0]) for error messages
 * @line: The allocated buffer from getline to free on error
 */
void execute_cmd(char *command, char *prog_name, char *line)
{
	pid_t pid;
	int status;
	char *args[2];

	/* Task 2: Only one word, no arguments */
	args[0] = command;
	args[1] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0) /* Child process */
	{
		if (execve(command, args, environ) == -1)
		{
			perror(prog_name);
			free(line); /* CRITICAL: Prevent memory leak in child */
			exit(EXIT_FAILURE);
		}
	}
	else /* Parent process */
	{
		wait(&status);
	}
}
