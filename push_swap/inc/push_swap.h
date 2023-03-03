/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:48:49 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/19 10:36:44 by osuchane         ###   ########.fr       */
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

typedef struct s_move_price
{
	int	move_count[2];
	int	value;
}	t_move_price;

//init
t_stack			*init_stack_a(int argc, char **argv);

//stack operations
void			add_to_stack(t_stack **stack, int value);
void			reverse_stack(t_stack **stack);
t_stack			*new_stack(int value);

//swap
void			swap(t_stack **stack);
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);

//push
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **a, t_stack **b);

//rotate
void			rotate(t_stack **stack);
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);

//reverse rotate
void			reverse_rotate(t_stack **stack);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);

//parse
void			parse(t_stack **a, int argc, char **argv);
void			reverse_parse(t_stack **a, char *argv);

//checks
int				check_duplicates_in_stack(t_stack *stack);
int				check_duplicates(t_stack *stack, int val);
int				check_is_integer(int argc, char **argv);
int				check_sorted(t_stack *stack);

// Sorts
void			sort_small_sizes(t_stack **a, t_stack **b, int argc);
void			sort_big_sizes(t_stack **a, t_stack **b);
void			sort_two_values(t_stack **a);
void			reverse_sort_two_values(t_stack **b);
void			sort_three_values(t_stack **a);
void			reverse_sort_three_values(t_stack **b);
void			sort_four_to_six_values(t_stack **a, t_stack **b);
void			bubble_sort(int *arr, int n);
void			transfer_median(t_stack **a, t_stack **b, int median);

//free
void			double_free(char **ptr, size_t size);
void			free_stack(t_stack **stack);
void			free_multiple(int n, ...);

//errors
void			errored(t_stack **a);
void			errored_without_notice(t_stack **a);

// calculations
t_move_price	*get_move_price(t_stack *a, t_stack *b, int *t_size);
int				pick_best_move(t_move_price *t, int t_size);
int				get_stack_max_elem(t_stack *stack);
int				get_stack_min_elem(t_stack *stack);
int				get_stack_val_index(t_stack *stack, int val);
int				get_position_in_a(int val, t_stack *a);
int				get_closest_move(int i, int size);
void			pick_move(t_move_price t, t_stack **a, t_stack **b);
void			pick_sub(t_move_price *t, t_stack **a, t_stack **b);

// Math
int				abs(int a);
int				max(int a, int b);
int				min(int a, int b);

//utils
long			ft_atoi_long(const char *str);
int				get_stack_size(t_stack *stack);
int				get_stack_median(t_stack *stack);
int				*stack_to_array(t_stack *stack);
void			move_list_to_b(t_stack **a, t_stack **b);
int				*get_list(int *arr, int size, int *list_size, int i);
int				int_in_arr(int n, int *arr, int size);
t_stack			*copy_stack(t_stack *src);
void			put_min_element_on_top(t_stack **stack);
int				*list_sub(int size, int list_length, int *arr, int *index);

#endif
