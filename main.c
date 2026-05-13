#include "shell.h"

/**
 * main - Entry point for the simple shell
 *
 * Return: 0 on success
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		/* Only display prompt if we are in a terminal */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

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

		/* Ignore empty lines */
		if (strlen(line) > 0)
		{
			/* For now, this just prints what you typed */
			/* In the next task, we will add execution logic */
			printf("%s\n", line);
		}
	}

	free(line);
	return (0);
}