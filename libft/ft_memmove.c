/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JEAN-SEBA <jcourtem@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:28:29 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/07/08 13:45:04 by JEAN-SEBA        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*pt_dest;
	const char	*pt_src;
	char		*last_dest;
	const char	*last_src;

	last_dest = dest + (n - 1);
	last_src = src + (n - 1);
	pt_dest = dest;
	pt_src = src;
	if (!dest && !src)
		return (0);
	if (pt_dest < pt_src)
		while (n--)
			*pt_dest++ = *pt_src++;
	else
	{
		while (n--)
			*last_dest-- = *last_src--;
	}
	return (dest);
}
