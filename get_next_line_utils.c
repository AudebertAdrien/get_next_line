/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:09:37 by aaudeber          #+#    #+#             */
/*   Updated: 2023/02/23 14:59:24 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_find_byte(const char *b)
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

char	*ft_strjoin(const char *s, const char *b)
{
	char	*ptr;
	int	i;
	int	j;

	i = 0;
	j = 0;
	ptr = (char *)malloc(sizeof(char *) * (ft_strlen(s) + ft_strlen(b)) + 1);
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i]; 
		i++;
	}
	while (b[j])
	{
		ptr[i + j] = b[j]; 
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}
