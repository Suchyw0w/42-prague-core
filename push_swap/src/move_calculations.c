/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:03:47 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/19 16:05:50 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/push_swap.h"

int	get_closest_move(int i, int size)
{
	if (i <= size / 2)
		return (i);
	else
		return (i - size);
}

/* determine the position where a given value val
should be inserted into a stack a. */
int	get_position_in_a(int val, t_stack *a)
{
	int		i;
	t_stack	*temp;
	t_stack	*prev;
	int		size_a;
	int		stack_min;

	i = get_stack_max_elem(a);
	temp = a->next;
	prev = a;
	size_a = get_stack_size(a);
	stack_min = get_stack_min_elem(a);
	if (val > i)
		return (get_closest_move(get_stack_val_index(a, i), size_a) + 1);
	if (val < stack_min)
		return (get_closest_move(get_stack_val_index(a, stack_min), size_a));
	i = 1;
	while (temp)
	{
		if (temp->value > val && prev->value < val)
			return (get_closest_move(i, size_a));
		prev = temp;
		temp = temp->next;
		i++;
	}
	return (get_closest_move(i, size_a));
}

// calculate the "price" of each move that can be made from stack b to stack a
t_move_price	*get_move_price(t_stack *a, t_stack *b, int *t_size)
{
	t_stack			*temp;
	t_move_price	*ret;
	int				b_size;
	int				i;

	b_size = get_stack_size(b);
	i = 0;
	temp = b;
	ret = malloc(sizeof(t_move_price) * b_size);
	while (temp)
	{
		ret[i].value = temp->value;
		ret[i].move_count[0] = get_position_in_a(temp->value, a);
		if (i <= b_size / 2)
			ret[i].move_count[1] = i;
		else
			ret[i].move_count[1] = i - b_size;
		temp = temp->next;
		i++;
	}
	*t_size = b_size;
	return (ret);
}

// the best move is the one that requires the fewest total moves.
// keeps track of the element with the lowest move score,
// and returns the index of that element in the array
int	pick_best_move(t_move_price *t, int t_size)
{
	int	i;
	int	best;
	int	moves_best;
	int	cm;

	i = 0;
	best = -1;
	moves_best = INT_MAX;
	cm = 0;
	while (i < t_size)
	{
		if (t[i].move_count[0] * t[i].move_count[1] > 0)
		{
			cm = max(abs(t[i].move_count[0]), abs(t[i].move_count[1]));
		}
		else
			cm = abs(t[i].move_count[0]) + abs(t[i].move_count[1]);
		if (cm < moves_best)
		{
			best = i;
			moves_best = cm;
		}
		i++;
	}
	return (best);
}
