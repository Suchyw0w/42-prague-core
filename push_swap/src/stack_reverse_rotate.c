/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:16:50 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/19 10:36:47 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*i;
	t_stack	*prev;

	if (!stack)
		return ;
	if (!(*stack)->next)
		return ;
	i = *stack;
	while (i->next != NULL)
	{
		prev = i;
		i = i->next;
	}
	prev->next = NULL;
	i->next = *stack;
	*stack = i;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
