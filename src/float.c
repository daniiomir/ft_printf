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

static void		ft_handle_integer(long double *nb,
	char **str, size_t *i, long double modul)
{
	char	*s;

	s = *str;
	if (!*nb)
		s[(*i)++] = '0';
	else
	{
		while ((size_t)*nb != 0)
		{
			s[(*i)++] = (char)((*nb / modul) + 48);
			*nb -= (size_t)(*nb / modul) * modul;
			modul /= 10;
		}
	}
}

static char		*ft_handle_decimals(size_t size,
	long double nb, size_t precision)
{
	size_t	j;
	size_t	i;
	size_t	tmp;
	size_t	prev;
	char	*s;

	nb *= 10;
	j = 0;
	i = 0;
	tmp = 0;
	prev = 0;
	s = ft_strnew(size);
	s[i++] = '.';
	while (j++ < precision)
	{
		prev = tmp;
		tmp = ((size_t)nb != 9) ? (size_t)(nb + 0.001) : (size_t)nb;
		s[i++] = (char)(tmp + 48);
		nb = (nb - tmp) * 10;
	}
	if (tmp > 5)
		s[i - 1] = (char)((prev + 1) + 46);
	return (s);
}

static char		*decimals(t_arginfo *info, char *str,
	long double nb, size_t size)
{
	char	*string;

	string = NULL;
	if (info->flag[3] == '0' && info->width && info->is_precision)
		if (info->width > info->precision)
			str = handle_zero(str, info, info->width - info->precision - 1);
	if (info->precision)
		string = ft_strjoin_free_all(str,
			ft_handle_decimals(size, nb, info->precision));
	if (string == NULL)
		return (str);
	return (string);
}

static char		*ft_put_float_to_string(long double nb, t_arginfo *info)
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
	size += info->precision + 1;
	str = ft_strnew(size);
	i = 0;
	if (neg)
		str[i++] = '-';
	ft_handle_integer(&nb, &str, &i, modul);
	str = decimals(info, str, nb, size);
	if (!info->precision)
	{
		if (info->flag[0] == '#')
			str[i++] = '.';
		i++;
	}
	return (str);
}

char			*type_f(va_list *args, t_arginfo *info)
{
	char	*nb;

	if ((!info->precision && !info->is_precision)
		|| (!info->is_precision && info->precision))
		info->precision = 6;
	if (info->size[0] == 'L')
		nb = ft_put_float_to_string(va_arg(*args, long double), info);
	else
		nb = ft_put_float_to_string(va_arg(*args, double), info);
	return (nb);
}
