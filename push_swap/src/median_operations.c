/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:08:00 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/17 18:09:01 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/push_swap.h"

void	transfer_median(t_stack **a, t_stack **b, int median)
{
	int	size;
	int	i;

	size = get_stack_size(*a);
	i = 1;
	while (i <= size)
	{
		if ((*a)->value < median)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}
