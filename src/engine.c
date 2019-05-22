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

char	*ft_engine(char *format) // , va_list *args
{
	size_t	i;
	char	*string;

	i = 0;
	string = ft_strnew(0);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			string = ft_strjoin_free(string, ft_strsub(format, 0, i));
		}
		i++;
	}
	if (ft_strchr(format, '%') == NULL)
		string = ft_strdup(format);
	return (string);
}
