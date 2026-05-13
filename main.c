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
	size_t len = 0;
	ssize_t nread;
	(void)argc;

	while (1)
	{
		/* Display standard prompt if in interactive mode */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		nread = getline(&line, &len, stdin);

		/* Handle Ctrl+D / EOF */
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

		/* Execute only if the command is not empty */
		if (line[0] != '\0')
			execute_cmd(line, argv[0], line);
	}

	free(line);
	return (0);
}
