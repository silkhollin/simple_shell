#include "shell.h"

/**
 * _strchr - id's a character in a string.
 * @st: The string to be searched.
 * @c: The character to find
 *
 * Return: If c is found - a pointer to its initial location.
 *         If c is not found - NULL.
 */
char *_strchr(char *st, char c)
{
	int ind;

	for (ind = 0; st[ind]; ind++)
	{
		if (st[ind] == c)
			return (st + ind);
	}

	return (NULL);
}

/**
 * _strspn - Gets the length of a prefix substring.
 * @s: The string to be searched.
 * @accept: The prefix to be measured.
 *
 * Return: The number of bytes in s which
 *         consist only of bytes from accept.
 */
int _strspn(char *s, char *accept)
{
	int bytes = 0;
	int index;

	while (*s)
	{
		for (index = 0; accept[index]; index++)
		{
			if (*s == accept[index])
			{
				bytes++;
				break;
			}
		}
		s++;
	}
	return (bytes);
}

/**
 * _strncmp - Compare two strings with a specific number of bytes to match.
 * @sf: Pointer to a string.
 * @s2: Pointer to a string.
 * @nb: The first bytes of the strings to compare.
 *
 * Return: Less than 0 if sf is shorter than s2.
 *         0 if sf and s2 match.
 *         Greater than 0 if sf is longer than s2.
 */
int _strncmp(const char *sf, const char *s2, size_t nb)
{
	size_t i;

	for (i = 0; sf[i] && s2[i] && i < nb; i++)
	{
		if (sf[i] > s2[i])
			return (sf[i] - s2[i]);
		else if (sf[i] < s2[i])
			return (sf[i] - s2[i]);
	}
	if (i == nb)
		return (0);
	else
		return (-15);
}

/**
 * _strcmp - Compares two strings ignoring the number of bytes.
 * @s1: first string to be compared.
 * @s2: second string to be compared.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 = s2
 *         Negative byte difference if s1 < s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}
