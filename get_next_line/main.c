/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 09:16:02 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/23 14:02:03 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;
	int		fd2;
	int		fd3;
	int		i;
    
	fd = open("test.txt", O_RDONLY);
	//bonus
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
    
	i = 0;
	while (i < 8)
	{
		line = get_next_line(fd);
		printf("line %d: %s", i, line);
		free(line);
		//bonuses
		line = get_next_line(fd2);
		printf("line %d: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line %d: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	close(fd2);
	close(fd3);
	return (0);
}
