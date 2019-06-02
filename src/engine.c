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
	while (format[j])
	{
	    if (format[j] == '%')
	        break ;
        j++;
    }
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
        return (ft_itoa_base(va_arg(*args, unsigned int), 10));
    else if (format[i + 1] == 'U')
        return (ft_itoa_base(va_arg(*args, unsigned int), 10));
    else if (format[i + 1] == 'o')
        return (ft_itoa_base(va_arg(*args, unsigned int), 8));
    else if (format[i + 1] == 'b')
        return (ft_itoa_base(va_arg(*args, int), 2));
    else if (format[i + 1] == 'X')
        return (ft_itoa_base(va_arg(*args, unsigned int), 16));
    else if (format[i + 1] == 'x')
        return (ft_strlower(ft_itoa_base(va_arg(*args, unsigned int), 16)));
    else if (format[i + 1] == 'p')
        return (ft_strjoin("0x", ft_strlower(ft_itoa_base((unsigned long long int)va_arg(*args, void *), 16))));
	return ("\0");
}

char			*ft_engine(char *format, va_list *args)
{
	size_t	i;
	size_t  j;

	char	*string;

	i = 0;
	if (ft_strchr(format, '%') == NULL)
	{
		string = ft_strdup(format);
		return (string);
	}
	string = ft_strnew(0);
	if (format[0] != '%')
    {
	    i = ft_next_ending(format, i);
        string = ft_strjoin_free(string, ft_strsub(format, 0, i));
    }
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			string = ft_strjoin_free(string, ft_parse_args(format, args, i));
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			string = ft_strjoin_free(string, "%");
			i++;
		}
		i == 1 ? j = 1 : (j = ft_next_ending(format, i) - i - 1);
		string = ft_strjoin_free(string, ft_strsub(format, i + 1, j));
		i = ft_next_ending(format, i);
	}
	return (string);
}
