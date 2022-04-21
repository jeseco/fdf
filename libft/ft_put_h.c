/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_h.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 10:08:19 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/10/28 10:37:57 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	make_hex(unsigned long long va, int *hex)
{
	int	j;

	j = 0;
	while (va >= 16)
	{
		*(hex + j) = va % 16;
		va = va / 16;
		j++;
	}
	*(hex + j) = va;
	return (j + 1);
}

void	ft_put_upperh(va_list ap, int *pt_count)
{
	int				t[7];
	int				j;
	unsigned int	va;

	va = va_arg(ap, unsigned int);
	j = 0;
	if (va >= 10)
		j = make_hex(va, t);
	else
	{
		ft_putnbr(va);
		*pt_count += 1;
	}
	while (j-- != 0)
	{
		if (!(t[j] >= 10 && t[j] <= 15))
		{	
			ft_putnbr(t[j]);
			*pt_count += 1;
		}	
		else
			*pt_count += ft_put_c('A' + (t[j] - 10));
	}
}

void	ft_put_h(va_list ap, int *pt_count)
{
	int				hex[7];
	int				j;
	unsigned int	va;

	va = va_arg(ap, unsigned int);
	j = 0;
	if (va >= 10)
		j = make_hex(va, hex);
	else
	{
		ft_putnbr(va);
		*pt_count += 1;
	}
	while (j-- != 0)
	{
		if (!(hex[j] >= 10 && hex[j] <= 15))
		{	
			ft_putnbr(hex[j]);
			*pt_count += 1;
		}	
		else
			*pt_count += ft_put_c('a' + (hex[j] - 10));
	}
}
