/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:56:24 by aaudeber          #+#    #+#             */
/*   Updated: 2023/02/23 12:08:56 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd)
{
	static char	*stash;
	char		buf[BUFFER_SIZE + 1];
	int			bytes_read;
	int			is_found;

	is_found = 0;
	while (!is_found)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (!stash)
			stash = "";
		stash = ft_strjoin(stash, buf);
		is_found = ft_finds_byte_end_line(stash);	
		
		if (!stash)
			return (NULL);

		if (is_found)
			is_found = 1;
	}
	return (stash);
}

char *get_next_line(int fd)
{
	return(ft_read(fd));
}
/*
char *get_next_line(int fd)
{
	int		bytes_read;
	int		is_found;
	char	buf[BUFFER_SIZE + 1];
	char	*ptr;

	static char	*save;
	is_found = 0;
	while (!is_found || bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		is_found = ft_finds_byte_end_line(buf);	

		if (save)
		{
			ptr = ft_strjoin(save, buf);

		}
		
		if (is_found)
		{
			save = ft_substr(buf, is_found, bytes_read);
			ptr = ft_strjoin(ptr, ft_substr(buf, 0, is_found));
			return (ptr);
		}	

		ptr = ft_strjoin(ptr, buf);
		if (!ptr)
			return (NULL);
	}

	printf("\n");
	return (ptr);
}
*/
