/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:03:35 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/02 10:38:18 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static t_format	ft_innit_struct(void)
{
	t_format	innit;

	innit.precision = 0;
	innit.space = 0;
	innit.specifier = 0;
	innit.dot = 0;
	innit.sharp = 0;
	innit.neg_prec = 0;
	innit.plus = 0;
	innit.minus = 0;
	innit.width = 0;
	innit.zero = 0;
	return (innit);
}

static t_format	ft_parse_flags(char *str, t_format f)
{
	while (*str != '.' && !ft_strchr(DEFAULTS, *str))
	{
		if (*str == '+')
			f.plus = 1;
		if (*str == ' ')
			f.space = 1;
		if (*str == '#')
			f.sharp = 1;
		str++;
	}
	return (f);
}

static t_format	ft_get_width(char *str, va_list args, t_format f)
{
	int	found;

	found = 0;
	while (*str != '.' && !ft_strchr(DEFAULTS, *str))
	{
		if (*str == '-')
			f.minus = 1;
		if (*str == '0' && !ft_isdigit(*(str - 1)))
			f.zero = 1;
		else if (((*str > '0' && *str <= '9') || *str == '*') && !found)
		{
			if (*str == '*')
				f.width = va_arg(args, int);
			else
				f.width = ft_atoi(str);
			found = 1;
		}
		str++;
	}
	return (f);
}

static t_format	ft_parse_precisions(char *str, va_list args, t_format f)
{
	int	found;

	found = 0;
	while (!ft_strchr(DEFAULTS, *str))
	{
		if ((ft_isdigit(*str) || *str == '*') && !found)
		{
			if (*str == '*')
				f.precision = va_arg(args, int);
			else
				f.precision = ft_atoi(str);
			found = 1;
		}
		str++;
	}
	return (f);
}

int	ft_get_flags(char *str, va_list args)
{
	t_format	flags;

	flags = ft_get_width(str, args, ft_innit_struct());
	flags = ft_parse_flags(str, flags);
	while (!ft_strchr(DEFAULTS, *str) && *str != '.')
		str++;
	if (*str == '.' && !flags.specifier)
	{
		flags.dot = 1;
		flags = ft_parse_precisions(str++, args, flags);
		while (!ft_strchr(DEFAULTS, *str))
			str++;
	}
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
	}
	flags.specifier = *str;
	flags.neg_prec = flags.precision < 0;
	return (ft_choose_flag(flags, args));
}
