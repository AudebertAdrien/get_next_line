/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:56:24 by aaudeber          #+#    #+#             */
/*   Updated: 2023/02/26 15:14:08 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean_stash(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	new_stash = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i) + 1);
//	new_stash = (char *)ft_calloc((ft_strlen(stash) - i)+1, sizeof(char));
	if (!new_stash)
		return (ft_error(new_stash));
	while (stash[i + j]) 
	{
		new_stash[j] = stash[i + j];
		j++;
	}
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*ft_get_line(char *stash)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	//line = ft_calloc((i + 1), sizeof(char));
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (ft_error(line));
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
	char		*buf;
	int			bytes_read;

	bytes_read = BUFFER_SIZE;
//	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (ft_error(buf));
	while (!ft_strchr(stash, '\n') && bytes_read == BUFFER_SIZE) 
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_error(buf));
		
		buf[bytes_read] = '\0';
		stash = ft_strjoin(stash, buf);
		if (!stash)
			return (ft_error(stash));
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	
	if (!stash)
		stash = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	//	stash = malloc((BUFFER_SIZE) * sizeof(char));
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
