/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:55:30 by swarner           #+#    #+#             */
/*   Updated: 2019/06/27 16:55:32 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *get_u(va_list *args, t_arginfo *info)
{
	char 	*string;

	if (info->size[0] == 'h')
	{
		if (info->size[1] == 'h')
			string = ft_itoa_base((unsigned char)va_arg(*args, int), 10);
		else
			string = ft_itoa_base((unsigned short int)va_arg(*args, int), 10);
	}
	else
		string = ft_itoa_base(va_arg(*args, unsigned int), 10);
	return (string);
}

static char *get_x(va_list *args, t_arginfo *info, size_t base)
{
	char 	*string;

	if (info->size[0] == 'h')
	{
		if (info->size[1] == 'h')
			string = ft_itoa_base((unsigned char)va_arg(*args, int), base);
		else
			string = ft_itoa_base((unsigned short int)va_arg(*args, int), base);
	}
	else if (info->size[0] == 'l')
	{
		if (info->size[1] == 'l')
			string = ft_itoa_base(va_arg(*args, unsigned long long int), base);
		else
			string = ft_itoa_base(va_arg(*args, unsigned long int), base);
	}
	else
		string = ft_itoa_base(va_arg(*args, unsigned int), base);
	return (string);
}

static char *get_i(va_list *args, t_arginfo *info)
{
	char 	*string;

	if (info->size[0] == 'h')
	{
		if (info->size[1] == 'h')
			string = ft_itoa((signed char)va_arg(*args, int));
		else
			string = ft_itoa((short int)va_arg(*args, int));
	}
	else if (info->size[0] == 'l')
	{
		if (info->size[1] == 'l')
			string = ft_unsigned_itoa(va_arg(*args, unsigned long long int));
		else
			string = ft_unsigned_itoa(va_arg(*args, unsigned long int));
	}
	else
		string = ft_itoa(va_arg(*args, int));
	return (string);
}

static char *get_c(va_list *args, t_arginfo *info)
{
	char	*for_char;

	if (info->type == '%')
	{
		for_char = ft_strnew(1);
		for_char[0] = '%';
		return (for_char);
	}
	else if (info->type == 'c')
	{
		for_char = ft_strnew(1);
		for_char[0] = va_arg(*args, int);
		return (for_char);
	}
	return ("\0");
}

char		*get_arg(t_arginfo *info, va_list *args)
{
	char	*string;

    string = NULL;
    if (info->type == 's')
        string = va_arg(*args, char *);
    else if (info->type == 'c' || info->type == '%')
        string = get_c(args, info);
    else if (info->type == 'i' || info->type == 'd')
        string = get_i(args, info);
    else if (info->type == 'U')
        string = ft_itoa_base(va_arg(*args, unsigned int), 10);
    else if (info->type == 'u')
        string = get_u(args, info);
    else if (info->type == 'x')
        string = ft_strlower(get_x(args, info, 16));
    else if (info->type == 'X')
        string = get_x(args, info, 16);
    else if (info->type == 'o')
        string = get_x(args, info, 8);
    else if (info->type == 'p')
        string = ft_strjoin("0x", ft_strlower(ft_itoa_base((unsigned long long int)va_arg(*args, void *), 16)));
    return (string == NULL ? "(null)" : string);
}
