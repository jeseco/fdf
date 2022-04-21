/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JEAN-SEBA <jcourtem@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:31:57 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/07/08 13:48:24 by JEAN-SEBA        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	const char	*pt_char;
	size_t		i;

	i = -1;
	pt_char = (const char *)s;
	while (++i < n)
		if (*(pt_char + i) == (char)c)
			return ((void *)pt_char + i);
	return (NULL);
}
