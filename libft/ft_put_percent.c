/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:47:43 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/10/27 21:07:02 by JEAN-SEBA        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_percent(const char *str, int i, int *pt_count)
{
	int	percent_amount_in_str;
	int	percent_amount_to_print;

	percent_amount_in_str = 0;
	i--;
	while (str[++i] == '%')
		percent_amount_in_str++;
	if (percent_amount_in_str % 2 > 0)
		i--;
	percent_amount_to_print = percent_amount_in_str / 2;
	while (percent_amount_to_print--)
		*pt_count += ft_put_c('%');
	return (i);
}
