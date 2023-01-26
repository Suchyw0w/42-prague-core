/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:57:40 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/26 14:40:23 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_case_num(va_list *args)
{
	int		len;
	char	*str;

	str = ft_itoa(va_arg(*args, int));
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int	ft_case_u(va_list *args)
{
	unsigned int	len;
	char			*str;

	str = ft_unsigned_itoa(va_arg(*args, unsigned int));
	ft_putstr_fd(str, 1);
	len = (unsigned int)ft_strlen(str);
	free(str);
	return (len);
}

static int	ft_create_pointer_address(unsigned long int n, int index)
{
	if (n == 0)
	{
		index += write(1, "(nil)", 5);
		return (index);
	}
	if (index == 0)
		index += write(1, "0x", 2);
	if (n >= 16)
		index = ft_create_pointer_address(n / 16, index);
	index += write(1, &"0123456789abcdef"[n % 16], 1);
	return (index);
}

int	ft_case_p(va_list *args)
{
	int	count;

	count = ft_create_pointer_address(va_arg(*args, unsigned long int), 0);
	return (count);
}
