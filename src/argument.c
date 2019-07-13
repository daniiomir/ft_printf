/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 18:42:50 by swarner           #+#    #+#             */
/*   Updated: 2019/06/11 18:42:52 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_strset(char *string, size_t len, char c)
{
	size_t	i;

	i = 0;
	while (i != len)
		string[i++] = c;
}

char		*handle_zero(char *string, t_arginfo *info)
{
	size_t	len;
	char	*zeroes;

	len = ft_strlen(string);
	if (len < info->width)
	{
	    if (info->flag[0] == '#')
		    len = info->width - len - 2;
	    else
            len = info->width - len;
		zeroes = ft_strnew(len);
		ft_strset(zeroes, len, '0');
		string = ft_strjoin_free_all(zeroes, string);
		return (string);
	}
	return (string);
}

char		*handle_space(char *string, t_arginfo *info)
{
	size_t	len;
	char	*spaces;

	len = ft_strlen(string);
	if (len < info->width)
	{
		len = info->width - len;
		spaces = ft_strnew(len);
		ft_strset(spaces, len, ' ');
		string = ft_strjoin_free_all(spaces, string);
		return (string);
	}
	return (string);
}

char		*handle_plus(char *string)
{
	if (string[0] != '-')
	{
		string = ft_strjoin_free2("+", string);
		return (string);
	}
	return (string);
}

char		*handle_octotorp(char *string, t_arginfo *info)
{
	if (info->type == 'o')
	{
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

char		*handle_minus(char *string, t_arginfo *info)
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
		return (string);
	}
	return (string);
}

char	*handle_flags(t_arginfo *info, va_list *args, size_t *len_for_null) // WORK WITH FLAGS!!!!
{
	char	*arg;
	
	arg = get_arg(info, args, len_for_null);
	if (info->flag[3] == '0' && ft_search_helper("iduUoxX", info->type) == 1 && info->flag[1] != '-')
		arg = handle_zero(arg, info);
	if (info->flag[4] == ' ' || ( info->flag[1] != '-' && info->width > 0))
		arg = handle_space(arg, info);
	if (info->flag[0] == '#' && (arg[0] != '0' || arg[1] != '\0') && ft_search_helper("oX", info->type) == 1 && info->width == 0)
		arg = handle_octotorp(arg, info);
	if (info->flag[2] == '+' && ft_search_helper("id", info->type) == 1)
		arg = handle_plus(arg);
	if (info->flag[1] == '-')
		arg = handle_minus(arg, info);
	return (arg);
}
