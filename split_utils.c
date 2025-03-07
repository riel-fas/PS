/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:41:31 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/07 13:41:32 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Count the number of words in a string
int count_words(char *s, char c)
{
    int count = 0;
    bool inside_word = false;

    while (*s)
    {
        if (*s == c)
            inside_word = false;
        else if (!inside_word)
        {
            count++;
            inside_word = true;
        }
        s++;
    }
    return count;
}

// Get the next word from the string
char *get_next_word(char *s, char c)
{
    static int cursor = 0;
    char *next_word;
    int len = 0;
    int i = 0;

    while (s[cursor] == c)
        cursor++;
    while (s[cursor + len] != c && s[cursor + len])
        len++;
    next_word = malloc((len + 1) * sizeof(char));
    if (!next_word)
        return NULL;
    while (s[cursor] != c && s[cursor])
        next_word[i++] = s[cursor++];
    next_word[i] = '\0';
    return next_word;
}