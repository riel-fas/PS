/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:29:23 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/07 13:29:24 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Find the median value in the stack
int find_median(t_stack *stack)
{
    int *array = stack_to_array(stack);
    if (!array)
        return 0;

    int length = stack_length(stack);
    sort_array(array, length);

    int median = array[length / 2];
    free(array);
    return median;
}

// Convert the stack to an array
int *stack_to_array(t_stack *stack)
{
    int length = stack_length(stack);
    int *array = malloc(length * sizeof(int));
    if (!array)
        return NULL;

    t_stack *current = stack;
    for (int i = 0; i < length; i++)
    {
        array[i] = current->nbr;
        current = current->next;
    }
    return array;
}

// Sort the array using bubble sort
void sort_array(int *array, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}