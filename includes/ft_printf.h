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

int		ft_printf(const char *format, ...);
char	*ft_engine(const char *format, va_list *args);
char	*ft_parse_args(const char *format, va_list *args, size_t i);


#endif
