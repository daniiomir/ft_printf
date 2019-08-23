/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:10:35 by swarner           #+#    #+#             */
/*   Updated: 2019/06/03 15:10:37 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_parse_width(const char *format, t_arginfo *info, size_t i)
{
	size_t	j;
	size_t	w;
	char	*width;

	j = i;
	if (ft_isdigit(format[j + 1]))
	{
		while (ft_isdigit(format[j + 1]))
			j++;
		if (j - i == 1)
			w = j - i;
		else
			w = j;
		width = ft_strsub(format, i + 1, w);
		info->width = ft_atoi(width);
		free(width);
		return (j);
	}
	return (i);
}

static size_t	ft_parse_precision(const char *format, t_arginfo *info,
	size_t i)
{
	size_t	j;
	char	*precision;

	if (format[i + 1] == '.')
	{
		info->is_precision = 1;
		j = i + 1;
		while (ft_isdigit(format[j + 1]))
			j++;
		precision = ft_strsub(format, i + 2, j - i);
		info->precision = ft_atoi(precision);
		if (info->precision > 2147483647)
			info->precision = 6;
		free(precision);
		return (j);
	}
	else
		return (i);
}

static size_t	ft_parse_size(const char *format, t_arginfo *info, size_t i)
{
	if (ft_search_helper("lhLztj", format[i + 1]))
	{
		info->size[0] = format[i + 1];
		if (ft_search_helper("lh", format[i + 2]))
		{
			info->size[1] = format[i + 2];
			return (i + 2);
		}
		return (i + 1);
	}
	else
		return (i);
}

static size_t	ft_parse_types(const char *format, t_arginfo *info, size_t i)
{
	if (ft_search_helper("sciduUobxXpf%", format[i + 1]))
		info->type = format[i + 1];
	return (i + 1);
}

size_t			ft_parse(const char *format, t_arginfo *info, size_t i)
{
	ft_clean_info(info);
	i = ft_parse_flags(format, info, i);
	i = ft_parse_width(format, info, i);
	i = ft_parse_precision(format, info, i);
	i = ft_parse_size(format, info, i);
	i = ft_parse_types(format, info, i);
	return (i);
}
