#include "shell.h"

/**
 * get_path - finds command path
 * @command: command entered
 *
 * Return: full path or NULL
 */
char *get_path(char *command)
{
	char *path_env, *path_copy, *dir;
	char *full_path;
	static char buffer[1024];

	if (strchr(command, '/'))
	{
		if (access(command, X_OK) == 0)
			return (command);

		return (NULL);
	}

	path_env = getenv("PATH");

	if (path_env == NULL)
		return (NULL);

	path_copy = strdup(path_env);

	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		sprintf(buffer, "%s/%s", dir, command);

		if (access(buffer, X_OK) == 0)
		{
			free(path_copy);
			full_path = buffer;
			return (full_path);
		}

		dir = strtok(NULL, ":");
	}

	free(path_copy);

	return (NULL);
}
