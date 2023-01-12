/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:44:28 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/12 11:09:10 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*psrc;
	unsigned char		*pdest;

	i = 0;
	psrc = src;
	pdest = dest;
	while (n--)
	{
		pdest[i] = psrc[i];
		i++;
	}
	return (dest);
}
