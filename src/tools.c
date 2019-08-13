/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 22:06:44 by swarner           #+#    #+#             */
/*   Updated: 2019/08/13 22:06:46 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*zeroes_to_string(char *string, size_t sign, size_t len)
{
	char	*zeroes;

	zeroes = ft_strnew(len);
	ft_strset(zeroes, len, '0');
	string = ft_strjoin_free_all(zeroes, string);
	if (sign == 1)
		string[0] = '-';
	return (string);
}

size_t			len_for_zeroes(char *string, t_arginfo *info,
	size_t flag_pw, size_t sign)
{
	size_t	len;

	len = ft_strlen(string);
	if (info->flag[0] == '#' && info->precision && info->type == 'o')
		len = flag_pw - ft_strlen(string);
	else if (info->flag[0] == '#' && info->precision)
		len = flag_pw - len;
	else if (info->flag[0] == '#')
		len = flag_pw - len - 2;
	else if ((info->flag[2] == '+' && sign == 0) || info->flag[4] == ' '
		|| (info->flag[3] == '0' && info->is_precision && sign == 0))
		len = flag_pw - len - 1;
	else if ((info->precision && sign == 1 && !info->width) ||
		(info->precision && sign == 1 && flags_checker(info) == 0))
		len = flag_pw - len + 1;
	else
		len = flag_pw - len;
	return (len);
}

size_t			free_arg(t_arginfo *info, char *arg)
{
	if ((ft_search_helper("uxX", info->type) && info->is_precision
		&& arg[0] == '0' && !info->precision) || (info->type == 'o'
		&& info->flag[0] != '#'
		&& info->is_precision && arg[0] == '0'))
	{
		free(arg);
		return (1);
	}
	return (0);
}

static char		*strjoin_null_helper(char *for_malloc, char *s1,
	char *s2, size_t *len_for_null)
{
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s2[0] == '\0')
		for_malloc = ft_strnew(s1_len);
	else
	{
		if (*len_for_null)
			for_malloc = ft_strnew(s1_len + s2_len);
		else
			return (ft_strjoin_free_all(s1, s2));
	}
	return (for_malloc);
}

char			*ft_strjoin_null(char *s1, char *s2, size_t *len_for_null)
{
	size_t	i;
	size_t	j;
	size_t	h;
	char	*for_malloc;
	size_t	s2_len;

	i = 0;
	j = 0;
	h = 0;
	s2_len = ft_strlen(s2);
	for_malloc = NULL;
	for_malloc = strjoin_null_helper(for_malloc, s1, s2, len_for_null);
	while (i < ft_strlen(s1))
		for_malloc[h++] = s1[i++];
	for_malloc[h++] = '\0';
	while (j <= s2_len)
		for_malloc[h++] = s2[j++];
	*len_for_null = s2_len + 1;
	free(s1);
	free(s2);
	return (for_malloc);
}
