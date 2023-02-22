/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:49:39 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/05 10:27:59 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_store_recieved_chars(char c, int pid)
{
	static char	*str = NULL;
	char		*dest;
	int			i;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!dest)
		return ;
	if (str)
	{
		while (str[i])
		{
			dest[i] = str[i];
			i++;
		}
		free(str);
	}
	dest[i++] = c;
	dest[i] = '\0';
	str = ft_strdup(dest);
	if (!c)
	{
		str = ft_print_str(str);
		kill(pid, SIGUSR1);
	}
}

void	ft_handle_signal(int signal, siginfo_t *info, void *ucontext)
{
	static unsigned char	c = 0;
	static unsigned char	bit = 128;

	(void)ucontext;
	if (signal == SIGUSR1)
		c |= bit;
	if (bit == 1)
	{
		ft_store_recieved_chars(c, info->si_pid);
		c = 0;
		bit = 128;
	}
	else
		bit /= 2;
	kill(info->si_pid, SIGUSR2);
}

char	*ft_print_str(char *str)
{
	if (str != NULL)
	{
		ft_putstr(str);
		ft_putchar('\n');
		free(str);
	}
	return (NULL);
}

int	main(void)
{
	int					pid;
	struct sigaction	data;

	pid = getpid();
	printf("PID: %d\n", pid);
	data.sa_sigaction = ft_handle_signal;
	data.sa_flags = SA_SIGINFO;
	sigemptyset(&data.sa_mask);
	sigaction(SIGUSR1, &data, NULL);
	sigaction(SIGUSR2, &data, NULL);
	while (1)
		pause();
}
