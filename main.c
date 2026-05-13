#include "shell.h"

/**
 * main - entry point for the simple shell
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	(void)argc;

	while (1)
	{
		/* Display prompt only in interactive mode */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		nread = getline(&line, &len, stdin);

		/* Handle EOF (Ctrl+D) */
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			exit(EXIT_SUCCESS);
		}

		/* Remove newline character from input */
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		/* Only execute if the line is not empty */
		if (strlen(line) > 0)
			execute_cmd(line, argv[0]);
	}

	free(line);
	return (0);
}
