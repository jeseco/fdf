/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:42:15 by jcourtem          #+#    #+#             */
/*   Updated: 2022/01/26 10:18:44 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft.h"

char	*get_next_line(int fd);
char	*gnl_strchr(char *s, char c);
char	*gnl_strcat(char *dest, char *src);
void	gnl_memmove(char *dest, char*src, int size);

#endif 
