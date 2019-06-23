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

static char	*ft_strset(char *string, size_t len, char c)
{
	size_t	i;

	i = 0;
	while (i != len + 1)
		string[i++] = c;
}

char		*handle_zero(char *string, t_arginfo *info)
{
	char	*zeroes;

	if (info->zero == 1 && ft_search_helper("iduUoxX", info->type) == 1)
	{
		len = ft_strlen(string)
		if (len < info->width)
		{
			len = info->width - len;
			zeroes = ft_strnew(len);
			ft_strset(zeroes, len, '0');
			string = ft_strjoin_free_all(zeroes, string);
			return (string);
		}
	}
	return (string);
}

char		*handle_space(char *string, t_arginfo *info)
{
	char	*zeroes;

	if (info->space == 1)
	{
		zeroes = ft_strnew(info->width);
		ft_strset(zeroes, info->width, ' ');
		string = ft_strjoin_free_all(zeroes, string);
		return (string);
	}
	return (string);
}

char		*handle_plus(char *string, t_arginfo *info)
{
	char	*sign;

	if (info->plus == 1 && ft_search_helper("iduU", info->type) == 1)
	{
		if (string[0] != '-')
		{
			sign = ft_strnew(1);
			sign[0] = '+';
			string = ft_strjoin_free_all(sign, string);
			return (string);
		}
	}
	return (string);
}

char		*handle_octotorp(char *string, t_arginfo *info)
{
	char	*prefix;

	if (info->octotorp == 1)
	{
		if (info->type == 'o')
		{
			prefix = ft_strnew(1);
			prefix[0] = '0';
			string = ft_strjoin_free_all(prefix, string);
			return (string);
		}
		if (info->type == 'x' || info->type == 'X')
		{
			prefix = ft_strnew(2);
			prefix[0] = '0';
			prefix[1] = 'x';
			string = ft_strjoin_free_all(prefix, string);
			return (info->type == 'x' ? string : ft_strupper(string));
		}
	}
	return (string);
}

char		*handle_minus(char *string, t_arginfo *info)
{

}

char	*get_arg(t_arginfo *info, va_list *args)
{
	char	*string;

	if (info->type == '%')
		return ("%");
	else if (info->type == 's')
		return ((string = va_arg(*args, char *)) == NULL ? "(null)" : letter);
	else if (info->type == 'c')
	{
		string = ft_strnew(1);
		letter[0] = va_arg(*args, int);
		return (letter);
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
	// arg = handle_zero(arg, info);
	return (arg);
}

/*
char	*ft_parse_types(const char *format, va_list *args, size_t i)
{
	
}
*/
