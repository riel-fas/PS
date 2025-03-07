/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:45:50 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/06 16:29:39 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_first_2(t_stack **A, t_stack **B)
{
	if (!A || !*A || !(*A)->next) // Ensure stack A has at least 2 nodes
		return;
	pb(A, B); // Push the first node
	pb(A, B); // Push the second node
	if ((*B)->nbr > (*B)->next->nbr)
		sa_sb(B, 'B');
}

// void	push_nodes_to_b(t_stack **A, t_stack **B)
// {
//     int median = find_median(*A); // Find the median value in stack A

//     while (stack_length(*A) > 3)
//     {
//         t_stack *node = *A;

//         // Find the best node to push based on the median
//         if (node->nbr <= median)
//         {
//             pb(A, B); // Push the node to stack B
//             if ((*B)->next && (*B)->nbr < (*B)->next->nbr)
//                 sa_sb(B, 'B'); // Sort stack B if necessary
//         }
//         else
//         {
//             ra_rb(A, 'A'); // Rotate stack A to bring the next node to the top
//         }
//     }
// }
////////////////////////////////////////////
int calculate_chunk_size(int stack_size)
{
    if (stack_size <= 100)
        return 5;
    else if (stack_size <= 500)
        return 10;
    else
        return 20;
}


void sort_array(int *array, int size)
{
	if (!array || size <= 1)
	return; // Nothing to sort

    for (int i = 0; i < size - 1; i++)
    {
		for (int j = 0; j < size - i - 1; j++)
        {
			if (array[j] > array[j + 1])
            {
				// Swap elements
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int *stack_to_array(t_stack *stack)
{
	int length = stack_length(stack); // Get the length of the stack
	int *array = malloc(length * sizeof(int)); // Allocate memory for the array
	if (!array)
		return NULL; // Handle malloc failure

	t_stack *current = stack;
	for (int i = 0; i < length; i++)
	{
		array[i] = current->nbr; // Copy the value from the stack to the array
		current = current->next; // Move to the next node
	}

	return array; // Return the populated array
}

void push_nodes_to_b(t_stack **a, t_stack **b)
{
    int *sorted_array;
    int i = 0;

    if (!a || !*a || stack_length(*a) <= 3)
        return; // No need to push if 3 or fewer numbers

    // Convert stack A to an array and sort it
    sorted_array = stack_to_array(*a);
    if (!sorted_array)
        return; // Handle malloc failure

    // Sort the array
    sort_array(sorted_array, stack_length(*a));

    while (stack_length(*a) > 3)
    {
        if ((*a)->nbr <= sorted_array[i])
        {
            pb(a, b); // Push the node to stack B
            if ((*b)->next && (*b)->nbr < (*b)->next->nbr)
                sa_sb(b, 'b'); // Keep `b` sorted
            i++;
        }
        else
            ra_rb(a, 'a'); // Rotate if not within the current chunk
    }

    free(sorted_array); // Free the allocated array
}
///////////////////////////////////////////////

// void push_nodes_to_b(t_stack **a, t_stack **b)
// {
//     int chunk_size;
//     int *sorted_array;
//     int i = 0;

//     if (!a || !*a || stack_length(*a) <= 3)
//         return; // No need to push if 3 or fewer numbers

//     sorted_array = stack_to_array(*a);
//     sort_array(sorted_array, stack_length(*a));  // Use quicksort or bubble sort

//     chunk_size = stack_length(*a) / 5;  // Divide into 5 chunks

//     while (stack_length(*a) > 3)
//     {
//         if ((*a)->nbr <= sorted_array[i])
//         {
//             pb(a, b);
//             if ((*b)->next && (*b)->nbr < (*b)->next->nbr)
//                 sa_sb(b, 'b');  // Keep `b` sorted
//             i++;
//         }
//         else
//             ra_rb(a, 'a');  // Rotate if not within the first chunk
//     }
//     free(sorted_array);
// }

// void push_nodes_to_b(t_stack **a, t_stack **b)
// {
//     if (!a || !*a || stack_length(*a) <= 3)
//         return; // Nothing to do if stack A has 3 or fewer nodes

//     int median = find_median(*a); // Find the median value in stack A

//     while (stack_length(*a) > 3)
//     {
//         t_stack *node = *a;

//         // If the current node is less than or equal to the median, push it to stack B
//         if (node->nbr <= median)
//         {
//             pb(a, b); // Push the node to stack B

//             // If stack B has at least two nodes and they are out of order, swap them
//             if ((*b)->next && (*b)->nbr < (*b)->next->nbr)
//                 sa_sb(b, 'b');
//         }
//         else
//         {
//             // If the current node is greater than the median, rotate stack A
//             ra_rb(a, 'a');
//         }
//     }
// }


// Helper function to compare two integers (used by qsort)
int compare_ints(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int find_median(t_stack *stack)
{
    int length = stack_length(stack);
    if (length == 0)
        return 0; // Handle empty stack case

    // Extract values from the stack into an array
    int *values = malloc(length * sizeof(int));
    if (!values)
        return 0; // Handle malloc failure

    t_stack *current = stack;
    for (int i = 0; i < length; i++)
    {
        values[i] = current->nbr;
        current = current->next;
    }

    // Sort the array
    qsort(values, length, sizeof(int), compare_ints);

    // Find the median
    int median;
    if (length % 2 == 1)
    {
        // Odd number of elements: return the middle element
        median = values[length / 2];
    }
    else
    {
        // Even number of elements: return the lower middle element
        median = values[(length / 2) - 1];
    }

    // Free the allocated memory
    free(values);

    return median;
}


