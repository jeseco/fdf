/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 10:00:30 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/10/27 16:50:02 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

void	ft_check_flag(const char flag, va_list ap, int *pt_count)
{	
	if (flag == 'c')
		*pt_count += ft_put_c(va_arg(ap, int));
	else if (flag == 'd' || flag == 'i')
		*pt_count += ft_put_i(ap);
	else if (flag == 'p')
		ft_put_p(ap, pt_count);
	else if (flag == 's')
		ft_put_s(ap, pt_count);
	else if (flag == 'u')
		ft_put_u(ap, pt_count);
	else if (flag == 'x')
		ft_put_h(ap, pt_count);
	else if (flag == 'X')
		ft_put_upperh(ap, pt_count);
}
