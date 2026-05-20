#include "shell.h"

int shell_status = 0;

/**
 * parse_line - splits line into arguments
 * @line: command line
 * @argv: argument array
 */
void parse_line(char *line, char **argv)
{
	char *token;
	int i;

	token = strtok(line, " ");

	i = 0;

	while (token != NULL)
	{
		argv[i] = token;
		token = strtok(NULL, " ");
		i++;
	}

	argv[i] = NULL;
}

/**
 * handle_builtin - handles builtins
 * @argv: argument array
 * @line: input line
 */
void handle_builtin(char **argv, char *line)
{
	if (strcmp(argv[0], "exit") == 0)
	{
		free(line);
		exit(shell_status);
	}

	if (strcmp(argv[0], "env") == 0)
	{
		print_env();
	}
	else
	{
		execute_command(argv);
	}
}

/**
 * main - simple shell
 *
 * Return: shell status
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *argv[64];

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

		parse_line(line, argv);

		if (argv[0] != NULL)
			handle_builtin(argv, line);
	}

	free(line);

	return (shell_status);
}
