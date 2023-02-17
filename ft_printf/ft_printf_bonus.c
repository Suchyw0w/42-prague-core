/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:04:23 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/02 10:54:05 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_nbrlen(unsigned long n, int divider)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n /= divider;
	}
	return (i);
}

int	ft_choose_flag(t_format f, va_list args)
{
	int				count;
	int				is_allocated;
	unsigned long	ptr;

	count = 0;
	is_allocated = 0;
	if (f.specifier == 'c' || f.specifier == '%')
		return (ft_case_c(f, args));
	if (f.specifier == 's')
		return (ft_case_s(f, va_arg(args, char *), count, is_allocated));
	if (f.specifier == 'd' || f.specifier == 'i'
		|| f.specifier == 'u')
		return (ft_case_i_d_u(f, args));
	if (f.specifier == 'x' || f.specifier == 'X')
		return (ft_case_x(f, args));
	if (f.specifier == 'p')
	{
		ptr = va_arg(args, unsigned long);
		if (ptr)
			return (ft_case_p(f, ptr));
		else
			return (ft_case_s(f, "(nil)", 0, 0));
	}
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;
	char	*first_occur;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			first_occur = (char *)str;
			if (*(++str))
				count += ft_get_flags((char *)str, args);
			while (*str && !ft_strchr(DEFAULTS, *str))
				str++;
			if (!(*str))
				str = first_occur;
		}
		else
			count += ft_printchar(*str);
		if (*str)
			str++;
	}
	va_end(args);
	return (count);
}
