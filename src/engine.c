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
		if (format[j - 1] == '%' && format[j] == '%')
			break ;
	}
	return (j);
}

static size_t	percent_handling(const char *format, t_arginfo *info,
	size_t i, size_t j)
{
	if (info->type == '%')
	{
		if (ft_strlen(format) == 2)
			j = ft_next_ending(format, i) - 1;
		else
			j = 1;
	}
	else
		ft_strlen(format) == 2 ? j = 0 :
			(j = ft_next_ending(format, i) - i - 1);
	return (j);
}

static char		*next_part_string(const char *format, size_t i,
	size_t j, t_arginfo *info)
{
	char	*tmp;

	if (format[i + j] == '%')
		tmp = ft_strsub(format, i + 1, j - 1);
	else if ((ft_isalnum(format[i + j]) &&
		!ft_search_helper("SsCciduUoxXpf%", format[i + j])
		&& format[i + j + 1] != '%') || (ft_isalnum(format[i + j])
		&& info->type != 'd' && format[i + j + 1] != '%'))
		tmp = ft_strsub(format, i + 1, j + 2);
	else
		tmp = ft_strsub(format, i + 1, j);
	return (tmp);
}

static size_t	start(const char *format, char **string, size_t i)
{
	*string = ft_strnew(0);
	if (format[0] != '%')
	{
		i = ft_next_ending(format, i);
		*string = ft_strjoin_free_all(*string, ft_strsub(format, 0, i));
	}
	else
		i = 0;
	return (i);
}

char			*ft_engine(const char *format, va_list *args,
	size_t *len_for_null, size_t *i)
{
	size_t		j;
	char		*string;
	char		*arg;
	t_arginfo	info;

	j = 0;
	*i = start(format, &string, *i);
	while (format[*i] != '\0')
	{
		if (format[*i] == '%')
		{
			*i = ft_parse(format, &info, *i);
			arg = handle_flags(&info, args, len_for_null);
			string = ft_strjoin_free_all(string, arg);
		}
		j = percent_handling(format, &info, *i, j);
		if (*len_for_null)
			string = ft_strjoin_null(string,
			next_part_string(format, *i, j, &info), len_for_null);
		else
			string = ft_strjoin_free_all(string,
				next_part_string(format, *i, j, &info));
		*i = ft_next_ending(format, *i);
	}
	return (string);
}
