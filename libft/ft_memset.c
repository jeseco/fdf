/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JEAN-SEBA <jcourtem@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:28:54 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/05/26 10:28:59 by JEAN-SEBA        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*str, int c, size_t len)
{
	char	*pt_str;

	pt_str = str;
	while (len-- > 0)
		*pt_str++ = (unsigned char) c;
	return (str);
}
