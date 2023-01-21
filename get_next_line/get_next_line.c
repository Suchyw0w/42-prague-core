/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:46:16 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/21 12:51:47 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_allocate(char *str)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	ptr = malloc((ft_strlen(str) + 1 - i) * sizeof(char));
	if (!ptr)
		return (NULL);
	i++;
	while (str[i])
		ptr[j++] = str[i++];
	ptr[j] = '\0';
	free(str);
	return (ptr);
}

char	*ft_read(int fd, char *str)
{
	char	*buffer;
	int		number_of_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	number_of_bytes = 1;
	while (number_of_bytes != 0 && !ft_strchr(str, '\n'))
	{
		number_of_bytes = read(fd, buffer, BUFFER_SIZE);
		if (number_of_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[number_of_bytes] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_single_line(str);
	str = ft_allocate(str);
	return (line);
}
