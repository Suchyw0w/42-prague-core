/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:47:09 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/26 14:18:32 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_param(va_list *args, char c, int count)
{
	if (c == 'c')
		count += ft_case_c(args);
	else if (c == 's')
		count += ft_case_s(args);
	else if (c == 'p')
		count += ft_case_p(args);
	else if (c == 'd' || c == 'i')
		count += ft_case_num(args);
	else if (c == 'u')
		count += ft_case_u(args);
	else if (c == 'x')
		count += ft_case_x(args);
	else if (c == 'X')
		count += ft_case_up_x(args);
	else if (c == '%')
		count += ft_case_percent();
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*ptr;
	int		count;
	int		i;

	ptr = (char *)format;
	i = 0;
	count = 0;
	va_start(args, format);
	while (ptr[i])
	{
		if (ptr[i] == '%')
		{
			count = ft_check_param(&args, ptr[i + 1], count);
			i += 2;
		}
		else
		{
			ft_putchar_fd(ptr[i], 1);
			i++;
			count++;
		}
	}
	va_end(args);
	return (count);
}
