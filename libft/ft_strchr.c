/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:29:53 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/15 16:10:01 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*p;
	int			i;

	if (s == NULL)
		return (NULL);
	i = 0;
	p = s;
	while (p[i])
	{
		if (p[i] == (char) c)
			return ((char *)&p[i]);
		i++;
	}
	if ((char) c == p[i])
		return ((char *)&p[i]);
	return (NULL);
}
