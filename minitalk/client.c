/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:49:36 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/05 10:37:52 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_bits	g_bits;

void	ft_char_to_binary(int pid, char c)
{
	int	bits;
	int	i;

	bits = 7;
	i = 0;
	while (i <= 7)
	{
		if ((c >> bits) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		sleep(1);
		while (!g_bits.received_bit)
		{
			pause();
			g_bits.received_bit = 0;
		}
		bits--;
		i++;
	}
}

void	ft_str_to_char(int pid, char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		ft_char_to_binary(pid, str[i]);
		i++;
	}
}

void	ft_received_bit(int signum)
{
	if (signum == SIGUSR2)
		g_bits.received_bit = 1;
}

void	ft_received_message(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_putstr("Message received\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	g_bits.received_bit = 0;
	signal(SIGUSR1, ft_received_message);
	signal(SIGUSR2, ft_received_bit);
	if (argc != 3 || (ft_atoi(argv[1]) < 1) || !argv[2])
		ft_putstr("Client: Error!\n");
	else
		ft_str_to_char(ft_atoi(argv[1]), argv[2]);
	return (0);
}
