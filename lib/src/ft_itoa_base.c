/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 20:32:44 by swarner           #+#    #+#             */
/*   Updated: 2019/05/29 20:32:46 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_helper(int tmp, int base, int size, int flag)
{
	while (tmp /= base)
		size++;
	size = size + flag + 1;
	return (size);
}

char		*ft_itoa_base(int value, int base)
{
	char	*str;
	char	*tab;
	int		size;
	int		flag;
	int		tmp;

	flag = 0;
	size = 0;
	tab = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (0);
	if (value < 0 && base == 10)
		flag = 1;
	tmp = value;
	size = ft_itoa_helper(tmp, base, size, flag);
	str = ft_strnew(size);
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[ft_abs(value % base)];
		size--;
		value /= base;
	}
	return (str);
}
