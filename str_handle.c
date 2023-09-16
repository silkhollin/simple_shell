#include "shell.h"

/**
 * _strcpy - copies a string to a buffer.
 * @fn: pointer adddress to destination
 * @src: Pointer to the src of the source string.
 *
 * Return: fn pointer
 */
char *_strcpy(char *fn, const char *src)
{
	size_t kk;

	for (kk = 0; src[kk] != '\0'; kk++)
		fn[kk] = src[kk];
	fn[kk] = '\0';
	return (fn);
}

/**
 * _strcat - merges two strings.
 * @fn: Pointer to final str
 * @src: Pointer to source string.
 *
 * Return: Pointer to merged string.
 */
char *_strcat(char *fn, const char *src)
{
	char *fnTemp;
	const char *srcTemp;

	fnTemp = fn;
	srcTemp =  src;

	while (*fnTemp != '\0')
		fnTemp++;

	while (*srcTemp != '\0')
		*fnTemp++ = *srcTemp++;
	*fnTemp = '\0';
	return (fn);
}

/**
 * _strncat - Concatenates two strings specifying nb bytes to be copied from
 * sourec string
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 * @nb:  number of bytes to copy from src.
 *
 * Return: Pointer to destination string.
 */
char *_strncat(char *dest, const char *src, size_t nb)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0; i < nb && src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}

/**
 * _strlen - Returns the length of a string.
 * @st: pointer to string whose lenght is being calculated
 *
 * Return:string length
 */
int _strlen(const char *st)
{
	int len = 0;

	if (!st)
		return (len);
	for (len = 0; st[len]; len++)
		;
	return (len);
}
