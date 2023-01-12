/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:31:02 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/12 16:37:17 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_itoa_fill(long int n, char *nb, int index)
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
		ft_itoa_fill(x / 10, nb, index - 1);
		ft_itoa_fill(x % 10, nb, index);
	}
	if (x < 10)
	{
		x += 48;
		nb[index] = x;
	}
}

char	*ft_itoa(int n)
{
	char		*ret;
	long int	x;
	int			i;
	int			size;

	x = n;
	i = 0;
	while (x != 0)
	{
		x /= 10;
		i++;
	}
	size = i;
	if (n < 0)
	{
		size++;
		x *= -n;
	}
	if (n == 0)
		size = 1;
	ret = malloc((size + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[size] = '\0';
	ft_itoa_fill(n, ret, size - 1);
	return (ret);
}
