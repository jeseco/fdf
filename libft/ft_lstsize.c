/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JEAN-SEBA <jcourtem@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 03:52:09 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/07/15 05:32:21 by JEAN-SEBA        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	unsigned int	list_size;

	if (!lst)
		return (0);
	list_size = 0;
	while (lst)
	{
		lst = lst->next;
		list_size++;
	}
	return (list_size);
}
