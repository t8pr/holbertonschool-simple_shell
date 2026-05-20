#include "shell.h"

int shell_status = 0;

/**
 * process_command - handles builtins and execution
 * @argv: parsed arguments
 * @line: input line (for freeing on exit)
 *
 * Return: void
 */
void process_command(char **argv, char *line)
{
	if (argv[0] == NULL)
		return;

	if (strcmp(argv[0], "exit") == 0)
	{
		free(line);
		exit(shell_status);
	}

	if (strcmp(argv[0], "env") == 0)
	{
		print_env();
		return;
	}

	execute_command(argv);
}

/**
 * main - simple shell
 *
 * Return: shell status
 */
int main(void)
{
	char *line = NULL, *token, *argv[64];
	size_t len = 0;
	ssize_t read;
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

		for (i = 0; token != NULL; i++)
		{
			argv[i] = token;
			token = strtok(NULL, " ");
		}
		argv[i] = NULL;

		process_command(argv, line);
	}

	free(line);
	return (shell_status);
}
