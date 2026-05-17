#include "shell.h"

int shell_status = 0;

/**
 * main - simple shell
 * Return: shell status
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
			exit(shell_status);
		}

		if (line[0] == '\n')
			continue;

		line[strcspn(line, "\n")] = '\0';

		token = strtok(line, " ");

		i = 0;

		while (token != NULL)
		{
			argv[i] = token;
			token = strtok(NULL, " ");
			i++;
		}

		argv[i] = NULL;

		if (argv[0] != NULL)
		{
			if (strcmp(argv[0], "exit") == 0)
			{
				free(line);
				exit(shell_status);
			}

			if (strcmp(argv[0], "env") == 0)
			{
				print_env();
				continue;
			}

			execute_command(argv);
		}
	}

	free(line);

	return (shell_status);
}
