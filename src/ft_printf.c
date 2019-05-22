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

	va_start(va, format);
	string = ft_engine((char *)format, args);
	va_end(va);
	return (ft_strlen(string));
}