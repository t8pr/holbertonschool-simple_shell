#include "shell.h"

/**
 * execute_cmd - creates a child process to execute a command
 * @command: the full path of the command
 * @prog_name: name of the shell (argv[0]) for error reporting
 */
void execute_cmd(char *command, char *prog_name)
{
	pid_t pid;
	int status;
	char *args[2];

	/* Task 2 only requires handling one word (no arguments) */
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
		/* Pass command, args, and global environ to execve */
		if (execve(command, args, environ) == -1)
		{
			perror(prog_name);
			exit(EXIT_FAILURE);
		}
	}
	else /* Parent process */
	{
		wait(&status);
	}
}
