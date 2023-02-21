/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:56:24 by aaudeber          #+#    #+#             */
/*   Updated: 2023/02/21 16:36:37 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	int		bytes_read;
	int		is_found;
	char	*ptr;
	static char	buf[BUFFER_SIZE];

	is_found = 0;
	while (!is_found || bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		ptr = ft_strjoin(ptr, buf);	
		if (!ptr)
			return (NULL);
		
		if (ft_find_end_line(buf))
		{
			is_found = 1;
		}
	}

	printf("\n");
	return (ptr);
}
