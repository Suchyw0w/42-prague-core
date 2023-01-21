/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:46:33 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/21 09:22:56 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*ptr;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen((char *)s1);
	j = ft_strlen((char *)s2);
	ptr = malloc((i + j) + 1 * sizeof (char));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}

char	*ft_get_single_line(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	ptr = malloc((i + 2) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

