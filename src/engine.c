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

static size_t	ft_next_ending(const char *format, size_t i)
{
	size_t	j;

	j = i;
	while (format[j])
	{
		if (format[j] == '%' && format[j - 1] != '%')
			break ;
		j++;
	}
	return (j);
}

char			*ft_engine(const char *format, va_list *args)
{
	size_t		i;
	size_t  	j;
	char		*string;
	char		*arg;
	char		*tmp;
	t_arginfo	*info;

	i = 0;
	if (ft_strchr(format, '%') == NULL)
		return (ft_strdup(format));
	string = ft_strnew(0);
	if (format[0] != '%')
	{
		i = ft_next_ending(format, i);
		tmp = ft_strsub(format, 0, i);
		string = ft_strjoin_free(string, tmp);
		free(tmp);
	}
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			info = (t_arginfo *)malloc(sizeof(t_arginfo));
			i = ft_parse(format, info, i);
			arg = handle_flags(info, args);
			string = ft_strjoin_free(string, arg);
			free(arg);
			free(info);
		}
		ft_strlen(format) == 2 ? j = 0 : (j = ft_next_ending(format, i) - i - 1);
		tmp = ft_strsub(format, i + 1, j);
		string = ft_strjoin_free(string, tmp);
		free(tmp);
		i = ft_next_ending(format, i);
	}
	return (string);
}
