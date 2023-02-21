/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:56:24 by aaudeber          #+#    #+#             */
/*   Updated: 2023/02/20 13:28:24 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_get_next_line(int fd)
{
	int		bytes_read;

	static char	buf[BUFFER_SIZE + 1];

	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read == BUFFER_SIZE)
		buf[bytes_read] = '\n';
	
	//printf("bytes_read = %d\n", bytes_read);
	//printf("%s", buf);
	return (buf);
}
