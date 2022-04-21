/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JEAN-SEBA <jcourtem@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:34:36 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/07/08 15:32:43 by JEAN-SEBA        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	new_str = malloc(sizeof(char) * len + 1);
	if (!new_str)
		return (0);
	while (i < len)
	{
		new_str[i] = *(s + start + i);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
