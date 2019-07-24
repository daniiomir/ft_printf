/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:28:00 by swarner           #+#    #+#             */
/*   Updated: 2019/07/19 19:51:56 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# define ABS(a)			(a < 0.1) ? -a : a

# include <stdarg.h>
# include "../lib/includes/libft.h"

typedef struct		s_arginfo
{
	char	type;
	char	flag[5];
	char 	size[2];
	size_t 	width;
	size_t 	is_precision;
	size_t 	precision;
}					t_arginfo;

char    *ft_strjoin_null(char *s1, char *s2, size_t *len_for_null);
char	*ft_strjoin_free2(char *s1, char *s2);
char	*ft_strjoin_free_all(char *s1, char *s2);
int		ft_search_helper(const char *string, char search);

int		ft_printf(const char *format, ...);
char	*ft_engine(const char *format, va_list *args, size_t *len_for_null);

size_t	ft_parse(const char *format, t_arginfo *info, size_t i);
size_t	ft_parse_flags(const char *format, t_arginfo *info, size_t i);
size_t	ft_parse_width(const char *format, t_arginfo *info, size_t i);
size_t	ft_parse_precision(const char *format, t_arginfo *info, size_t i);
size_t	ft_parse_size(const char *format, t_arginfo *info, size_t i);
size_t	ft_parse_types(const char *format, t_arginfo *info, size_t i);

char	*handle_flags(t_arginfo *info, va_list *args, size_t *len_for_null);
char	*handle_zero(char *string, t_arginfo *info, size_t flag_pw);
char	*handle_space(char *string, t_arginfo *info, size_t *len_for_null);
char	*handle_plus(char *string);
char	*handle_octotorp(char *string, t_arginfo *info);
char	*handle_minus(char *string, t_arginfo *info);

char	*handle_string_precision(char *string, t_arginfo *info);
char	*get_arg(t_arginfo *info, va_list *args, size_t *len_for_null);
char	*type_f(va_list *args, t_arginfo *flags);
#endif
