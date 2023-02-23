/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:56:24 by aaudeber          #+#    #+#             */
/*   Updated: 2023/02/23 17:12:53 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean_stash(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;

	j = 0;
	i = ft_find_byte(stash);
	new_stash = (char *)malloc(sizeof(char *) * (ft_strlen(stash) - i) + 1);
	if (!new_stash)
		return (NULL);
	while (stash[i] != '\n' && stash[i])
	{
		new_stash[j] = stash[i];	
		j++;
		i++;
	}
	new_stash[j] = '\0';
	if (stash)
		free(stash);
	return (new_stash);
}

char	*ft_get_line(char *stash)
{
	char	*line;
	int		i;
	int		j;
	i = ft_find_byte(stash);

	j = 0;
	line = (char *)malloc(sizeof(char *) * i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_read(char *stash, int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			is_found;

	is_found = 0;
	if (!stash)
			stash = "";
	while (!is_found && read(fd, buf, BUFFER_SIZE)) 
	{
		stash = ft_strjoin(stash, buf);
		if (!stash)
			return (NULL);
		is_found = ft_find_byte(stash);
	}
	return (stash);
}

char *get_next_line(int fd)
{
	static char	*stash;
	char	*line;

	stash = ft_read(stash, fd);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);	
	if (!line)
		return (NULL);
	stash = ft_clean_stash(stash);
	if (!stash)
		return (NULL);
	return (line);
}
