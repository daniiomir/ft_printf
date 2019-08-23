/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:55:30 by swarner           #+#    #+#             */
/*   Updated: 2019/07/19 19:52:49 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_p(va_list *args, t_arginfo *info, char *string)
{
	string = ft_itoa_base(
		(unsigned long long int)va_arg(*args, void *), 16);
	if (string[0] == '0' && info->is_precision)
		string = ft_strjoin_free2("0x",
			handle_zero(ft_strnew(0), info, info->precision));
	else if (info->precision > 0)
		string = ft_strjoin_free2("0x",
			ft_strlower(handle_zero(string, info, info->precision)));
	else
		string = ft_strlower(ft_strjoin_free2("0x", string));
	return (string);
}

static char	*get_o(va_list *args, t_arginfo *info, char *string)
{
	if (info->flag[0] == '#')
	{
		if (info->precision)
			string = handle_zero(handle_octotorp(get_x(args,
				info, 8), info), info, info->precision);
		else
			string = handle_octotorp(get_x(args, info, 8), info);
	}
	else
		string = get_x(args, info, 8);
	return (string);
}

static char	*get_x_with_flags(va_list *args, t_arginfo *info, char *string)
{
	if (info->flag[0] == '#')
	{
		string = get_x(args, info, 16);
		if (string[0] != '0')
		{
			if (info->flag[3] == '0' && info->flag[1] != '-'
				&& !info->is_precision)
				string = handle_octotorp(handle_zero(
					string, info, info->width), info);
			else if (info->precision > 0)
				string = handle_octotorp(handle_zero(string,
					info, info->precision), info);
			else
				string = handle_octotorp(string, info);
		}
	}
	else
		string = get_x(args, info, 16);
	if (info->type == 'x')
		string = ft_strlower(string);
	return (string);
}

char		*get_arg(t_arginfo *info, va_list *args, size_t *len_for_null)
{
	char	*string;

	string = NULL;
	if (info->type == 's')
		string = get_s(args);
	else if (info->type == 'f' || info->type == 'F')
		string = type_f(args, info);
	else if (info->type == 'c' || info->type == '%' || info->type == '\0')
		string = get_c(args, info, len_for_null);
	else if (info->type == 'i' || info->type == 'd')
		string = get_i(args, info);
	else if (info->type == 'U')
		string = ft_itoa_base(va_arg(*args, unsigned int), 10);
	else if (info->type == 'u')
		string = get_u(args, info);
	else if (info->type == 'o' || info->type == 'x' || info->type == 'X')
	{
		if (info->type == 'o')
			string = get_o(args, info, string);
		else if (info->type == 'x' || info->type == 'X')
			string = get_x_with_flags(args, info, string);
	}
	else if (info->type == 'p')
		string = get_p(args, info, string);
	return (string);
}
