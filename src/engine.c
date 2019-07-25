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
	}
	return (j);
}

static size_t	ft_next_ending_p(t_arginfo *info, const char *format, size_t i)
{
    size_t	j;

    j = i;
    while (format[j])
    {
        if (format[j] == '%' && format[j - 1] != '%' && info->type != '%')
            break ;
        j++;
    }
    return (j);
}

char		*ft_strjoin_free2(char *s1, char *s2)
{
	char	*result;

	if (!s2)
	    return (s1);
	result = ft_strjoin(s1, s2);
	free(s2);
	return (result);
}

char		*ft_strjoin_free_all(char *s1, char *s2)
{
	char	*result;

	if (!s2)
	    return (s1);
	result = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (result);
}

char        *ft_strjoin_null(char *s1, char *s2, size_t *len_for_null)
{
    size_t	i;
    size_t	j;
    size_t	h;
    char	*for_malloc;
    size_t  s1_len;
    size_t  s2_len;

    i = 0;
    j = 0;
    h = 0;
    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);

    if (s2[0] == '\0')
        for_malloc = ft_strnew(s1_len + 2);
    else
    {
        if (*len_for_null > 0)
            for_malloc = ft_strnew(s1_len + s2_len + 1);
        else
            return (ft_strjoin_free_all(s1, s2));
    }
    while (i < s1_len + 1)
        for_malloc[h++] = s1[i++];
    if (s2[0] == '\0')
        for_malloc[h++] = '\0';
    else
    {
        while (j < s2_len + 1)
            for_malloc[h++] = s2[j++];
    }
    *len_for_null = s2_len + 1;
    free(s1);
    free(s2);
    return (for_malloc);
}

char		*ft_engine(const char *format, va_list *args, size_t *len_for_null)
{
	size_t		i;
	size_t  	j;
	char		*string;
	char		*arg;
	char		*tmp;
	t_arginfo	*info;

	i = 0;
	if (ft_strchr(format, '%') == NULL)
		return (ft_strdup(format));
	string = ft_strnew(1);
	if (format[0] != '%')
	{
		i = ft_next_ending(format, i);
		tmp = ft_strsub(format, 0, i);
		string = ft_strjoin_free_all(string, tmp);
	}
	while (format[i] != '\0')
	{
        info = (t_arginfo *)malloc(sizeof(t_arginfo));
		if (format[i] == '%')
		{
			i = ft_parse(format, info, i);
			arg = handle_flags(info, args, len_for_null);
			if (*len_for_null > 0)
            {
			    if (info->width == 0)
			        string = ft_strjoin_null(string, arg, len_for_null);
			    else
                    string = ft_strjoin_null(arg, string, len_for_null);
            }
			else
			    string = ft_strjoin_free_all(string, arg);
		}
		if (info->type == '%')
		    ft_strlen(format) == 2 ? j = 0 : (j = ft_next_ending_p(info, format, i) - 1);
		else
            ft_strlen(format) == 2 ? j = 0 : (j = ft_next_ending(format, i) - i - 1);
		tmp = ft_strsub(format, i + 1, j);
		if (*len_for_null > 0)
            string = ft_strjoin_null(string, tmp, len_for_null);
		else
		    string = ft_strjoin_free_all(string, tmp);
		i = ft_next_ending_p(info, format, i);
        free(info);
	}
	return (string);
}
