/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:58:19 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/06 13:27:24 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		++cursor;
	while ((s[cursor + len] != c) && s[cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char	**splitv2(char *s, char c)
{
	int		words_count;
	char	**result_array;
	int		i;

	i = 0;
	words_count = count_words(s, c);
	if (!words_count)
		exit(1);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (!result_array)
		return (NULL);
	while (i < words_count)
	{
		result_array[i] = get_next_word(s, c);
		i++;
	}
	result_array[i] = NULL;
	return (result_array);
}

long atoi_v2(char *av)
{
	int		sign;
	int		x;
	long	result;

	sign = 1;
	x = 0;
	result = 0;
	while ((av[x] >= 9 && av[x] <= 13) || av[x] == 32)
		x++;
	if (av[x] == '+' || av[x] == '-')
	{
		if (av[x] == '-')
			sign = -1;
		x++;
	}
	while (av[x] >= '0' && av[x] <= '9')
	{
		result = result * 10 + (av[x] - '0');
		x++;
	}
	return (result * sign);
}

