/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:26:46 by shamzaou          #+#    #+#             */
/*   Updated: 2023/03/30 07:45:52 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int find_max_value(t_stack *stack)
{
    int max_value = stack->data;
    while (stack)
    {
        if (stack->data > max_value)
            max_value = stack->data;
        stack = stack->next;
    }
    return max_value;
}

void counting_sort(t_stack **stack, t_stack **sorted_stack, int exp, int array_size)
{
    t_stack *temp = NULL;
    int count[10] = {0};
    int i;
    t_stack *current = *stack;

    while (current != NULL)
    {
        int index = (current->data / exp) % 10;
        count[index]++;
        current = current->next;
    }

    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = array_size - 1; i >= 0; i--)
    {
        current = *stack;
        int position = i;
        while (position > 0)
        {
            current = current->next;
            position--;
        }

        int index = (current->data / exp) % 10;
        append_node(current->data, &temp);
        temp->next = (*sorted_stack);
        if (*sorted_stack != NULL)
        {
            (*sorted_stack)->prev = temp;
        }
        *sorted_stack = temp;
        count[index]--;
    }
}


void radix_sort(t_stack **stack, int array_size)
{
    int max = find_max_value(*stack);
    int exp;
    t_stack *sorted_stack = NULL;

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort(stack, &sorted_stack, exp, array_size);
    }

    *stack = sorted_stack;
}

