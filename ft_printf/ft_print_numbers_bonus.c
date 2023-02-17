/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:04:44 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/02 10:53:29 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*ft_unsigned_itoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_nbrlen(n, 10);
	if (n == 0)
		len = 1;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	while (n > 0)
	{
		str[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str);
}

static char	ft_plus(t_format f)
{
	if (f.plus)
		return ('+');
	return ('-');
}

static int	ft_print_nbr(t_format f, char *str, int len, int isneg)
{
	int	count;

	count = 0;
	f.width -= (f.space && !isneg && !f.plus && f.width);
	if (isneg || f.plus)
		count += ft_putnchar_fd(ft_plus(f), f.zero
				&& (!f.dot || f.neg_prec), 1);
	else if (f.space)
		count += ft_putnchar_fd(' ', !f.zero, 1);
	if (!f.minus && f.width > f.precision && (!f.dot || f.neg_prec) && f.zero)
		count += ft_putnchar_fd('0', f.width - f.precision - isneg - f.plus, 1);
	else if (!f.minus && f.width > f.precision)
		count += ft_putnchar_fd(' ', f.width - f.precision - isneg - f.plus, 1);
	if (isneg || f.plus)
		count += ft_putnchar_fd(ft_plus(f), !f.zero
				|| (f.dot && !f.neg_prec), 1);
	count += ft_putnchar_fd('0', f.precision - len, 1);
	count += write(1, str, len);
	if (f.minus && f.width > f.precision)
		count += ft_putnchar_fd(' ', f.width - f.precision - isneg - f.plus, 1);
	return (count);
}

int	ft_case_i_d_u(t_format f, va_list args)
{
	char	*str;
	int		isneg;
	int		count;
	int		n;
	int		len;

	count = 0;
	n = va_arg(args, int);
	isneg = (n < 0 && f.specifier != 'u');
	if (isneg)
		f.plus = 0;
	if (n < 0 && f.specifier != 'u')
		n *= -1;
	str = ft_unsigned_itoa((unsigned)n);
	len = ft_strlen(str);
	if (*str == '0' && !f.precision && f.dot)
		len = 0;
	if (f.precision < len || !f.dot)
		f.precision = len;
	count += ft_print_nbr(f, str, len, isneg);
	free(str);
	return (count);
}
