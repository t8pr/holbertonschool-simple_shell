#include "shell.h"

/**
 * main - Entry point for the simple shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	char *command = NULL;
	size_t len = 0;
	ssize_t nread;
	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			exit(EXIT_SUCCESS);
		}

		command = strtok(line, " \n\t\r");

		if (command != NULL)
		{
			execute_cmd(command, argv[0], line);
		}
	}

	free(line);
	return (0);
}
