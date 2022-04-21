/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JEAN-SEBA <jcourtem@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:48:32 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/07/08 13:53:38 by JEAN-SEBA        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*pt_s1;
	const unsigned char	*pt_s2;
	size_t				i;

	i = -1;
	pt_s1 = (unsigned char *)s1;
	pt_s2 = (unsigned char *)s2;
	while (++i < n && *(pt_s1 + i) == *(pt_s2 + i))
		;
	if (i == n)
		return (0);
	return (*(pt_s1 + i) - *(pt_s2 + i));
}
