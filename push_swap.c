/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:10:00 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/07 08:27:37 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

////////////////////////////////
void print_stacks(t_stack *a, t_stack *b)
{
    t_stack *current_a = a;
    t_stack *current_b = b;

    write(1, "Stack A: ", 9);
    while (current_a)
    {
        printf("%d ", current_a->nbr); // Print the value of the current node in stack A
        current_a = current_a->next;
    }
    printf("\n");

    write(1, "Stack B: ", 9);
    while (current_b)
    {
        printf("%d ", current_b->nbr); // Print the value of the current node in stack B
        current_b = current_b->next;
    }
    printf("\n");
}

void push_swap(t_stack **A, t_stack **B)
{
    printf("Initial stacks:\n");
    print_stacks(*A, *B); // Print initial state of stacks

    push_first_2(A, B);
    printf("After pushing first 2 elements to B:\n");
    print_stacks(*A, *B); // Print state after pushing first 2 elements to B

    push_nodes_to_b(A, B);
    printf("After pushing nodes to B:\n");
    print_stacks(*A, *B); // Print state after pushing nodes to B

    sort_three(A);
    printf("After sorting stack A (3 elements):\n");
    print_stacks(*A, *B); // Print state after sorting stack A

    sort_stack_b(B);
    printf("After sorting stack B:\n");
    print_stacks(*A, *B); // Print state after sorting stack B

    push_back_to_a(A, B);
    printf("After pushing elements back to A:\n");
    print_stacks(*A, *B); // Print state after pushing elements back to A

    final_adjustments(A);
    printf("Final stacks:\n");
    print_stacks(*A, *B); // Print final state of stacks
}



//////////////////////////////

void error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

// void	push_swap(t_stack **A, t_stack **B)
// {
// 	push_first_2(A, B);
// 	push_nodes_to_b(A, B);
// 	sort_three(A);
// 	sort_stack_b(B);
// 	push_back_to_a(A, B);
// 	final_adjustments(A);
// }

// int main(int ac, char **av)
// {
// 	t_stack	*A;
// 	t_stack	*B;
// 	char	**splited;
// 	int		start_index;

// 	A = NULL;
// 	B = NULL;
// 	start_index = 1;
// 	if (ac < 2 || (ac == 2 && !av[1][0]))
// 		error_exit ();
// 	if (ac == 2)
// 	{
// 		splited = splitv2(av[1], ' ');
// 		//we split the command line
// 		start_index = 0;
// 	}
// 	else
// 	{
// 		splited = av;
// 		start_index = 1;
// 	}

// 	populate_stack_A(&A, splited, start_index);

// 	if (stack_sort_check(A))
// 	{
// 		free_stack(&A);
// 		if (ac == 2)
// 			free_args(splited);
// 		return (0);
// 	}
// 	push_swap(&A, &B);

// 	free_stack(&A);
//     free_stack(&B);
//     if (ac == 2)
//     {
//         free_args(splited);
//     }
//     return (0);

// }

void print_stack(t_stack *stack, const char *name)
{
    printf("%s: ", name);
    while (stack)
    {
        printf("%d ", stack->nbr);
        stack = stack->next;
    }
    printf("\n");
}

int main(int ac, char **av)
{
    t_stack *A = NULL;
    t_stack *B = NULL;
    char **splited;
    int start_index = 1;

    if (ac < 2 || (ac == 2 && !av[1][0]))
        error_exit();

    if (ac == 2)
    {
        splited = splitv2(av[1], ' ');
        start_index = 0;
    }
    else
    {
        splited = av;
        start_index = 1;
    }

    populate_stack_A(&A, splited, start_index);
    print_stack(A, "Stack A after parsing"); // Debug print

    if (stack_sort_check(A))
    {
        free_stack(&A);
        if (ac == 2)
            free_args(splited);
        return 0;
    }

    push_swap(&A, &B);

    free_stack(&A);
    free_stack(&B);
    if (ac == 2)
        free_args(splited);

    return 0;
}


