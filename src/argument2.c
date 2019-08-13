/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 22:33:40 by swarner           #+#    #+#             */
/*   Updated: 2019/08/13 22:33:43 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*handle_zero(char *string, t_arginfo *info, size_t flag_pw)
{
	size_t	len;
	size_t	sign;

	sign = 0;
	len = ft_strlen(string);
	if (len < flag_pw)
	{
		if (string[0] == '-')
		{
			string[0] = '0';
			sign++;
		}
		len = len_for_zeroes(string, info, flag_pw, sign);
		string = zeroes_to_string(string, sign, len);
	}
	return (string);
}

char			*handle_space(char *string, t_arginfo *info,
	size_t *len_for_null)
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
	if (info->width == 0 && string[0] != '-' && string[0] != '+'
		&& ft_search_helper("id", info->type))
		string = ft_strjoin_free2(" ", string);
	return (string);
}

char			*handle_plus(char *string)
{
	if (string[0] != '-')
		string = ft_strjoin_free2("+", string);
	return (string);
}
