/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 08:33:53 by mevelyne          #+#    #+#             */
/*   Updated: 2019/07/19 19:58:40 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static double	ft_calc_modul(long double nb, size_t *size)
{
	long double	modul;

	modul = 1;
	while ((size_t)(nb /= 10) != 0 && (*size)++)
		modul *= 10;
	return (modul);
}

static void		ft_handle_integer(long double *nb,
	char **str, size_t *i, long double modul)
{
	char	*s;

	s = *str;
	while ((size_t)*nb != 0)
	{
		s[(*i)++] = (char)((*nb / modul) + 48);
		*nb -= (size_t)(*nb / modul) * modul;
		modul /= 10;
	}
}

static void		ft_handle_decimals(char **str, size_t *i,
	long double nb, size_t precision)
{
	size_t	j;
	size_t	tmp;
	size_t	prev;
	char	*s;

	s = *str;
	nb *= 10;
	j = 0;
	tmp = 0;
	prev = 0;
	s[(*i)++] = '.';
	while (j++ < precision)
	{
		prev = tmp;
		tmp = ((size_t)nb != 9) ? (size_t)(nb + 0.001) : (size_t)nb;
		s[(*i)++] = (char)(tmp + 48);
		nb = (nb - tmp) * 10;
	}
	if (tmp > 5)
		s[(*i) - 2] = (char)((prev + 1) + 48);
}

static size_t	ft_put_float_to_string(long double nb,
	char **s, size_t precision)
{
	size_t		i;
	size_t		size;
	size_t		neg;
	char		*str;
	long double	modul;

	size = 1;
	neg = 0;
	if (nb < 0 && size++ && (neg = 1) == 1)
		nb = -nb;
	modul = ft_calc_modul(nb, &size);
	size += precision + 1;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	if (neg)
		str[i++] = '-';
	ft_handle_integer(&nb, &str, &i, modul);
	ft_handle_decimals(&str, &i, nb, precision + 1);
	str[--i] = '\0';
	*s = str;
	return (size);
}

char			*type_f(va_list *args, t_arginfo *info)
{
	char	*nb;

	if (info->precision == 0)
		info->precision = 6;
	if (info->size[0] == 'L')
		ft_put_float_to_string(va_arg(*args, long double),
			&nb, info->precision);
	else
		ft_put_float_to_string(va_arg(*args, double),
			&nb, info->precision);
	return (nb);
}
