#include "shell.h"

/**
 * execute_cmd - Creates a child process to execute a command
 * @command: The string containing the command path
 * @prog_name: The name of the shell (argv[0]) for error messages
 */
void execute_cmd(char *command, char *prog_name)
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
		/* Execute command with current environment */
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
