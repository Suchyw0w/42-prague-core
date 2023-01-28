/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:03:20 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/28 22:15:06 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_fill(unsigned int n, char *nb, unsigned int index)
{
	unsigned int	x;

	if (n < 0)
	{
		x = -n;
		nb[0] = '-';
	}
	else
		x = n;
	if (x >= 10)
	{
		ft_fill(x / 10, nb, index - 1);
		ft_fill(x % 10, nb, index);
	}
	if (x < 10)
	{
		x += 48;
		nb[index] = x;
	}
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char		*ans;
	unsigned int	x;
	unsigned int	i;

	x = n;
	i = 0;
	while (x != 0)
	{
		x /= 10;
		i++;
	}
	if (n < 0)
		i++;
	if (n == 0)
		i = 1;
	ans = malloc((i + 1) * sizeof(char));
	if (!ans)
		return (NULL);
	ans[i] = '\0';
	ft_fill(n, ans, i - 1);
	return (ans);
}

static void	ft_puthex(unsigned int n, const char format)
{
	if (n < 16)
	{
		if (n > 9)
		{
			if (format == 'x')
				ft_putchar_fd(n - 10 + 'a', 1);
			if (format == 'X')
				ft_putchar_fd(n - 10 + 'A', 1);
		}
		else
			ft_putchar_fd(n + '0', 1);
	}
	else
	{
		ft_puthex(n / 16, format);
		ft_puthex(n % 16, format);
	}
}

static int	ft_hexlen(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

int	ft_printhex(unsigned int n, const char format)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_puthex(n, format);
	return (ft_hexlen(n));
}
