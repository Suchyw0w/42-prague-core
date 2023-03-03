/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_sizes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:11:06 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/19 16:08:15 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/push_swap.h"

// picking move
void	pick_sub(t_move_price *t, t_stack **a, t_stack **b)
{
	if (t->move_count[0] > 0)
	{
		ra(a);
		t->move_count[0] -= 1;
	}
	if (t->move_count[0] < 0)
	{
		rra(a);
		t->move_count[0] += 1;
	}
	if (t->move_count[1] > 0)
	{
		rb(b);
		t->move_count[1] -= 1;
	}
	if (t->move_count[1] < 0)
	{
		rrb(b);
		t->move_count[1] += 1;
	}
}

// repeatedly executes rotations of both stacks
// until the move_count values in the t_move_price structure are zeroed out.
void	pick_move(t_move_price t, t_stack **a, t_stack **b)
{
	while (t.move_count[0] != 0 || t.move_count[1] != 0)
	{
		if (t.move_count[0] > 0 && t.move_count[1] > 0)
		{
			rr(a, b);
			t.move_count[0] -= 1;
			t.move_count[1] -= 1;
		}
		else if (t.move_count[0] < 0 && t.move_count[1] < 0)
		{
			rrr(a, b);
			t.move_count[0] += 1;
			t.move_count[1] += 1;
		}
		else
			pick_sub(&t, a, b);
	}
	pa(a, b);
}

void	sort_big_sizes(t_stack **a, t_stack **b)
{
	int				size;
	int				i;
	int				size_a;
	t_move_price	*t;

	if (check_sorted(*a))
		return ;
	move_list_to_b(a, b);
	while (*b)
	{
		t = get_move_price(*a, *b, &size);
		i = pick_best_move(t, size);
		pick_move(t[i], a, b);
		free(t);
	}
	size_a = get_stack_size(*a);
	if (get_stack_val_index(*a, get_stack_max_elem(*a)) <= size_a / 2)
		while (get_stack_val_index(*a, get_stack_max_elem(*a)) != size_a - 1)
			ra(a);
	else
		while (get_stack_val_index(*a, get_stack_max_elem(*a)) != size_a - 1)
			rra(a);
}
