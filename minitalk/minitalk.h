/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 01:00:03 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/05 10:36:26 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <strings.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_bits
{
	int	received_bit;
}	t_bits;

void	ft_handle_signal(int signal, siginfo_t *info, void *ucontext);
void	ft_store_recieved_chars(char c, int pid);

void	ft_str_to_char(int pid, char *msg);
void	ft_char_to_binary(int pid, char c);

void	ft_received_bit(int sig);
void	ft_received_message(int sig);

char	*ft_print_str(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);

#endif
