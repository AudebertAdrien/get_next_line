/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:09:37 by aaudeber          #+#    #+#             */
/*   Updated: 2023/02/26 15:11:47 by aaudeber         ###   ########.fr       */
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

char	*ft_error(char *ptr)
{
	free(ptr);
	ptr = NULL;
	return (NULL);
}


char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (*str == (char)c)
		return (str);
	return (0);
}


void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb * size / size != nmemb)
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*src_cpy;

	src_cpy = (unsigned char *)s;
	while (n--)
		*src_cpy++ = '\0';
}



int	ft_find_byte(const char *str)
{
	int	b;

	b = 0;
	while (str[b])
	{
		if (str[b] == '\n')
			return (b + 1);
		b++;
	}
	return (0);
}

char	*ft_strjoin(char *s, char *b)
{
	char	*ptr;
	int	i;
	int	j;

	i = 0;
	j = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + ft_strlen(b)) + 1);
	if (!ptr)
		return (ft_error(ptr));
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
	free(s);
	return (ptr);
}
