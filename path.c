#include "shell.h"

/**
 * check_path - checks direct path
 * @command: command entered
 *
 * Return: command or NULL
 */
char *check_path(char *command)
{
	if (strchr(command, '/'))
	{
		if (access(command, X_OK) == 0)
			return (command);
	}

	return (NULL);
}

/**
 * find_in_path - searches PATH
 * @path_copy: copied PATH
 * @command: command entered
 *
 * Return: full path or NULL
 */
char *find_in_path(char *path_copy, char *command)
{
	char *token;
	static char full_path[1024];

	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		sprintf(full_path, "%s/%s", token, command);

		if (access(full_path, X_OK) == 0)
			return (full_path);

		token = strtok(NULL, ":");
	}

	return (NULL);
}

/**
 * get_env_path - gets PATH variable
 *
 * Return: PATH value
 */
char *get_env_path(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			return (environ[i] + 5);
	}

	return (NULL);
}

/**
 * get_path - finds command in PATH
 * @command: command entered
 *
 * Return: full path or NULL
 */
char *get_path(char *command)
{
	char *path;
	char *path_copy;
	char *full_path;

	full_path = check_path(command);

	if (full_path != NULL)
		return (full_path);

	path = get_env_path();

	if (path == NULL)
		return (NULL);

	path_copy = strdup(path);

	full_path = find_in_path(path_copy, command);

	free(path_copy);

	return (full_path);
}
