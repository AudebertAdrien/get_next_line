/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:09:37 by aaudeber          #+#    #+#             */
/*   Updated: 2023/02/21 15:52:38 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

char	*ft_create_ptr(char *s, char *b)
{
	char	*ptr;
	int	i;
	int	j;

	i = 0;
	j = 0;
	ptr = (char *)malloc(sizeof(char *) * (s_len + b_len) + 1);
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
