/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:58:08 by swarner           #+#    #+#             */
/*   Updated: 2019/05/22 16:58:09 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_next_ending(char *format, size_t i)
{
	size_t	j;

	j = i;
	while (format[j] != '\0' && format[j] != '%')
		j++;
	return (j);
}

char			*ft_parse_args(char *format, va_list *args, size_t i)
{
	char	*letter;

	if (format[i + 1] == '%')
		return ("%");
	else if (format[i + 1] == 's')
		return (va_arg(*args, char *));
	else if (format[i + 1] == 'c')
	{
		letter = ft_strnew(1);
		letter[0] = va_arg(*args, int);
		return (letter);
	}
	else if (format[i + 1] == 'i' || format[i + 1] == 'd')
	    return (ft_itoa(va_arg(*args, int)));
	else if (format[i + 1] == 'u')
        return (ft_unsigned_itoa(va_arg(*args, unsigned int)));
    else if (format[i + 1] == 'o')
        return (ft_itoa_base(va_arg(*args, int), 8));
    else if (format[i + 1] == 'b')
        return (ft_itoa_base(va_arg(*args, int), 2));
    else if (format[i + 1] == 'X')
        return (ft_itoa_base(va_arg(*args, int), 16));
    else if (format[i + 1] == 'x')
        return (ft_strlower(ft_itoa_base(va_arg(*args, int), 16)));
	return ("\0");
}

char			*ft_engine(char *format, va_list *args)
{
	size_t	i;
	char	*string;

	i = 0;
	if (ft_strchr(format, '%') == NULL)
	{
		string = ft_strdup(format);
		return (string);
	}
	string = ft_strnew(0);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			string = ft_strjoin_free(string, ft_parse_args(format, args, i));
			i = i + 2;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			string = ft_strjoin_free(string, "%");
			i = i + 2;
		}
		string = ft_strjoin_free(string, ft_strsub(format, i, ft_next_ending(format, i)));
		i++;
	}
	return (string);
}
