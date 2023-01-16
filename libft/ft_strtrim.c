/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osuchane <osuchane@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:28:21 by osuchane          #+#    #+#             */
/*   Updated: 2023/01/15 16:43:36 by osuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_emptystr(void)
{
	char	*ptr;

	// Allocate memory for a single character
	ptr = malloc(1 * sizeof(char));
	if (!ptr)
		return (NULL);
	// Assign null character to the allocated memory
	ptr[0] = '\0';
	return (ptr);
}

int	ft_is_in_set(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	// Loop as long as current character of set is not null
	while (set[i])
	{
		// Check if the current character is equal to the character in the set
		if (c == set[i])
			return (1); // If the characters match, return 1
		i++;
	}
	return (0);  // If the loop completes without finding a match, return 0
}

int	ft_count(char const *s1, char const *set)
{
	int	start;
	int	i;
	int	end;

	start = 0;
	i = 0;
	end = 0;
	while (ft_is_in_set(s1[i], set)) // Loop as long as the current character of s1 is in the set
	{
		start++;
		i++;
	}
	while (s1[i])
		i++;
	while (ft_is_in_set(s1[i - end - 1], set) && (i - end - 1) > 0)
		end++;
	return (i - (start + end));// Return the length of the string s1 minus the number of leading and trailing characters that need to be trimmed
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*ptr;

	if (!s1 || !set) // Check if either one of the input parameters s1 or set are null
		return (NULL);
	i = ft_count(s1, set); // Get the length of the resulting trimmed string
	if (i < 1)
		return (ft_emptystr()); // If the length is less than 1, return an empty string
	ptr = malloc((i + 1) * sizeof(char)); // Allocate memory for the resulting string
	if (!ptr)
		return (NULL);
	j = 0;
	k = 0;
	while (ft_is_in_set(s1[j], set)) // Loop as long as the current character of s1 is in the set
		j++;
	while (k < i)
	{
		ptr[k] = s1[j + k]; // Assign the current character of s1 to the current index of the resulting string
		k++;
	}
	ptr[k] = '\0'; // Assign null character at the end of the resulting string
	return (ptr); // Return the pointer to the resulting string
}
