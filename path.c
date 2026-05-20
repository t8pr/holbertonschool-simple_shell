#include "shell.h"

/**
 * get_path - finds command in PATH
 * @command: command entered
 *
 * Return: full path or NULL
 */
char *get_path(char *command)
{
	char *path = NULL, *path_copy, *token, *full_path;
	int i;
	static char buffer[1024];

	if (strchr(command, '/'))
	{
		if (access(command, X_OK) == 0)
			return (command);
		return (NULL);
	}

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = environ[i] + 5;
			break;
		}
	}

	if (path == NULL)
		return (NULL);

	path_copy = strdup(path);
	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		sprintf(buffer, "%s/%s", token, command);
		if (access(buffer, X_OK) == 0)
		{
			free(path_copy);
			full_path = buffer;
			return (full_path);
		}
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
