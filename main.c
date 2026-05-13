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
	char *args[64];
	int i;
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

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		i = 0;
		args[i] = strtok(line, " \n\t\r");
		while (args[i] != NULL)
		{
			i++;
			args[i] = strtok(NULL, " \n\t\r");
		}

		if (args[0] != NULL)
		{
			execute_cmd(args, argv[0], line);
		}
	}

	free(line);
	return (0);
}
