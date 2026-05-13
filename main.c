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
		/* Display prompt only if input is from a terminal */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		nread = getline(&line, &len, stdin);

		/* Handle End of File (Ctrl+D) */
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			exit(EXIT_SUCCESS);
		}

		/* Remove newline character from the end of the input */
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		/* Process the command if it's not an empty string */
		if (strlen(line) > 0)
			execute_cmd(line, argv[0]);
	}

	free(line);
	return (0);
}
