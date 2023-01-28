/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strings_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:05:27 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/28 22:05:33 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_case_c(va_list *args)
{
	ft_putchar_fd(va_arg(*args, int), 1);
	return (1);
}

int	ft_case_s(va_list *args)
{
	char	*str;
	int		str_len;

	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	str_len = ft_strlen(str);
	return (str_len);
}

int	ft_case_percent()
{
	ft_putchar_fd('%', 1);
	return (1);
}

int	ft_case_x(va_list *args)
{
	int	count;

	count = ft_printhex(va_arg(*args, unsigned int), 'x');
	return (count);
}

int	ft_case_up_x(va_list *args)
{
	int	count;

	count = ft_printhex(va_arg(*args, unsigned int), 'X');
	return (count);
}
