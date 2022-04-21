/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 10:04:09 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/10/27 16:55:47 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_s(va_list ap, int *pt_count)
{
	char	*s;
	int		i;

	s = va_arg(ap, char *);
	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			write (1, &s[i++], 1);
			*pt_count += 1;
		}
	}
	else
	{
		s = "(null)";
		while (s[i])
		{
			write (1, &s[i++], 1);
			*pt_count += 1;
		}
	}
}
