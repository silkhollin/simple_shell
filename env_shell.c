#include "shell.h"

/**
 * _copyenv - clones the environment variables.
 *
 * Return: A double pointer to the new copy.or NULL - for an error occurs
 */
char **_copyenv(void)
{
	char **new_environ;
	size_t size;
	int index;

	for (size = 0; environ[size]; size++)
		;

	new_environ = malloc(sizeof(char *) * (size + 1));
	if (!new_environ)
		return (NULL);

	for (index = 0; environ[index]; index++)
	{
		new_environ[index] = malloc(_strlen(environ[index]) + 1);

		if (!new_environ[index])
		{
			for (index--; index >= 0; index--)
				free(new_environ[index]);
			free(new_environ);
			return (NULL);
		}
		_strcpy(new_environ[index], environ[index]);
	}
	new_environ[index] = NULL;

	return (new_environ);
}

/**
 * free_env - frees the environment replica
 */
void free_env(void)
{
	int dex;

	for (dex = 0; environ[dex]; dex++)
		free(environ[dex]);
	free(environ);
}

/**
 * _getenv - Gets an environmental variable from the PATH.
 * @var: The name of the variable to get.
 *
 * Return: a pointer to the environmental variable. NULL - if it doesnt exist
 */
char **_getenv(const char *var)
{
	int dex, sum;

	sum = _strlen(var);
	for (dex = 0; environ[dex]; dex++)
	{
		if (_strncmp(var, environ[dex], sum) == 0)
			return (&environ[dex]);
	}

	return (NULL);
}
