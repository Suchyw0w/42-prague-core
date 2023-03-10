/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:40:59 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/19 10:08:56 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc < 2)
		return (0);
	a = init_stack_a(argc, argv);
	b = NULL;
	sort_small_sizes(&a, &b, argc);
	sort_big_sizes(&a, &b);
	free_stack(&a);
	return (0);
}
