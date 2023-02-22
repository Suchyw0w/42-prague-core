/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:15:09 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/15 13:53:18 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/push_swap.h"

t_stack *new_stack(int value)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	new->value = value;
	new->next = NULL;
	return (new);
}

void	add_to_stack(t_stack **stack, int value)
{
	t_stack	*new;

	new = new_stack(value);
	new->next = *stack;
	*stack = new;
}

void	reverse_stack(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*current;
	t_stack	*next;

	prev = NULL;
	current = *stack;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*stack = prev;
}
