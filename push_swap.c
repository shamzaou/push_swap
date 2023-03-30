/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:47:29 by shamzaou          #+#    #+#             */
/*   Updated: 2023/03/30 07:31:19 by shamzaou         ###   ########.fr       */
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
    t_stack *original_stack, *sorted_stack;
    int *arr;
    int i, array_size;

    arr = parse_args(argc, argv);
    array_size = count_args(argc, argv);

    printf("Array size: %d\n", array_size);
    printf("Array elements: ");
    for (i = 0; i < array_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    original_stack = create_stack(array_size, arr);
    sorted_stack = radix_sort(&original_stack);

    printf("Original stack:\n");
    print_list(original_stack);
    printf("Sorted stack:\n");
    print_list(sorted_stack);

    return 0;
}