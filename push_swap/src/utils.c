/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:31:23 by osuchane          #+#    #+#             */
/*   Updated: 2023/02/19 10:22:57 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/push_swap.h"

int	*stack_to_array(t_stack *stack)
{
	t_stack	*tmp;
	int		size;
	int		*val;
	int		i;

	if (!stack)
		return (NULL);
	size = get_stack_size(stack);
	val = malloc(sizeof(int) * (size + 1));
	i = 1;
	tmp = stack;
	val[0] = size;
	while (tmp != NULL)
	{
		val[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (val);
}

long	ft_atoi_long(const char *str)
{
	long	convert;
	int		sign;
	int		i;

	convert = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		convert = (convert * 10) + (str[i] - '0');
		i++;
	}
	return (convert * sign);
}

int	check_is_integer(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (j != 0 && argv[i][j] == '-')
				return (0);
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-' &&
			argv[i][j] != ' ')
				return (0);
			j++;
		}
		if (j == 0)
			return (0);
		i++;
	}
	return (1);
}

int	get_stack_size(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	if (!stack)
		return (0);
	tmp = stack;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	get_stack_median(t_stack *stack)
{
	int	val;
	int	*arr;
	int	size;

	arr = stack_to_array(stack);
	size = arr[0];
	bubble_sort(&arr[1], size);
	val = arr[size / 2 + 1];
	free(arr);
	return (val);
}
