#include "terminal.h"
/**
 * is_interactive - returns true if terminal is is_interactive mode
 * @data: struct address
 *
 * Return: 1 if is_interactive mode, 0 otherwise
 */
int is_interactive(data_t *data)
{
	return (isatty(STDIN_FILENO) && data->readfd <= 2);
}
/**
 * is_separator - checks if character is a delimeter
 * @c: the char to check
 * @separator: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_separator(char c, char *separator)
{
	while (*separator)
		if (*separator++ == c)
			return (1);
	return (0);
}
/**
 *_isalpha - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 *str_to_int - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */
int str_to_int(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -result;
	else
		output = result;
	return (output);
}
