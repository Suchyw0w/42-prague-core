/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:28:21 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/13 15:43:59 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

int	ft_ischar(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_trim(char const *s1, char const *set, int *j, int i)
{
	int		k;
	int		len;
	char	*ptr;

	len = ft_strlen((char *)s1);
	k = 0;
	while (ft_ischar(s1[len - k - 1], set))
		00k++;
	ptr = ft_calloc(sizeof(char), len - (k + i) + 1);
	if (!ptr)
		return (NULL);
	while (*j < len - (k + i))
	{
		*(ptr + *j) = *(s1 + i + *j);
		*j += 1;
	}
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*ptr;

	if (!s1)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen((char *)s1);
	while (ft_ischar(s1[i], set))
		i++;
	if (i == len)
		ptr = malloc(1);
	else
		ptr = ft_trim(s1, set, &j, i);
	if (ptr)
		ptr[i + j] = '\0';
	return (ptr);
}
