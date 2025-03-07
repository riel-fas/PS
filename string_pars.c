/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:58:19 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/07 15:59:29 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"
#include "push_swap.h"

// Split a string into an array of substrings
char **split(char *s, char c)
{
    int words_count = count_words(s, c);
    char **result_array = malloc((words_count + 1) * sizeof(char *));
    if (!result_array)
        return NULL;

    int cursor = 0; // Initialize cursor here instead of statically
    int i = 0;
    while (i < words_count)
        result_array[i++] = get_next_word(s, c, &cursor);
    result_array[i] = NULL;
    return result_array;
}

// Convert a string to a long integer
long atoi_v2(char *av)
{
    long result = 0;
    int sign = 1;
    while (*av == ' ' || (*av >= 9 && *av <= 13))
        av++;
    if (*av == '+' || *av == '-')
    {
        if (*av == '-')
            sign = -1;
        av++;
    }
    while (*av >= '0' && *av <= '9')
        result = result * 10 + (*av++ - '0');
    return result * sign;
}
