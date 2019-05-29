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
    char    letter;
	if (format[i + 1] == '%')
		return ("%");
	if (format[i + 1] == 's')
		return (va_arg(*args, char *));
	if (format[i + 1] == 'c')
	{
        letter = (char *)va_arg(*args, char);
        return (letter);
    }
	return ("\0");
}

char			*ft_engine(char *format, va_list *args)
{
	size_t	i;
	size_t  j;
	char	*string;

	i = 0;
	j = 0;
    if (ft_strchr(format, '%') == NULL)
        return (ft_strdup(format));
    string = ft_strnew(0);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			//string = ft_strjoin_free(string, ft_strsub(format, 0, i));
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
