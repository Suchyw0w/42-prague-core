/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:44:28 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/15 16:08:44 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*d;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	d = dst;
	i = 0;
	while (n > i)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (d);
}
