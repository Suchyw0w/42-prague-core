/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:05:53 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/14 08:36:13 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = 0;
	while (big[i] && i < len && len > 0)
	{
		j = 0;
		while (little[j] && (little[j] == big[i + j] && i + j < len))
			j++;
		if (little[j] == 0)
			return (&((char *)big)[i]);
		i++;
	}
	return (NULL);
}
