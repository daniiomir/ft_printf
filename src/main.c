/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:42:44 by swarner           #+#    #+#             */
/*   Updated: 2019/05/16 17:42:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main()
{
	printf("1\n");
	ft_printf("2\n");

	printf("%%\n");
	ft_printf("%%\n");

	printf("%s\n", "Hello World");
	ft_printf("%s\n", "Hello World");

	printf("%c\n", 'Y');
	ft_printf("%c\n", 'Y');
}