/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:09:37 by aaudeber          #+#    #+#             */
/*   Updated: 2023/02/21 14:50:57 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_end_line(char *b)
{
	int	i;

	i = 0;
	while (b[i])
	{
		if (b[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

int	ft_count_all_occurence(char c)
{
	int	count;

	count = 0;
	while (read(fd, buf, BUFFER_SIZE))
	{
		if (ft_find_end_line(buf))
			count++;
	}
	return (count);
}
