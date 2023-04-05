/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:47:29 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/05 14:46:48 by shamzaou         ###   ########.fr       */
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
    quicksort(&stack_a, &stack_b, len);
    print_list(stack_a);
    // free stack func
    free(arr);
    return (0);
}*/

int main(int argc, char **argv)
{
    t_stack* head = NULL;
    int *arr;
    int pos;
    int *pos_ptr = &pos;
    
    
    if (!parse_args(argc, argv, &arr))
    {
        ft_error();
        return (1);
    }

    t_stack *stack_a = create_stack(argc - 1, arr);
    free(arr);

    t_stack* largest_node = find_largest_node(stack_a, pos_ptr);
    if (largest_node != NULL) {
        printf("Largest node data: %d\n", largest_node->data);
    } else {
        printf("The list is empty.\n");
    }

    printf("NODE POS : %d\n", pos);
    printf("STACK LEN : %d\n", stack_len(stack_a));
    // Now stack_a should be sorted
    // Perform any other required operations here

    return 0;
}
