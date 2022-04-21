/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JEAN-SEBA <jcourtem@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 10:08:40 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/07/24 21:19:15 by JEAN-SEBA        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dest, const char *src, size_t dest_size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	if (!dest || !src)
		return (0);
	src_len = ft_strlen(src);
	if (!dest_size)
		return (src_len);
	while (src[i] != '\0' && i < dest_size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (dest_size < src_len)
		dest[dest_size - 1] = '\0';
	else if (dest_size != 0)
		dest[i] = '\0';
	return (src_len);
}
