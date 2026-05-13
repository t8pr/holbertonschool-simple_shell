#include "shell.h"

/**
 * execute_cmd - Creates a child process to execute a command
 * @args: Array of strings containing the command and its arguments
 * @prog_name: The name of the shell (argv[0]) for error messages
 * @line: The allocated buffer from getline to free on error
 */
void execute_cmd(char **args, char *prog_name, char *line)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(prog_name);
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}