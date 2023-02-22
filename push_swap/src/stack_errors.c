/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:23:33 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/15 13:37:19 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/push_swap.h"

int	check_duplicates(t_stack *stack, int val)
{
	t_stack	*tmp;
	int		count;

	tmp = stack;
	count = 0;
	while (tmp != NULL)
	{
		if (val == tmp->value)
			count++;
		if (count == 2)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_duplicates_in_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		if (check_duplicates(stack, tmp->value))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	errored(t_stack **a)
{
	free_stack(a);
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	errored_without_notice(t_stack **a)
{
	free_stack(a);
	exit(0);
}
