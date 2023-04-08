/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:47:29 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/08 17:47:40 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_stack* head) 
{
    t_stack* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


/*
int main(int argc, char **argv)
{
    int *arr;
    int num_elements;
    int i;
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;

    num_elements = parse_args(argc, argv, &arr);
    stack_a = create_stack(num_elements, arr);
    int len = stack_len(stack_a);
    quicksort(&stack_a, &stack_b, leni);
    print_list(stack_a);
    // free stack func
    free(arr);
    return (0);
}*/

int main(int argc, char **argv)
{
    int *arr;
    
    
    if (!parse_args(argc, argv, &arr))
    {
        ft_error();
        return (1);
    }

    t_stack *stack_a = create_stack(argc - 1, arr);
    free(arr);
    
    t_stack *stack_b = NULL;
    
    //sort(&stack_a, &stack_b);
    radix_sort(&stack_a, &stack_b);
    print_list(stack_a);

    return 0;
}
