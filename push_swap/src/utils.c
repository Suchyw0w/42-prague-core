/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:31:23 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/16 09:00:58 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/push_swap.h"

long	ft_atoi_long(const char *str)
{
	long	convert;
	int		sign;
	int		i;

	convert = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		convert = (convert * 10) + (str[i] - '0');
		i++;
	}
	return (convert * sign);
}

int	check_is_integer(int argc, char **argv)
{
	int i;
	int j;
	int min;

	i = 1;
	while (i < argc)
	{
		j = 0;
		min = 0;
		while (argv[i][j])
		{
			if (j != 0 && argv[i][j] == '-')
				return (0);
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-' && argv[i][j] != ' ')
				return (0);
			j++;
		}
		if (j == 0)
			return (0);
		i++;
	}
	return (1);
}
