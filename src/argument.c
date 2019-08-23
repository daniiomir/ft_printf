/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 18:42:50 by swarner           #+#    #+#             */
/*   Updated: 2019/07/19 19:59:08 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*handle_octotorp(char *string, t_arginfo *info)
{
	if (info->type == 'o')
	{
		if (string[0] == '0')
			return (string);
		string = ft_strjoin_free2("0", string);
		return (string);
	}
	if (info->type == 'x' || info->type == 'X')
	{
		string = ft_strjoin_free2("0x", string);
		return (info->type == 'x' ? string : ft_strupper(string));
	}
	return (string);
}

char			*handle_string_precision(char *string, t_arginfo *info)
{
	size_t	len;
	char	*result;

	len = ft_strlen(string);
	if (info->precision >= len ||
		(ft_strchr(string, '.') == NULL && info->type == 'd'))
		return (string);
	if (info->is_precision && info->precision == 0)
	{
		result = ft_strnew(0);
		return (result);
	}
	result = ft_strnew(len);
	result = ft_strncpy(result, string, info->precision);
	free(string);
	return (result);
}

char			*handle_minus(char *string, t_arginfo *info)
{
	size_t	len;
	char	*spaces;

	len = ft_strlen(string);
	if (len < info->width)
	{
		len = info->width - len;
		spaces = ft_strnew(len);
		ft_strset(spaces, len, ' ');
		string = ft_strjoin_free_all(string, spaces);
	}
	return (string);
}

char			*handle_flags(t_arginfo *info, va_list *args,
	size_t *len_for_null)
{
	char	*arg;

	arg = get_arg(info, args, len_for_null);
	if (free_arg(info, arg))
		arg = ft_strnew(0);
	if ((info->flag[3] == '0' && ft_search_helper("iduUoxX", info->type)
	&& info->flag[1] != '-' && info->width && !info->is_precision) ||
	(info->precision && ft_search_helper("iduUopxX", info->type)))
	{
		if (info->precision)
			arg = handle_zero(arg, info, info->precision);
		else
			arg = handle_zero(arg, info, info->width);
	}
	if (info->flag[2] == '+' && ft_search_helper("idf", info->type) == 1)
		arg = handle_plus(arg);
	if (info->is_precision && ft_search_helper("sd", info->type))
		arg = handle_string_precision(arg, info);
	if ((info->flag[4] == ' ' && info->flag[2] != '+')
	|| (info->flag[1] != '-' && info->width))
		arg = handle_space(arg, info, len_for_null);
	if (info->flag[1] == '-')
		arg = handle_minus(arg, info);
	return (arg);
}
