#include "shell.h"

/**
 * get_location - Locates a command in the PATH.
 * @cmd: The command to locate.
 * Return: NULL -  if errors occur or the command cannot be located
 *         Otherwise - the full pathname of the command.
 */
char *get_location(char *cmd)
{
	char **path, *temp;
	list_t *dirs, *head;
	struct stat st;

	path = _getenv("PATH");
	if (!path || !(*path))
		return (NULL);

	dirs = get_path_dir(*path + 5);
	head = dirs;

	while (dirs)
	{
		temp = malloc(_strlen(dirs->dir) + _strlen(cmd) + 2);
		if (!temp)
			return (NULL);

		_strcpy(temp, dirs->dir);
		_strcat(temp, "/");
		_strcat(temp, cmd);

		if (stat(temp, &st) == 0)
		{
			free_list(head);
			return (temp);
		}

		dirs = dirs->next;
		free(temp);
	}

	free_list(head);

	return (NULL);
}

/**
 * fill_path_dir - Copies path but also replaces leading/trailing colons (:)
 * @path: a normal path format with slashes and colons
 * Return: a path copy
 */
char *fill_path_dir(char *path)
{
	int i, length = 0;
	char *path_copy, *pwd;

	pwd = *(_getenv("PWD")) + 4;
	for (i = 0; path[i]; i++)
	{
		if (path[i] == ':')
		{
			if (path[i + 1] == ':' || i == 0 || path[i + 1] == '\0')
				length += _strlen(pwd) + 1;
			else
				length++;
		}
		else
			length++;
	}
	path_copy = malloc(sizeof(char) * (length + 1));
	if (!path_copy)
		return (NULL);
	path_copy[0] = '\0';
	for (i = 0; path[i]; i++)
	{
		if (path[i] == ':')
		{
			if (i == 0)
			{
				_strcat(path_copy, pwd);
				_strcat(path_copy, ":");
			} else if (path[i + 1] == ':' || path[i + 1] == '\0')
			{
				_strcat(path_copy, ":");
				_strcat(path_copy, pwd);
			} else
				_strcat(path_copy, ":");
		} else
		{
			_strncat(path_copy, &path[i], 1);
		}
	}
	return (path_copy);
}

/**
 * get_path_dir - Tokenizes a colon-separated list of directories int a list.
 * @path: colon formatted list of directories.
 *
 * Return: A pointer to the initialized linked list.
 */
list_t *get_path_dir(char *path)
{
	int index;
	char **dirs, *path_copy;
	list_t *head = NULL;

	path_copy = fill_path_dir(path);
	if (!path_copy)
		return (NULL);
	dirs = _strtok(path_copy, ":");
	free(path_copy);
	if (!dirs)
		return (NULL);

	for (index = 0; dirs[index]; index++)
	{
		if (add_node_end(&head, dirs[index]) == NULL)
		{
			free_list(head);
			free(dirs);
			return (NULL);
		}
	}

	free(dirs);

	return (head);
}
