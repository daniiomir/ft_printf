/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:28:00 by swarner           #+#    #+#             */
/*   Updated: 2019/08/13 22:38:29 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include "../lib/includes/libft.h"

typedef struct		s_arginfo
{
	char	type;
	char	flag[5];
	char	size[2];
	size_t	is_precision;
	size_t	width;
	size_t	precision;
}					t_arginfo;

char				*ft_strjoin_null(char *s1, char *s2, size_t *len_for_null);
int					flags_checker(t_arginfo *info);
int					ft_printf(const char *format, ...);
char				*ft_engine(const char *format, va_list *args,
	size_t *len_for_null, size_t *i);
size_t				ft_parse(const char *format, t_arginfo *info, size_t i);
char				*handle_flags(t_arginfo *info, va_list *args,
	size_t *len_for_null);
char				*handle_zero(char *string, t_arginfo *info, size_t flag_pw);
char				*handle_space(char *string, t_arginfo *info,
	size_t *len_for_null);
char				*handle_plus(char *string);
char				*handle_octotorp(char *string, t_arginfo *info);
char				*handle_minus(char *string, t_arginfo *info);
char				*handle_string_precision(char *string, t_arginfo *info);
char				*get_arg(t_arginfo *info, va_list *args,
	size_t *len_for_null);
char				*get_u(va_list *args, t_arginfo *info);
char				*get_x(va_list *args, t_arginfo *info, size_t base);
char				*get_i(va_list *args, t_arginfo *info);
char				*get_c(va_list *args, t_arginfo *info,
		size_t *len_for_null);
char				*get_s(va_list *args);
char				*type_f(va_list *args, t_arginfo *flags);
char				*zeroes_to_string(char *string, size_t sign, size_t len);
size_t				len_for_zeroes(char *string, t_arginfo *info,
	size_t flag_pw, size_t sign);
size_t				free_arg(t_arginfo *info, char *arg);
void				ft_clean_info(t_arginfo *info);
int					flags_checker(t_arginfo *info);
size_t				ft_parse_flags(const char *format,
		t_arginfo *info, size_t i);
double				ft_calc_modul(long double nb, size_t *size);

#endif
