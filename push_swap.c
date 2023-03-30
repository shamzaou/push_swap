/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:47:29 by shamzaou          #+#    #+#             */
/*   Updated: 2023/03/30 06:50:56 by shamzaou         ###   ########.fr       */
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
    int num_elements;
    int i;

    num_elements = parse_args(argc, argv, &arr);

    printf("Input values:\n");
    for (i = 0; i < num_elements; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return (0);
}