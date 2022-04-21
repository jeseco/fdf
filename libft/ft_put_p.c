/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 10:00:58 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/10/28 11:14:28 by JEAN-SEBA        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_p(int j, int i, unsigned int *t, int *pt_count)
{
	while (j-- != 0)
	{
		if (!(t[j] >= 10 && t[j] <= 15))
		{
			ft_putnbr(t[j]);
			i++;
		}
		if (t[j] >= 10 && t[j] <= 15)
			i += ft_put_c('a' + (t[j] - 10));
	}
	*pt_count += i;
}

void	make_p(void *n, int *pt_count)
{
	unsigned long	nb;
	unsigned int	t[100];
	int				j;
	int				i;

	nb = (unsigned long)n;
	j = 0;
	i = 0;
	while (nb >= 16)
	{
		t[j++] = nb % 16;
		nb = nb / 16;
	}
	if (nb >= 10 && nb <= 15)
		i += ft_put_c('a' + (nb - 10));
	if (!(nb >= 10 && nb <= 15))
	{
		ft_putnbr(nb);
		i++;
	}
	print_p(j, i, t, pt_count);
}

void	ft_put_p(va_list ap, int *pt_count)
{
	void	*p;

	p = va_arg(ap, void *);
	write (1, "0x", 2);
	*pt_count += 2;
	if (p == 0)
	{
		*pt_count += ft_put_c('0');
		return ;
	}
	make_p(p, pt_count);
}
