/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 22:17:06 by swarner           #+#    #+#             */
/*   Updated: 2019/08/13 22:17:08 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_u(va_list *args, t_arginfo *info)
{
	char	*string;

	if (info->size[0] == 'h')
	{
		if (info->size[1] == 'h')
			string = ft_itoa_base((unsigned char)va_arg(*args, int), 10);
		else
			string = ft_itoa_base((unsigned short int)va_arg(*args, int), 10);
	}
	else if (info->size[0] == 'l')
		if (info->size[1] == 'l')
			string = ft_itoa_base(va_arg(*args, unsigned long long int), 10);
		else
			string = ft_itoa_base(va_arg(*args, unsigned long int), 10);
	else
		string = ft_itoa_base(va_arg(*args, unsigned int), 10);
	return (string);
}

char	*get_x(va_list *args, t_arginfo *info, size_t base)
{
	char	*string;

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

char	*get_i(va_list *args, t_arginfo *info)
{
	char			*string;
	long long int	arg;

	arg = va_arg(*args, long long int);
	if (arg == 0 && info->is_precision)
	{
		string = ft_strnew(0);
		return (string);
	}
	if (info->size[0] == 'h')
	{
		if (info->size[1] == 'h')
			string = ft_itoa((signed char)arg);
		else
			string = ft_itoa((short int)arg);
	}
	else if (info->size[0] == 'l')
		string = ft_itoa(arg);
	else
		string = ft_itoa((int)arg);
	if (info->type == 'd' && info->is_precision
		&& info->width && info->flag[3] != '0' && flags_checker(info))
		string = ft_strjoin_free2("0", string);
	return (string);
}

char	*get_c(va_list *args, t_arginfo *info, size_t *len_for_null)
{
	char	*for_char;

	for_char = ft_strnew(1);
	if (info->type == '%')
	{
		for_char[0] = '%';
		return (for_char);
	}
	else if (info->type == 'c')
	{
		for_char[0] = va_arg(*args, int);
		if (for_char[0] == 0)
		{
			if (info->width > 0)
				info->width--;
			*len_for_null = 1;
		}
		return (for_char);
	}
	else
	{
		for_char[0] = '\0';
		return (for_char);
	}
}

char	*get_s(va_list *args)
{
	char	*for_string;
	char	*for_null;

	for_string = va_arg(*args, char *);
	if (for_string == NULL)
	{
		for_null = "(null)";
		for_string = ft_strsub(for_null, 0, ft_strlen(for_null));
		return (for_string);
	}
	else
		return (ft_strdup(for_string));
}
