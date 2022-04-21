/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 10:03:00 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/10/22 13:19:08 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_i(va_list ap)
{
	int	int_to_print;

	int_to_print = va_arg(ap, int);
	if (int_to_print == -2147483648)
	{
		ft_putnbr(-2147483648);
		return (11);
	}
	ft_putnbr(int_to_print);
	return (ft_intlen(int_to_print));
}
