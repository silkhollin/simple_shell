#include "shell.h"

/**
 * error_126 - prints error messages for permission denied failures.
 * @args: array of arguments passed to the command.
 *
 * Return: String containing an error message
 */
char *error_126(char **args)
{
	char *error, *hist_str;
	int tot;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	tot = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 24;
	error = malloc(sizeof(char) * (tot + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": ");
	_strcat(error, args[0]);
	_strcat(error, ": Permission denied\n");

	free(hist_str);
	return (error);
}

/**
 * error_127 - prints an error message incase command cant be found
 * @args: array of arguments passed to the command.
 *
 * Return: string containing error message
 */
char *error_127(char **args)
{
	char *error, *hist_str;
	int tot;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	tot = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 16;
	error = malloc(sizeof(char) * (tot + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": ");
	_strcat(error, args[0]);
	_strcat(error, ": not found\n");

	free(hist_str);
	return (error);
}
