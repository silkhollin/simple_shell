#include "shell.h"

/**
 * error_env - returns an error messgae fora shell command
 * @args: array of arguments passed to the command.
 *
 * Return: a string containign the erro messgae
 */
char *error_env(char **args)
{
	char *error, *hist_str;
	int tot;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	args--;
	tot = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 45;
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
	_strcat(error, ": Unable to add/remove from environment\n");

	free(hist_str);
	return (error);
}

/**
 * error_1 - Creates an error message for for alias errors.
 * @args: array of arguments passed to the command.
 *
 * Return:strimg with error message
 */
char *error_1(char **args)
{
	char *erra;
	int len;

	len = _strlen(name) + _strlen(args[0]) + 13;
	erra = malloc(sizeof(char) * (len + 1));
	if (!erra)
		return (NULL);

	_strcpy(erra, "alias: ");
	_strcat(erra, args[0]);
	_strcat(erra, " not found\n");

	return (erra);
}

/**
 * error_2_exit - Creates an error message for shell exit errors.
 * @args: array of arguments passed to the command.
 *
 * Return: string containgi error messages
 */
char *error_2_exit(char **args)
{
	char *error, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 27;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": exit: Illegal number: ");
	_strcat(error, args[0]);
	_strcat(error, "\n");

	free(hist_str);
	return (error);
}

/**
 * error_2_cd - Creates an error message for shell directroy action errors.
 * @args: An array of arguments passed to the command.
 *
 * Return: string containing the error mesage
 */
char *error_2_cd(char **args)
{
	char *error, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	if (args[0][0] == '-')
		args[0][2] = '\0';
	len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 24;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	if (args[0][0] == '-')
		_strcat(error, ": cd: Illegal option ");
	else
		_strcat(error, ": cd: can't cd to ");
	_strcat(error, args[0]);
	_strcat(error, "\n");

	free(hist_str);
	return (error);
}

/**
 * error_2_syntax - Creates an error message for syntax errors.
 * @args: An array of arguments passed to the command.
 *
 * Return: string containing error messages
 */
char *error_2_syntax(char **args)
{
	char *error, *hist_str;
	int tot;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	tot = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 33;
	error = malloc(sizeof(char) * (tot + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": Syntax error: \"");
	_strcat(error, args[0]);
	_strcat(error, "\" unexpected\n");

	free(hist_str);
	return (error);
}
