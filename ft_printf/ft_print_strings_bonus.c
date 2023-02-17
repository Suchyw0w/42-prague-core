/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strings_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:02:29 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/02 10:21:05 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putstrn_fd(char *str, int n, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && i < n)
		write(fd, &str[i++], 1);
	return (n);
}

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnchar_fd(char c, int n, int fd)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(fd, &c, 1);
		i++;
	}
	return (n);
}

int	ft_case_c(t_format f, va_list args)
{
	int		count;
	char	c;

	count = 0;
	if (f.specifier == 'c')
		c = va_arg(args, int);
	else
		return (ft_printchar('%'));
	f.precision = 1;
	if (!f.minus && f.zero)
		count += ft_putnchar_fd('0', f.width - f.precision, 1);
	else if (!f.minus && f.width > f.precision)
		count += ft_putnchar_fd(' ', f.width - f.precision, 1);
	count += ft_printchar(c);
	if (f.minus && f.width - f.precision > 0)
		count += ft_putnchar_fd(' ', f.width - f.precision, 1);
	return (count);
}

int	ft_case_s(t_format f, char *str, int count, int is_allocated)
{
	if (str == NULL && f.dot && f.precision == 1)
		return (ft_putnchar_fd(' ', (f.width - f.precision) + 1, 1));
	else if (str == NULL && f.precision > 0 && f.precision < 6)
		return (0);
	if (!str)
	{
		str = malloc(7);
		is_allocated = 1;
		ft_strlcpy(str, "(null)", 7);
	}
	if (!f.dot || f.precision > (int)ft_strlen(str) || f.precision < 0)
		f.precision = ft_strlen(str);
	if (!f.minus && f.width > f.precision && f.zero && (!f.dot || f.neg_prec))
		count += ft_putnchar_fd('0', f.width - f.precision, 1);
	else if (!f.minus && f.width - f.precision > 0)
		count += ft_putnchar_fd(' ', f.width - f.precision, 1);
	count += ft_putstrn_fd(str, f.precision, 1);
	if (f.minus && f.width - f.precision > 0)
		count += ft_putnchar_fd(' ', f.width - f.precision, 1);
	if (is_allocated)
		free(str);
	return (count);
}
