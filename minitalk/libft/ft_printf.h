/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:21:11 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/01 11:56:58 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "./libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_check_param(va_list *args, char c, int count);
int		ft_case_c(va_list *args);
int		ft_case_s(va_list *args);
int		ft_case_percent(void);

int		ft_case_num(va_list *args);
int		ft_case_u(va_list *args);
int		ft_case_up_x(va_list *args);
int		ft_case_x(va_list *args);
int		ft_case_p(va_list *args);
char	*ft_unsigned_itoa(unsigned int n);
int		ft_printhex(unsigned int n, const char format);

#endif
