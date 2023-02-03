/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:44:37 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/18 11:57:58 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	detect_whitespaces_and_get_sign(const char *str, int *ptr_i)
{
	int	count;
	int	i;
	int	y;

	i = 0;
	count = 1;
	y = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] && (str[i] == 43 || str[i] == 45)
		&& (str[i + 1] >= 48 && str[i + 1] <= 57))
	{
		if (str[i] == 45)
			count *= -1;
		if (y == 1)
			return (0);
		y++;
		i++;
	}
	*ptr_i = i;
	return (count);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	i;

	result = 0;
	sign = detect_whitespaces_and_get_sign(str, &i);
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10;
		result = result + str[i] - 48;
		i++;
	}
	result *= sign;
	if (result > INT_MAX)
		return (INT_MAX);
	else if (result < INT_MIN)
		return (INT_MIN);
	return (result);
}
