/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:32:29 by swarner           #+#    #+#             */
/*   Updated: 2019/05/16 17:32:30 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	char	*string;
	va_list	args;
	size_t	len;
	size_t	len_for_null;
	size_t	i;

	i = 0;
	len_for_null = 0;
	va_start(args, format);
	if (ft_strchr(format, '%') == NULL)
		string = ft_strdup(format);
	else
		string = ft_engine(format, &args, &len_for_null, &i);
	len = ft_strlen(string) + len_for_null;
	write(1, string, len);
	free(string);
	va_end(args);
	return (len);
}
