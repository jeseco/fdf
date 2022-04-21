/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:01:00 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/10/27 20:11:13 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_helper(const char *str, va_list ap, int *pt_count)
{
	int	i;
	int	str_len;

	i = -1;
	str_len = ft_strlen(str);
	while (++i <= str_len)
	{
		if (str[i] == '%' && str[i + 1] != '%')
			ft_check_flag(str[++i], ap, pt_count);
		else if (str[i] == '%' && str[i + 1] == '%')
		{
			i = ft_put_percent(str, i, pt_count);
			if (i < str_len && str[i] != '%')
				*pt_count += ft_put_c((char)str[i]);
			else
				i--;
			continue ;
		}
		if (str[i - 1] != '%' || (str[i] == 32))
			if (i < str_len)
				*pt_count += ft_put_c((char)str[i]);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			*pt_count;
	int			count;

	pt_count = &count;
	*pt_count = 0;
	va_start(ap, str);
	ft_printf_helper(str, ap, pt_count);
	va_end(ap);
	return (count);
}
