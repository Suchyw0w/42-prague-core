/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:44:22 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/13 11:27:38 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "libft.h"

int main()
{
	char x[] = "nice string bro";
	char **ptr;
	ptr = ft_split(x, ' ');
	for (size_t i = 0; i < 3; i++)
	{
		printf("%s" , ptr[i]);
	}

}
