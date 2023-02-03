/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:49:39 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/03 12:02:19 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "./libft/libft.h"

void	get_signal(int signal)
{
	static int bits = 0;
	static char c = 0xFF;

	if (signal == SIGUSR1)
	{
		printf("0");
	}
	else if (signal == SIGUSR2)
	{
		printf("1");
	}
	bits++;
	if (bits == 8)
	{
		printf("%c\n", c);
		bits = 0;
		c = 0xFF;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID: %d\n", pid);
	signal(SIGUSR1, get_signal);
	signal(SIGUSR2, get_signal);
	while(1)
		sleep(1);
}
