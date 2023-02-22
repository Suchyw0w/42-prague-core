/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:40:59 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/17 13:06:33 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/push_swap.h"

static void	print_stack(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		printf("Stack is empty\n");
	tmp = stack;
	printf("_\n");
	while (tmp != NULL)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	printf("_\n\n");
}

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc < 2)
		return (0);
	a = init_stack_a(argc, argv);
	b = NULL;
	//small_sort(&a, &b, argc);
	//big_sort(&a, &b);
	print_stack(a);
	print_stack(b);
	free_stack(&a);
	return (0);
}
