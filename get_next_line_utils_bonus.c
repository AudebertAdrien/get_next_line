/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:09:37 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/01 09:53:17 by aaudeber         ###   ########.fr       */
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
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	char	*src_cpy;

	src_cpy = (char *)s;
	while (n--)
		*src_cpy++ = '\0';
}

char	*ft_strjoin(char *s, char *b)
{
	char	*ptr;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = ft_strlen(s) + ft_strlen(b);
	ptr = (char *)malloc((sizeof(char) * size) + 1);
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
