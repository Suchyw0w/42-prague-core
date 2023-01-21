/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:46:31 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/21 09:23:45 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*ft_get_single_line(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);

#endif
