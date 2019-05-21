/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlisthead_del.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:04:10 by swarner           #+#    #+#             */
/*   Updated: 2019/05/10 15:04:12 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlisthead_del(t_dlist **head)
{
	t_dlist *temp;

	temp = *head;
	*head = temp->next;
	(*head)->prev = NULL;
	free(temp);
}
