/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:56:24 by aaudeber          #+#    #+#             */
/*   Updated: 2023/02/21 16:06:08 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	int		bytes_read;
	int		is_found;
	char	*ptr;
	int		count_char;

	is_found = 0;
	count_char = 0;
	static char	buf[BUFFER_SIZE];
	ptr = malloc(BUFFER_SIZE);
	while (!is_found || bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		ptr = ft_strjoin(ptr, buf);	
		
		if (ft_find_end_line(buf))
		{
			is_found = 1;
			//count_char += ft_find_end_line(buf);
		}
			
		//count_char += bytes_read;
	}

	printf("\n");
	return (buf);
}
