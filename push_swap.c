/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:47:29 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/20 01:05:26 by shamzaou         ###   ########.fr       */
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

int main(int argc, char **argv)
{
    int *arr;
    int count;
    t_stack *stack_a;
    t_stack *stack_b;
    
    count = parse_args(argc, argv, &arr);
    if (count == 0)
        ft_error();
    stack_a = create_stack(count, arr);
    stack_b = NULL;
    free(arr);
    is_stack_sorted(stack_a);
    if (stack_len(stack_a) == 2)
        two_sort(&stack_a);
    else if (stack_len(stack_a) == 3)
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
