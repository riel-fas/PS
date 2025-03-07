/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:10:00 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/07 13:41:57 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;

    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return 1;
    if (argc == 2)
        argv = split(argv[1], ' ');
    populate_stack_a(&a, argv, 1);

    if (!stack_sorted(a))
    {
        push_first_2(&a, &b);
        push_nodes_to_b(&a, &b);
        if (stack_length(a) == 3)
            sort_three(&a);
        push_back_to_a(&a, &b);
        final_adjustments(&a);
    }

    free_stack(&a);
    free_stack(&b);
    return 0;
}
