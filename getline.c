#include "shell.h"

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptnr: pointer to the memory previously allocated.
 * @old_sb: size in bytes
 * @new_sb: size in bytes for the new block
 *
 * Return: If new_sb == old_sb - ptnr.
 *         If new_sb == 0 and ptnr is not NULL - NULL.
 *         Otherwise - a pointer to the reallocated memory block.
 */
void *_realloc(void *ptnr, unsigned int old_sb, unsigned int new_sb)
{
	void *mem;
	char *ptr_copy, *filler;
	unsigned int index;

	if (new_sb == old_sb)
		return (ptnr);

	if (ptnr == NULL)
	{
		mem = malloc(new_sb);
		if (mem == NULL)
			return (NULL);

		return (mem);
	}

	if (new_sb == 0 && ptnr != NULL)
	{
		free(ptnr);
		return (NULL);
	}

	ptr_copy = ptnr;
	mem = malloc(sizeof(*ptr_copy) * new_sb);
	if (mem == NULL)
	{
		free(ptnr);
		return (NULL);
	}

	filler = mem;

	for (index = 0; index < old_sb && index < new_sb; index++)
		filler[index] = *ptr_copy++;

	free(ptnr);
	return (mem);
}

/**
 * assign_lineptr - Reassigns the lineptr variable for _getline.
 * @lineptr: A buffer to store an input string.
 * @ns: size of lineptr.
 * @buff: The string to assign to lineptr.
 * @nb: The size of buffer.
 */
void assign_lineptr(char **lineptr, size_t *ns, char *buff, size_t nb)
{
	if (*lineptr == NULL)
	{
		if (nb > 120)
			*ns = nb;
		else
			*ns = 120;
		*lineptr = buff;
	}
	else if (*ns < nb)
	{
		if (nb > 120)
			*ns = nb;
		else
			*ns = 120;
		*lineptr = buff;
	}
	else
	{
		_strcpy(*lineptr, buff);
		free(buff);
	}
}

/**
 * _getline - Reads input from a stream.
 * @lineptr: buffer to store the input.
 * @nb: size of lineptr.
 * @stream: The stream to read from.
 * Return: The number of bytes read.
 */
ssize_t _getline(char **lineptr, size_t *nb, FILE *stream)
{
	static ssize_t input;
	ssize_t rev;
	char c = 'x', *buff;
	int r;

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;
	buff = malloc(sizeof(char) * 120);
	if (!buff)
		return (-1);
	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && input == 0))
		{
			free(buff);
			return (-1);
		}
		if (r == 0 && input != 0)
		{
			input++;
			break;
		}

		if (input >= 120)
			buff = _realloc(buff, input, input + 1);

		buff[input] = c;
		input++;
	}
	buff[input] = '\0';

	assign_lineptr(lineptr, nb, buff, input);
	rev = input;
	if (r != 0)
		input = 0;
	return (rev);
}

