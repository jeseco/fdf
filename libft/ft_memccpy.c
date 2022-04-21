/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JEAN-SEBA <jcourtem@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:28:08 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/07/15 05:36:20 by JEAN-SEBA        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*pt_dst;
	const unsigned char	*pt_src;
	size_t				i;

	pt_dst = (unsigned char *)dst;
	pt_src = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		pt_dst[i] = pt_src[i];
		if (pt_src[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
