/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:29:49 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/15 16:09:57 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill(char **mem, char const *s, char c)
{
	char		**mem_ptr;
	char const	*temp;

	temp = s;
	mem_ptr = mem;
	while (*temp)
	{
		while (*s == c)
			s++;
		temp = s;
		while (*temp != c && *temp)
		{
			temp++;
		}
		if (*temp == c || temp > s)
		{
			*mem_ptr = ft_substr(s, 0, temp - s);
			s = temp;
			mem_ptr++;
		}
	}
	*mem_ptr = NULL;
}

static int	ft_countwords(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		w_len;

	w_len = ft_countwords(s, c);
	ptr = malloc((w_len + 1) * sizeof (char *));
	if (!ptr || !s)
		return (0);
	ft_fill(ptr, s, c);
	return (ptr);
}
