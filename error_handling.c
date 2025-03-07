/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:45:57 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/07 13:45:58 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check for syntax errors in the input
int error_syntax(char *str_n)
{
    if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
        return 1;
    if ((*str_n == '+' || *str_n == '-') && !(str_n[1] >= '0' && str_n[1] <= '9'))
        return 1;
    while (*++str_n)
    {
        if (!(*str_n >= '0' && *str_n <= '9'))
            return 1;
    }
    return 0;
}

// Check for duplicate values in the stack
int error_duplicate(t_stack *a, int n)
{
    if (!a)
        return 0;
    while (a)
    {
        if (a->nbr == n)
            return 1;
        a = a->next;
    }
    return 0;
}

// Free the entire stack
void free_stack(t_stack **stack)
{
    t_stack *tmp;
    t_stack *current = *stack;

    while (current)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
    *stack = NULL;
}

// Free the stack and exit with an error message
void free_errors(t_stack **a)
{
    free_stack(a);
    write(2, "Error\n", 6);
    exit(1);
}
