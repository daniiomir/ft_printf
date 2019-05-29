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

	va_start(args, format);
	string = ft_engine((char *)format, &args);
	ft_putstr(string);
	free(string);
	va_end(args);
	return (ft_strlen(string));
}