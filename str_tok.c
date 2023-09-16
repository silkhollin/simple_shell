#include "shell.h"

/**
 * token_len - Locates the delimiter index marking the end of the first token
 * @str: string being searched.
 * @del: delimiting character.
 *
 * Return: The delimiter index marking the end of
 *         the initial token pointed to be str.
 */
int token_len(char *str, char *del)
{
	int index = 0, sum = 0;

	while (*(str + index) && *(str + index) != *del)
	{
		sum++;
		index++;
	}

	return (sum);
}

/**
 * token_tot - Counts the number of words with delimeters in the string
 * @str: The string to be searched.
 * @del: The delimiting character.
 *
 * Return: The number of words contained within str.
 */
int token_tot(char *str, char *del)
{
	int index, tokens = 0, sum = 0;

	for (index = 0; *(str + index); index++)
		sum++;

	for (index = 0; index < len; index++)
	{
		if (*(str + index) != *del)
		{
			tokens++;
			index += token_len(str + index, delim);
		}
	}

	return (tokens);
}

/**
 * _strtok - Tokenizes(splits) a string into substrings
 * @line: The string being tokenised
 * @del: The delimiting character which indicates a slpitting point
 *
 * Return: pointer to an array containing the substrings/tokens
 */
char **_strtok(char *line, char *del)
{
	char **ptr;
	int index = 0, tokens, t, letters, l;

	tokens = token_tot(line, del);
	if (tokens == 0)
		return (NULL);

	ptr = malloc(sizeof(char *) * (tokens + 2));
	if (!ptr)
		return (NULL);

	for (t = 0; t < tokens; t++)
	{
		while (line[index] == *del)
			index++;

		letters = token_len(line + index, del);

		ptr[t] = malloc(sizeof(char) * (letters + 1));
		if (!ptr[t])
		{
			for (index -= 1; index >= 0; index--)
				free(ptr[index]);
			free(ptr);
			return (NULL);
		}

		for (l = 0; l < letters; l++)
		{
			ptr[t][l] = line[index];
			index++;
		}

		ptr[t][l] = '\0';
	}
	ptr[t] = NULL;
	ptr[t + 1] = NULL;

	return (ptr);
}
