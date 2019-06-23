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

static void	ft_clean_info(t_arginfo *info)
{
	info->octotorp = 0;
	info->space = 0;
	info->zero = 0;
	info->minus = 0;
	info->plus = 0;
	info->width = 0;
	info->precision = 0;
	info->size[0] = '\0';
	info->size[1] = '\0';
	info->type = '\0';
}

int		ft_search_helper(const char *string, char search)
{
	size_t	j;

	j = 0;
	while (string[j])
	{
		if (string[j] == search)
			return (1);
		j++;
	}
	return (0);
}

size_t	ft_parse(const char *format, t_arginfo *info, size_t i)
{
	ft_clean_info(info);
	i = ft_parse_flags(format, info, i);
	i = ft_parse_width(format, info, i);
	i = ft_parse_precision(format, info, i);
	i = ft_parse_size(format, info, i);
	i = ft_parse_types(format, info, i);
	return (i);
}

size_t	ft_parse_flags(const char *format, t_arginfo *info, size_t i)
{
	if (ft_search_helper("# 0-+", format[i + 1]))
	{
		if (format[i + 1] == '#')
			info->octotorp = 1;
		else if (format[i + 1] == ' ')
			info->space = 1;
		else if (format[i + 1] == '0')
			info->zero = 1;
		else if (format[i + 1] == '-')
			info->minus = 1;
		else if (format[i + 1] == '+')
			info->plus = 1;
		return (i + 1);
	}
	return (i);
}

size_t	ft_parse_width(const char *format, t_arginfo *info, size_t i)
{
	size_t	j;
	char 	*width;

	j = i;
	if (ft_isdigit(format[j + 1]))
	{
		while (ft_isdigit(format[j + 1]))
			j++;
		width = ft_strsub(format, i + 1, j - i);
		info->width = ft_atoi(width);
		free(width);
		return (j);
	}
	return (i);
}

size_t	ft_parse_precision(const char *format, t_arginfo *info, size_t i)
{
	size_t	j;
	char 	*precision;

	if (format[i + 1] == '.')
	{
		j = i + 1;
		while (ft_isdigit(format[j + 1]))
			j++;
		precision = ft_strsub(format, i + 2, j - i);
		info->precision = ft_atoi(precision);
		free(precision);
		return (j);
	}
	else
		return (i);
}

size_t	ft_parse_size(const char *format, t_arginfo *info, size_t i)
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

size_t	ft_parse_types(const char *format, t_arginfo *info, size_t i)
{

	if (format[i + 1] == '%')
		info->type = '%';
	else if (format[i + 1] == 's')
		info->type = 's';
	else if (format[i + 1] == 'c')
		info->type = 'c';
	else if (format[i + 1] == 'i')
		info->type = 'i';
	else if (format[i + 1] == 'd')
		info->type = 'd';
	else if (format[i + 1] == 'u')
		info->type = 'u';
	else if (format[i + 1] == 'U')
		info->type = 'U';
	else if (format[i + 1] == 'o')
		info->type = 'o';
	else if (format[i + 1] == 'b')
		info->type = 'b';
	else if (format[i + 1] == 'X')
		info->type = 'X';
	else if (format[i + 1] == 'x')
		info->type = 'x';
	else if (format[i + 1] == 'p')
		info->type = 'p';
	return (i + 1);
}
