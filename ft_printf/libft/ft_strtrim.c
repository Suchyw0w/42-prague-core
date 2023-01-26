/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:28:21 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/18 11:58:52 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_emptystr(void)
{
	char	*ptr;

	ptr = malloc(1 * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[0] = '\0';
	return (ptr);
}

int	ft_is_in_set(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count(char const *s1, char const *set)
{
	int	start;
	int	i;
	int	end;

	start = 0;
	i = 0;
	end = 0;
	while (ft_is_in_set(s1[i], set))
	{
		start++;
		i++;
	}
	while (s1[i])
		i++;
	while (ft_is_in_set(s1[i - end - 1], set) && (i - end - 1) > 0)
		end++;
	return (i - (start + end));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	i = ft_count(s1, set);
	if (i < 1)
		return (ft_emptystr());
	ptr = malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	j = 0;
	k = 0;
	while (ft_is_in_set(s1[j], set))
		j++;
	while (k < i)
	{
		ptr[k] = s1[j + k];
		k++;
	}
	ptr[k] = '\0';
	return (ptr);
}
