/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:33:35 by jcourtem          #+#    #+#             */
/*   Updated: 2022/04/08 11:36:27 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// [ ] clean this shit! 
#include <stdio.h>

#include <mlx.h>

#include "../includes/fdf.h"

int	absolute(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
