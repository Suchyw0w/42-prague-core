/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:43:45 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/15 16:10:42 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;
	char		*last;
	int			i;

	if (s == NULL)
		return (NULL);
	p = s;
	last = NULL;
	i = 0;
	while (p[i])
	{
		if (p[i] == (char)c)
			last = (char *)&p[i];
		i++;
	}
	if ((char)c == p[i])
		last = (char *)&p[i];
	return (last);
}
