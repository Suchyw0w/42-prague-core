/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:33:48 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/14 08:42:29 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			count;
	char			*ptr;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		ptr = malloc(sizeof(char));
		if (!ptr)
			return (NULL);
		ptr[0] = 0;
		return (ptr);
	}
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	count = 0;
	while (count < len)
	{
		ptr[count] = s[start + count];
		count++;
	}
	ptr[count] = '\0';
	return (ptr);
}
