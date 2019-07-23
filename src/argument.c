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
static void ft_strset(char *string, size_t len, char c)
{
	size_t	i;

	i = 0;
	while (i != len)
		string[i++] = c;
}

char		*handle_zero(char *string, t_arginfo *info, size_t flag_pw)
{
	size_t	len;
	size_t 	sign;
	char	*zeroes;

	sign = 0;
	len = ft_strlen(string);
	if (string[0] == '-')
	{
		string[0] = '0';
		sign++;
	}
	if (len < flag_pw)
	{
	    if (info->flag[0] == '#')
		    len = flag_pw - len - 2;
	    else
            if (info->flag[2] == '+' && sign == 0)
                len = flag_pw - len - 1;
            else
                len = flag_pw - len;
		zeroes = ft_strnew(len);
		ft_strset(zeroes, len, '0');
		string = ft_strjoin_free_all(zeroes, string);
		if (sign == 1)
			string[0] = '-';
	}
	return (string);
}

char		*handle_space(char *string, t_arginfo *info, size_t *len_for_null)
{
	size_t	len;
	char	*spaces;

	len = ft_strlen(string);
	if (len < info->width)
	{
		len = info->width - len;
		spaces = ft_strnew(len);
		ft_strset(spaces, len, ' ');
		if (*len_for_null > 0)
            string = ft_strjoin_null(spaces, string, len_for_null);
		else
		    string = ft_strjoin_free_all(spaces, string);
	}
    if (info->width == 0 && string[0] != '-' && string[0] != '+' && ft_search_helper("id", info->type) == 1)
        string = ft_strjoin_free2(" ", string);
	return (string);
}

char		*handle_plus(char *string)
{
	if (string[0] != '-')
		string = ft_strjoin_free2("+", string);
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
char	*handle_string_precision(char *string, t_arginfo *info)
{
	size_t	len;
	char *result;
	len = ft_strlen(string);
	if (info->precision >= len || (ft_strchr(string, '.') == NULL && info->type == 'd'))
		return (string);
	result = ft_strnew(len);
	result = ft_strncpy(result, string, info->precision);
	free(string);
	return (result);
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
	}
	return (string);
}

char	*handle_flags(t_arginfo *info, va_list *args, size_t *len_for_null)
{
	char	*arg;
	
	arg = get_arg(info, args, len_for_null);
	if ((info->flag[3] == '0' && ft_search_helper("iduUoxX", info->type) == 1
	&& info->flag[1] != '-' && info->width > 0) ||
	(info->precision > 0 && info->type != 'f'))
	{
		if (info->precision)
			arg = handle_zero(arg, info, info->precision);
		else
			arg = handle_zero(arg, info, info->width);
	}
	if (info->flag[0] == '#' && (arg[0] != '0' || arg[1] != '\0') && ft_search_helper("X", info->type) == 1 && info->width == 0)
		arg = handle_octotorp(arg, info);
	if (info->flag[2] == '+' && ft_search_helper("id", info->type) == 1)
		arg = handle_plus(arg);
    if (info->flag[4] == ' ' || ( info->flag[1] != '-' && info->width > 0))
            arg = handle_space(arg, info, len_for_null);
	if (info->flag[1] == '-')
		arg = handle_minus(arg, info);
	if (info->precision > 0 && ft_search_helper("sd", info->type) && !info->width)
		arg = handle_string_precision(arg, info);
	return (arg);
}
