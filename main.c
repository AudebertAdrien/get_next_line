/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:56:24 by aaudeber          #+#    #+#             */
/*   Updated: 2023/02/28 10:30:46 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>


int	test(char *fileName)
{
	int fd;
	printf("\nFILE:%s\n", fileName);
	fd = open(fileName, O_RDONLY);

	if (fd == -1)
	{
		printf("NOT FOUND: %d", fd);
		return (0);
	}

	char	*line;
	int	i = 1;
	
	while (1)
	{
		line = get_next_line(fd);	
		if (!line)
			break;
		printf("Line : %d => %s", i, line);
		free(line);
		i++;
	}

	if (close(fd) == -1)
		return (0);
	return (0);
}

int	main(void)
{
	/*
	char* home = getenv("HOME");
	char* path = "/Programation/42cursus/get_next_line/files";
	char* test = "/test";

	size_t len = strlen(home) + strlen(path) + strlen(test) + 1;
	char* fullpath = malloc(len);

	strcpy(fullpath, home);
	strcat(fullpath, path);
	strcat(fullpath, test);
	*/

	test("test");
	test("text_no_line");

	return (0);
}
