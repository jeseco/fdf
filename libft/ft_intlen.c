/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 13:10:46 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/10/22 13:55:56 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int x)
{
	int	i;

	i = 0;
	if (x < 0)
	{
		x = -x;
		i++;
	}
	if (x == 0)
		i = 1;
	while (x != 0)
	{
		i++;
		x = x / 10;
	}
	return (i);
}

int	ft_uintlen(unsigned int x)
{
	int	i;

	i = 0;
	if (x == 0)
		return (1);
	while (x != 0)
	{
		i++;
		x = x / 10;
	}
	return (i);
}
