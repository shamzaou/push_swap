/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:26:46 by shamzaou          #+#    #+#             */
/*   Updated: 2023/03/30 03:39:32 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int stack_len(t_stack *stack)
{
    int len = 0;
    while (stack)
    {
        len++;
        stack = stack->next;
    }
    return len;
}

int find_median(t_stack *stack, int len)
{
    t_stack *slow = stack;
    t_stack *fast = stack;
    int median;

    if (len % 2 == 0)
    {
        len--;
    }

    while (len > 0 && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        len -= 2;
    }

    median = slow->data;
    return median;
}

int partition(t_stack **stack_a, t_stack **stack_b, int len, int pivot)
{
    int i;
    int less_than_pivot_count = 0;

    i = 0;
    while (i < len)
    {
        if ((*stack_a)->data <= pivot) // change the condition here
        {
            pb(stack_a, stack_b);
            less_than_pivot_count++;
        }
        else
        {
            ra(stack_a);
        }
        i++;
    }

    return less_than_pivot_count;
}


void quicksort(t_stack **stack_a, t_stack **stack_b, int len)
{
    int pivot;
    int less_than_pivot_count;

    if (len <= 1)
        return;

    pivot = find_median(*stack_a, len);
    less_than_pivot_count = partition(stack_a, stack_b, len, pivot);

    quicksort(stack_b, stack_a, less_than_pivot_count);
    quicksort(stack_a, stack_b, len - less_than_pivot_count);
}

