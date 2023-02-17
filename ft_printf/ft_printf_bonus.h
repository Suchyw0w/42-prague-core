/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:04:14 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/02 10:38:41 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_format
{
	int		width;
	int		precision;
	int		space;
	int		neg_prec;
	int		minus;
	int		plus;
	int		zero;
	int		dot;
	char	specifier;
	int		sharp;
}				t_format;

# define DEFAULTS	"cspdiuxX%"

int			ft_printf(const char *str, ...);
int			ft_get_flags(char *str, va_list args);
int			ft_choose_flag(t_format f, va_list args);

int			ft_printchar(char c);
int			ft_putnchar_fd(char c, int n, int fd);
int			ft_putstrn_fd(char *str, int n, int fd);
int			ft_nbrlen(unsigned long n, int divider);

int			ft_case_c(t_format f, va_list args);
int			ft_case_s(t_format f, char *str, int count, int is_allocated);
int			ft_case_i_d_u(t_format f, va_list args);
int			ft_case_p(t_format f, unsigned long n);
int			ft_case_x(t_format f, va_list args);

#endif
