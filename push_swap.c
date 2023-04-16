/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:47:29 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/16 22:27:40 by shamzaou         ###   ########.fr       */
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
    t_stack *stack_a;
    t_stack *stack_b;
    
    if (!parse_args(argc, argv, &arr))
    {
        ft_error();
        return (1);
    }
    stack_a = create_stack(argc - 1, arr);
    stack_b = NULL;
    free(arr);
    /*
    pb(&stack_a, &stack_b);
    pb(&stack_a, &stack_b);
    three_sort(&stack_a);
    int pos = find_pos(stack_a, stack_b->data);
    printf("pos value : %d\n", pos);
    to_the_top(&stack_a, pos - 1);
    pa(&stack_a, &stack_b);
    pos = find_pos(stack_a, stack_b->data);
    printf("pos value : %d\n", pos);
    to_the_top(&stack_a, pos - 1);
    pa(&stack_a, &stack_b);
    print_list(stack_a);
    print_list(stack_b);*/
    is_stack_sorted(stack_a);
    if (stack_len(stack_a) <= 3)
    {
        printf("THIS IS A 3 SORT : \n");
        three_sort(&stack_a);
    }
    else if (stack_len(stack_a) <= 6)
        {
            printf("THIS IS A 5 SORT : \n");
            five_sort(&stack_a);
        }
    else
        radix_sort(&stack_a, &stack_b);
    print_list(stack_a);

    return 0;
}
