/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:44:37 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/15 16:02:27 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	detect_whitespaces_and_get_sign(const char *str, int *ptr_i)
{
	int	count;
	int	i;
	int	y;

	i = 0;
	count = 1;
	y = 0;
	// Iterate through the input string, starting at the first character, and continue as long as the current character is a whitespace character (ascii value between 9 and 13 inclusive or ascii value of 32)
    // This loop is effectively skipping over any leading whitespace characters in the input string.
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	// checks for the presence of a sign (+ or -) in the input string and updates the `count` variable accordingly.
	// It also checks that the next character is a digit (ascii value between 48 and 57 inclusive) to ensure that it is a valid number.
    // If the variable `y` is equal to 1, the function returns 0, otherwise it increments the variable y. 
	while (str[i] && (str[i] == 43 || str[i] == 45)
		&& (str[i + 1] >= 48 && str[i + 1] <= 57))
	{
		if (str[i] == 45)
			count *= -1;
		if (y == 1)
			return (0);
		y++;
		i++;
	}
	*ptr_i = i;
	return (count);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	i;

    //call detect_whitespaces_and_get_sign function to get the sign of the number 
	//and the starting index of the actual number in the input string
	result = 0;
	sign = detect_whitespaces_and_get_sign(str, &i);
	//convert the string of digits to a numerical value by multiplying the current result by 10 and adding the current digit
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10;
		result = result + str[i] - 48;
		i++;
	}
	result *= sign;
	if (result > INT_MAX)
		return (INT_MAX);
	else if (result < INT_MIN)
		return (INT_MIN);
	return (result);
}
