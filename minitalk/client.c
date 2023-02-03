/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:49:36 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/03 11:20:07 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>
#include <signal.h>
#include "./libft/libft.h"

void	send_bits(char *str, int pid)
{
	int	bits;
	int	i;

	bits = -1;
	i = 0;
	while (str[i])
	{
		while (++bits < 8)
		{
			if (str[i] & (0x80 >> bits))
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(1);
			}
			usleep(3);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if(argc != 3)
	{
		printf("client: invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	send_bits(argv[2], pid);
	return (0);
}
