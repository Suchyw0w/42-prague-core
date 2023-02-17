/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimals_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:03:55 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/02 10:36:51 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*ft_sharp(t_format f)
{
	if (f.specifier == 'X')
		return ("0X");
	return ("0x");
}

static int	ft_hex(t_format f, unsigned long n, unsigned long found)
{
	int		remain;
	int		count;
	char	c;

	count = 0;
	if (n > 0 || (!found && (f.specifier != 'p' || !f.dot)))
	{
		remain = n % 16;
		if (f.specifier != 'X')
			c = "0123456789abcdef"[remain];
		else
			c = "0123456789ABCDEF"[remain];
		n /= 16;
		found = 1;
		count += ft_hex(f, n, found);
		count += ft_printchar(c);
	}
	return (count);
}

int	ft_case_x(t_format f, va_list args)
{
	unsigned int	n;
	int				count;
	int				len;

	count = 0;
	n = va_arg(args, unsigned int);
	len = ft_nbrlen(n, 16);
	if (!n && !f.precision && f.dot)
		len = 0;
	if (f.precision < 0 || f.precision < len || !f.dot)
		f.precision = len;
	if (f.sharp && n)
		f.width -= 2;
	count += ft_putstrn_fd(ft_sharp(f), 2 * (f.sharp && f.zero && n), 1);
	if (!f.minus && f.width > f.precision && (!f.dot || f.neg_prec) && f.zero)
		count += ft_putnchar_fd('0', (f.width - f.precision), 1);
	else if (!f.minus && f.width > f.precision)
		count += ft_putnchar_fd(' ', (f.width - f.precision), 1);
	count += ft_putstrn_fd(ft_sharp(f), 2 * (f.sharp && !f.zero && n), 1);
	count += ft_putnchar_fd('0', (f.precision - len), 1);
	if (len)
		count += ft_hex(f, n, n);
	if (f.minus && f.width > f.precision)
		count += ft_putnchar_fd(' ', f.width - f.precision, 1);
	return (count);
}

int	ft_case_p(t_format f, unsigned long n)
{
	int		count;
	int		len;

	count = 0;
	len = ft_nbrlen(n, 16);
	len *= !(!n && !f.precision && f.dot);
	if (f.precision < len || !f.dot)
		f.precision = len;
	count += write(1, "0x", 2 * f.zero);
	f.width -= 2;
	if (!f.minus && f.width > f.precision && !f.dot && f.zero)
		count += ft_putnchar_fd('0', (f.width - f.precision), 1);
	else if (!f.minus && f.width > f.precision)
		count += ft_putnchar_fd(' ', (f.width - f.precision), 1);
	count += write(1, "0x", 2 * !f.zero);
	count += ft_putnchar_fd('0', (f.precision - len) * (n != 0), 1);
	count += ft_putnchar_fd('0', f.precision * (f.dot && !n), 1);
	if (len)
		count += ft_hex(f, n, n);
	if (f.minus && f.width > f.precision)
		count += ft_putnchar_fd(' ', f.width - f.precision, 1);
	return (count);
}
