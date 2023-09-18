#include "shell.h"

/**
 * num_len - Calculates the lenght of a number
 * @numb: The number to measure.
 * Return: number lenght
 */
int num_len(int numb)
{
	unsigned int num1;
	int len = 1;

	if (numb < 0)
	{
		len++;
		num1 = numb * -1;
	}
	else
	{
		num1 = numb;
	}
	while (num1 > 9)
	{
		len++;
		num1 /= 10;
	}

	return (len);
}

/**
 * _itoa - Converts an integer to a string.
 * @numb: The integer to conbert
 *
 * Return: The converted string.
 */
char *_itoa(int numb)
{
	char *buff;
	int len = num_len(numb);
	unsigned int num1;

	buff = malloc(sizeof(char) * (len + 1));
	if (!buff)
		return (NULL);

	buff[len] = '\0';

	if (numb < 0)
	{
		num1 = numb * -1;
		buff[0] = '-';
	}
	else
	{
		num1 = numb;
	}

	len--;
	do {
		buff[len] = (num1 % 10) + '0';
		num1 /= 10;
		len--;
	} while (num1 > 0);

	return (buff);
}


/**
 * create_error - Writes an error message to stderr.
 * @args: An array of arguments.
 * @err: The error value.
 *
 * Return: The error value.
 */
int create_error(char **args, int err)
{
	char *error;

	switch (err)
	{
	case -1:
		error = error_env(args);
		break;
	case 1:
		error = error_1(args);
		break;
	case 2:
		if (*(args[0]) == 'e')
			error = error_2_exit(++args);
		else if (args[0][0] == ';' || args[0][0] == '&' || args[0][0] == '|')
			error = error_2_syntax(args);
		else
			error = error_2_cd(args);
		break;
	case 126:
		error = error_126(args);
		break;
	case 127:
		error = error_127(args);
		break;
	}
	write(STDERR_FILENO, error, _strlen(error));

	if (error)
		free(error);
	return (err);
}
