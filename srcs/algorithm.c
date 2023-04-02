/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:26:46 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/02 11:43:34 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*
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

        for (int i = 0; i < len; ++i)
    {
        if ((*stack_b)->data < (*stack_a)->data)
            pa(stack_a, stack_b);
        else
            pb(stack_a, stack_b);
    }
}
*/
/*
void    three_sort(t_stack **stack_a)
{
    int top;
    int mid;
    int bot;

    top = (**stack_a).data; 
    mid = (**stack_a).next->data;
    bot = (**stack_a).next->next->data;
    if ((top > mid) && (bot > top))
        sa(stack_a);
    else if ((top > mid) && (mid > bot))
    {
        sa(stack_a);
        rra(stack_a);
    }
    else if ((top > mid) && (mid < bot))
        ra(stack_a);
    else if ((top < mid) && ( mid > bot) && (top < bot))
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if ((top < mid) && (mid > bot) && (top > bot))
        rra(stack_a);
}

void five_sort(t_stack **stack_a)
{
    t_stack *stack_b;

    pb(stack_a, &stack_b);
    pb(stack_a, &stack_b);
    three_sort(stack_a);
    
}*/

int is_sorted(t_stack *stack)
{
    while (stack != NULL && stack->next != NULL)
    {
        if (stack->data > stack->next->data)
        {
            return 0;
        }
        stack = stack->next;
    }
    return 1;
}

void merge_sort(t_stack **stack_a, t_stack **stack_b, int len)
{
    if (len <= 1 || is_sorted(*stack_a))
    {
        return;
    }

    int mid = len / 2;

    // Move the top half of stack_a to stack_b
    for (int i = 0; i < mid; i++)
    {
        pb(stack_a, stack_b);
    }

    merge_sort(stack_a, stack_b, len - mid);
    merge_sort(stack_b, stack_a, mid);

    merge(stack_a, stack_b, len - mid, mid);
}

void merge(t_stack **stack_a, t_stack **stack_b, int len_a, int len_b)
{
    int i = 0, j = 0;

    while (i < len_a && j < len_b)
    {
        if ((*stack_b)->data < (*stack_a)->data)
        {
            pa(stack_b, stack_a);
            j++;
        }
        else
        {
            ra(stack_a);
            i++;
        }
    }

    // Move any remaining elements from stack_b to stack_a
    while (j < len_b)
    {
        pa(stack_b, stack_a);
        j++;
    }

    // Adjust stack_a to its original state
    for (int k = 0; k < len_a; k++)
    {
        rra(stack_a);
    }
}


