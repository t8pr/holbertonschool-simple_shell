#include "shell.h"

/**
 * execute_command - executes commands
 * @argv: command arguments
 */
void execute_command(char **argv)
{
	pid_t pid;
	char *path;

	path = get_path(argv[0]);

	if (path == NULL)
	{
		perror("./hsh");
		return;
	}

	pid = fork();

	if (pid == 0)
	{
		if (execve(path, argv, environ) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);
}
