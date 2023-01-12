/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:33:48 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/12 16:27:39 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static unsigned int	ft_strlen(char const *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		x++;
	}
	return (x);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			count;
	char			*ptr;

	if (s == NULL)
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
	while (s[start] && count < len)
	{
		ptr[count] = s[start];
		count++;
		start++;
	}
	ptr[count] = '\0';
	return (ptr);
}
