/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:48:49 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/17 12:53:16 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "./../libft/libft.h"

typedef struct s_stack {
	int				value;
	struct s_stack	*next;
}	t_stack;

//init
t_stack	*init_stack_a(int argc, char **argv);

//stack operations
void	add_to_stack(t_stack **stack, int value);
void	reverse_stack(t_stack **stack);
t_stack *new_stack(int value);

//swap

//push

//rotate

//reverse rotate

//parse
void	parse(t_stack **a, int argc, char **argv);
void	reverse_parse(t_stack **a, char *argv);

//checks
int	check_duplicates_in_stack(t_stack *stack);
int	check_duplicates(t_stack *stack, int val);
int	check_is_integer(int argc, char **argv);
int	check_sorted(t_stack *stack);

//free
void	double_free(char **ptr, size_t size);
void	free_stack(t_stack **stack);

//errors
void	errored(t_stack **a);
void	errored_without_notice(t_stack **a);

//utils
long	ft_atoi_long(const char *str);

#endif
