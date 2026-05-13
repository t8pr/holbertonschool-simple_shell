#include "shell.h"

/**
 * main - simple shell
 * Return: 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *token;
	char *argv[64];
	int i;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("($) ");

		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			free(line);
			exit(0);
		}

		if (line[0] == '\n')
			continue;

		line[strcspn(line, "\n")] = '\0';

		token = strtok(line, " ");

		i = 0;

		while (token != NULL)
		{
			argv[i++] = token;
			token = strtok(NULL, " ");
		}

		argv[i] = NULL;

		if (argv[0] != NULL)
			execute_command(argv);
	}

	free(line);

	return (0);
}
