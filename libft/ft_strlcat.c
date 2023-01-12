/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:54:41 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/12 14:06:59 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	ans;

	i = 0;
	while (!(dst == NULL && size == 0) && dst[i] && i < size)
		i++;
	j = 0;
	while (!(src == NULL && size == 0) && src[j])
		j++;
	if (size > i)
		ans = i + j;
	else
		ans = size + j;
	j = 0;
	while (size != 0 && src[j] && (i < size - 1))
		dst[i++] = src[j++];
	if (size > i)
		dst[i] = '\0';
	return (ans);
}
