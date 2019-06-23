/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:28:00 by swarner           #+#    #+#             */
/*   Updated: 2019/05/16 17:28:02 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include "../lib/includes/libft.h"

typedef struct		s_arginfo
{
	char	type;
	char 	size[2];
	int 	octotorp;
	int 	minus;
	int 	plus;
	int 	space;
	int 	zero;
	int 	width;
	int 	precision;
}					t_arginfo;

char		*ft_strjoin_free_all(char *s1, char *s2);

int		ft_printf(const char *format, ...);
char	*ft_engine(const char *format, va_list *args);
int		ft_search_helper(const char *string, char search);
size_t	ft_parse(const char *format, t_arginfo *info, size_t i);
size_t	ft_parse_flags(const char *format, t_arginfo *info, size_t i);
size_t	ft_parse_width(const char *format, t_arginfo *info, size_t i);
size_t	ft_parse_precision(const char *format, t_arginfo *info, size_t i);
size_t	ft_parse_size(const char *format, t_arginfo *info, size_t i);
size_t	ft_parse_types(const char *format, t_arginfo *info, size_t i);
char	*handle_flags(t_arginfo *info, va_list *args);

#endif
