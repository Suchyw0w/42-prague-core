/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:39:41 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/19 10:20:50 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*next;

	if (!stack)
		return ;
	temp = *stack;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	*stack = NULL;
}

void	double_free(char **ptr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	free_multiple(int n, ...)
{
	va_list	args;
	int		i;
	void	*p;

	va_start(args, n);
	i = 0;
	while (i < n)
	{
		p = va_arg(args, void *);
		free(p);
		i++;
	}
	va_end(args);
}
