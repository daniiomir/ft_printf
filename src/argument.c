/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 18:42:50 by swarner           #+#    #+#             */
/*   Updated: 2019/06/11 18:42:52 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_strset(char *string, size_t len, char c)
{
	size_t	i;

	i = 0;
	while (i != len)
		string[i++] = c;
}

char		*handle_zero(char *string, t_arginfo *info)
{
	size_t	len;
	char	*zeroes;

	len = ft_strlen(string);
	if (len < info->width)
	{
		len = info->width - len;
		zeroes = ft_strnew(len);
		ft_strset(zeroes, len, '0');
		string = ft_strjoin_free_all(zeroes, string);
		return (string);
	}
	return (string);
}

char		*handle_space(char *string, t_arginfo *info)
{
	size_t	len;
	char	*spaces;

	len = ft_strlen(string);
	if (len < info->width)
	{
		len = info->width - len;
		spaces = ft_strnew(len);
		ft_strset(spaces, len, ' ');
		string = ft_strjoin_free_all(spaces, string);
		return (string);
	}
	return (string);
}

char		*handle_plus(char *string)
{
	if (string[0] != '-')
	{
		string = ft_strjoin_free2("+", string);
		return (string);
	}
	return (string);
}

char		*handle_octotorp(char *string, t_arginfo *info)
{
	if (info->type == 'o')
	{
		string = ft_strjoin_free2("0", string);
		return (string);
	}
	if (info->type == 'x' || info->type == 'X')
	{
		string = ft_strjoin_free2("0x", string);
		return (info->type == 'x' ? string : ft_strupper(string));
	}
	return (string);
}

char		*handle_minus(char *string, t_arginfo *info)
{
	size_t	len;
	char	*spaces;

	len = ft_strlen(string);
	if (len < info->width)
	{
		len = info->width - len;
		spaces = ft_strnew(len);
		ft_strset(spaces, len, ' ');
		string = ft_strjoin_free_all(string, spaces);
		return (string);
	}
	return (string);
}

// char		*set_size(t_arginfo *info, va_list *args)
// {
// 	if ()
// }

char	*get_arg(t_arginfo *info, va_list *args)
{
	char	*string;

	if (info->type == '%')
	{
		string = ft_strnew(1);
		string[0] = '%';
		return (string);
	}
	else if (info->type == 's')
		return ((string = va_arg(*args, char *)) == NULL ? "(null)" : string);
	else if (info->type == 'c')
	{
		string = ft_strnew(1);
		string[0] = va_arg(*args, int);
		return (string);
	}
	else if (info->type == 'i' || info->type == 'd')
		return (ft_itoa(va_arg(*args, int)));
	else if (info->type == 'u')
		return (ft_itoa_base(va_arg(*args, unsigned int), 10));
	else if (info->type == 'U')
		return (ft_itoa_base(va_arg(*args, unsigned int), 10));
	else if (info->type == 'o')
		return (ft_itoa_base(va_arg(*args, unsigned int), 8));
	else if (info->type == 'b')
		return (ft_itoa_base(va_arg(*args, int), 2));
	else if (info->type == 'X')
		return (ft_itoa_base(va_arg(*args, unsigned int), 16));
	else if (info->type == 'x')
		return (ft_strlower(ft_itoa_base(va_arg(*args, unsigned int), 16)));
	else if (info->type == 'p')
		return (ft_strjoin("0x", ft_strlower(ft_itoa_base((unsigned long long int)va_arg(*args, void *), 16))));
	return ("\0");
}

char	*handle_flags(t_arginfo *info, va_list *args)
{
	char	*arg;

	arg = get_arg(info, args);
	if (info->flag == '0' && ft_search_helper("iduUoxX", info->type) == 1)
		arg = handle_zero(arg, info);
	else if (info->flag == ' ')
		arg = handle_space(arg, info);
	else if (info->flag == '#')
		arg = handle_octotorp(arg, info);
	else if (info->flag == '+' && ft_search_helper("iduU", info->type) == 1)
		arg = handle_plus(arg);
	else if (info->flag == '-')
		arg = handle_minus(arg, info);
	return (arg);
}
