/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:31:02 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/13 09:58:59 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static void	ft_fill(long int n, char *nb, int index)
{
	long int	x;

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

char	*ft_itoa(int n)
{
	char		*ans;
	long int	x;
	int			i;

	x = n;
	i = 0;
	while (x != 0)
	{
		x /= 10;
		i++;
	}
	if (n < 0)
	{
		i++;
		x *= -n;
	}
	if (n == 0)
		i = 1;
	ans = malloc((i + 1) * sizeof(char));
	if (!ans)
		return (NULL);
	ans[i] = '\0';
	ft_fill(n, ans, i - 1);
	return (ans);
}
