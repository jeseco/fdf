/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 10:06:02 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/10/27 18:40:57 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_u(va_list ap, int *pt_count)
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	if (u >= 10)
	{
		ft_putnbr(u / 10);
		ft_putnbr(u % 10);
	}
	else
	{
		*pt_count += ft_put_c(u + '0');
		return ;
	}
	*pt_count += ft_uintlen(u);
}
