/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:31:02 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/01 16:03:39 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	get_malloc(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = n * -1;
	if (n == -2147483648)
	{
		n = n + 1;
		n = n * -1;
	}
	while (n / 10 > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char	*handle_negative(char *out, int *n, int *i, int *var)
{
	if (*n == 0)
	{
		out[*i] = '0';
		return (out);
	}
	else if (*n >= -2147483647)
	{
		out[*i] = '-';
		*n = *n * -1;
	}
	else
	{
		out[*i] = '-';
		*n = *n + 1;
		*n = *n * -1;
		*var = 1;
	}
	return (out);
}

static char	*more_itoa(int n, int *var, int i, char *out)
{
	while (var[1] > 0)
	{
		if ((n / var[1]) > 0 || var[0])
		{
			var[0] = 1;
			out[i++] = (n / var[1]) + '0';
			n = n - ((n / var[1]) * var[1]);
		}
		if (var[2])
		{
			var[2] = 0;
			n = n + 1;
		}
		var[1] = var[1] / 10;
	}
	out[i] = '\0';
	return (out);
}

char	*ft_itoa(int n)
{
	int		var[3];
	int		i;
	char	*out;

	i = 0;
	var[0] = 0;
	var[2] = 0;
	if (n < 0)
		out = malloc(get_malloc(n) + 3);
	else
		out = malloc(get_malloc(n) + 2);
	if (!out)
		return (0);
	if (n <= 0)
	{
		out = handle_negative(out, &n, &i, &var[2]);
		i++;
	}
	var[1] = 1000000000;
	return (more_itoa(n, var, i, out));
}
