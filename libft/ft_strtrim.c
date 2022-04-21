/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JEAN-SEBA <jcourtem@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:02:31 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/07/15 05:39:24 by JEAN-SEBA        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isnset(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*rtn;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (ft_isnset(s1[start], set) == 0)
		start++;
	if (start == ft_strlen(s1))
	{
		rtn = ft_strdup("");
		if (!rtn)
			return (NULL);
		else
			return (rtn);
	}
	while (ft_isnset(s1[end - 1], set) == 0)
		end--;
	rtn = ft_substr(s1, start, end - start);
	return (rtn);
}
