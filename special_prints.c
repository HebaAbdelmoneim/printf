#include "main.h"

/**
 * print_part - print part of the parameters
 * @bg: starting address
 * @end: ending address
 * @exclude: char address that won't be printed
 *
 * Return: the numbers of printed char
 */
int print_part(char *bg, char *end, char *exclude)
{
	int ch_num = 0;

	while (bg <= end)
	{
		if (bg != exclude)
			ch_num += _putchar(*bg);
		bg++;
	}
	return (ch_num);
}

/**
 * print_unsigned - print unsigned integer numbers
 * @pa: the parameters list
 * @fl: flags struct
 *
 * Return: the numbers of printed char
 */
int print_unsigned(va_list pa, flag_ty *fl)
{
	unsigned long u;

	if (fl->long_mod)
		u = (unsigned long)va_arg(pa, unsigned long);
	else if (fl->short_mod)
		u = (unsigned short int)va_arg(pa, unsigned int);
	else
		u = (unsigned int)va_arg(pa, unsigned int);
	fl->unsign = 1;
	return (print_num(_itoa(u, 10, CONV_UNSIG), fl));
}

/**
 * print_address - print address
 * @pa: the parameters list
 * @fl: flags struct
 *
 * Return: the numbers of printed char
 */
int print_address(va_list pa, flag_ty *fl)
{
	unsigned long int p;
	char *str;

	p = va_arg(pa, unsigned long int);
	if (!p)
		return (_putstr("(nil)"));

	str = _itoa(p, 16, CONV_UNSIG | CONV_LC);
	*--str = 'x';
	*--str = '0';
	return (print_num(str, fl));
}

/**
 * print_rev - print reversed string
 * @pa: the parameters list
 * @fl: flags struct
 *
 * Return: the numbers of printed char
 */
int print_rev(va_list pa, __attribute__((unused)) flag_ty *fl)
{
	int len, ch_num = 0;
	char *str = va_arg(pa, char *);

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
		{
			ch_num += _putchar(*str);
		}
	}
	return (ch_num);
}

/**
 * print_rot13 - print string in rot13
 * @pa: the parameters list
 * @fl: flags struct
 *
 * Return: the numbers of printed char
 */
int print_rot13(va_list pa, __attribute__((unused)) flag_ty *fl)
{
	int i = 0, index = 0, ch_num = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *str = va_arg(pa, char *);

	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{
			index = str[i] - 65;
			ch_num += _putchar(arr[index]);
		}
		else
		{
			ch_num += _putchar(str[i]);
		}
		i++;
	}
	return (ch_num);
}

