/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JEAN-SEBA <jcourtem@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:12:11 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/07/08 15:10:21 by JEAN-SEBA        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = -1;
	while (++i < (int)ft_strlen(s) + 1)
		if (*(s + i) == (char)c)
			return ((char *)s + i);
	return (NULL);
}
