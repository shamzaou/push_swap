/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:26:46 by shamzaou          #+#    #+#             */
/*   Updated: 2023/03/30 07:12:30 by shamzaou         ###   ########.fr       */
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

void counting_sort(t_stack **stack, int exp)
{
    t_stack *output = NULL;
    int count[10] = {0};
    t_stack *current;

    current = *stack;
    while (current != NULL)
    {
        count[(current->data / exp) % 10]++;
        current = current->next;
    }

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    current = *stack;
    while (current != NULL)
    {
        t_stack *next = current->next;
        int index = (current->data / exp) % 10;
        count[index]--;
        current->next = NULL;
        current->prev = NULL;

        if (output == NULL)
        {
            output = current;
        }
        else
        {
            t_stack *temp = output;
            for (int i = 0; i < count[index]; i++)
                temp = temp->next;

            if (temp->prev)
            {
                temp->prev->next = current;
                current->prev = temp->prev;
            }
            temp->prev = current;
            current->next = temp;
        }
        current = next;
    }

    *stack = output;
}

void radix_sort(t_stack **stack)
{
    int max_value = find_max_value(*stack);
    for (int exp = 1; max_value / exp > 0; exp *= 10)
        counting_sort(stack, exp);
}
