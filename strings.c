#include "shell.h"
/**
 * _strcmp - Compare two strings.
 *
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
int _strcmp(char *s1, char *s2)
{
	int a, b, d, e;

	a = 0;
	b = 0;
	d = 0;
	while (s1[a] != '\0' || s2[a] != '\0')
	{
		b = b + s1[a];
		d = d + s2[a];
		a++;
		if (b != d)
			break;
	}
	e = b - d;
	return (e);
}
/**
 * _strcpy - Copy a string.
 *
 * @dest: Destination buffer.
 * @src: Source string.
 *
 * Return: A pointer to the destination buffer.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcat - Concatenate two strings.
 *
 * @dest: Destination string.
 * @src: Source string.
 *
 * Return: A pointer to the destination string.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
char *_strcat(char *dest, char *src)
{
	size_t a, b;

	a = 0;
	while (*(dest + a) != '\0')
	{
		a++;
	}
	b = 0;
	while (*(src + b) != '\0')
	{
		*(dest + (a + b)) = *(src + b);
		b++;
	}
	*(dest + (a + b)) = '\0';
	return (dest);
}
/**
 * _strlen - Calculate the length of a string.
 *
 * @s: Input string.
 *
 * Return: Length of the string.
 *
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
int _strlen(char *s)
{
	int b;

	for (b = 0; s[b] != '\0'; b++)
	;
	return (b);
}
