/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 09:16:02 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/21 09:24:05 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

int main()
{
	char	*line;
	int		fd;
	int		i;
	fd = open("", O_RDONLY);
	i = 1;
	while (i < 4)
	{
		line = get_next_line(fd);
		printf("line %d, %s\n", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
