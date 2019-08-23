/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 22:14:10 by swarner           #+#    #+#             */
/*   Updated: 2019/08/13 22:14:14 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

double	ft_calc_modul(long double nb, size_t *size)
{
	long double	modul;

	modul = 1;
	while ((size_t)(nb /= 10) != 0 && (*size)++)
		modul *= 10;
	return (modul);
}

void	ft_clean_info(t_arginfo *info)
{
	size_t	i;

	i = 0;
	info->width = 0;
	info->is_precision = 0;
	info->precision = 0;
	info->size[0] = '\0';
	info->size[1] = '\0';
	while (i < 5)
		info->flag[i++] = '\0';
	info->type = '\0';
}

int		flags_checker(t_arginfo *info)
{
	if (info->flag[0] != '\0' || info->flag[1] != '\0' ||
	info->flag[2] != '\0' || info->flag[3] != '\0' || info->flag[4] != '\0')
		return (1);
	return (0);
}

size_t	ft_parse_flags(const char *format, t_arginfo *info, size_t i)
{
	size_t	j;

	if (ft_search_helper("# 0-+", format[i + 1]))
	{
		j = 1;
		while (ft_search_helper("# 0-+", format[i + j]) == 1 && j <= 5)
		{
			if (format[i + j] == '#')
				info->flag[0] = '#';
			else if (format[i + j] == '-')
				info->flag[1] = '-';
			else if (format[i + j] == '+')
				info->flag[2] = '+';
			else if (format[i + j] == '0')
				info->flag[3] = '0';
			else if (format[i + j] == ' ')
				info->flag[4] = ' ';
			j++;
		}
		return (i + j - 1);
	}
	return (i);
}
