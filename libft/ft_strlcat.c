/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JEAN-SEBA <jcourtem@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:00:53 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/08/03 12:33:21 by JEAN-SEBA        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	char		*pt_dest;
	const char	*pt_src;
	size_t		i;
	size_t		dlen;

	pt_dest = dest;
	pt_src = src;
	i = dest_size;
	while (i-- != '\0' && *pt_dest != '\0')
		pt_dest++;
	dlen = pt_dest - dest;
	i = dest_size - dlen;
	if (i == 0)
		return (dlen + ft_strlen(pt_src));
	while (*pt_src != '\0')
	{
		if (i != 1)
		{
			*pt_dest++ = *pt_src;
			i--;
		}
		pt_src++;
	}
	*pt_dest = '\0';
	return (dlen + (pt_src - src));
}
