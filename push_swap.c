/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:47:29 by shamzaou          #+#    #+#             */
/*   Updated: 2023/03/30 00:37:56 by shamzaou         ###   ########.fr       */
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
// Fixed leaks, careful with the stack allocations.. 
// current code only frees the head.
int main(int argc, char **argv)
{
    t_stack *head = NULL;
    int *arr = parse_args(argc, argv);
    head = create_stack(argc, arr);
    free(arr);
    print_list(head);
    free(head);
}
*/

/*int main(int argc, char **argv) {
    int *arr = parse_args(argc, argv);
    if (arr == NULL) {
        ft_error();
        return 1;
    }

    t_stack *stack_a = create_stack(argc - 1, arr);
    free(arr);

    printf("Original stack:\n");
    print_list(stack_a);

    rra(&stack_a); // Update the head of the list after sa operation

    printf("\nStack after sa operation:\n");
    print_list(stack_a);

    // Free the stack memory
    t_stack *current = stack_a;
    while (current != NULL) {
        t_stack *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}*/



int main(int argc, char **argv)
{
    int *arr;
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc < 2)
    {
        ft_putstr("Please provide a list of numbers as arguments.\n");
        return (1);
    }

    arr = parse_args(argc, argv);
    stack_a = create_stack(argc - 1, arr);
    stack_b = NULL;

    printf("Initial stacks:\n");
    printf("Stack A: ");
    print_list(stack_a);
    printf("Stack B: ");
    print_list(stack_b);
    printf("\n");

    sa(&stack_a);
    sb(&stack_b);
    ss(&stack_a, &stack_b);
    pa(&stack_a, &stack_b);
    pb(&stack_a, &stack_b);
    ra(&stack_a);
    rb(&stack_b);
    rr(&stack_a, &stack_b);
    rra(&stack_a);
    rrb(&stack_b);
    rrr(&stack_a, &stack_b);

    printf("Final stacks after all operations:\n");
    printf("Stack A: ");
    print_list(stack_a);
    printf("Stack B: ");
    print_list(stack_b);

    free(arr);
    // Add functions to free the stacks' memory
    return (0);
}