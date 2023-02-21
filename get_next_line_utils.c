/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:09:37 by aaudeber          #+#    #+#             */
/*   Updated: 2023/02/21 11:14:10 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_find_end_line(char *b)
{
	int	i;

	i = 0;
	while (b[i])
	{
		if (b[i] == '\n')
			return (&b[i]);
	}
	return (NULL);
}
