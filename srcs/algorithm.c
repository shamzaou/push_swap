/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:26:46 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/03 10:20:42 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void    insert_sorted(t_stack **stack_a, t_stack **stack_b, int value, int n)
{
    t_stack *tmp = *stack_a;
    int counter = 0;

    if (value > (*stack_a)->next->next->data)
        {
            pa(stack_a, stack_b);
            ra(stack_a);        
        }
    else 
    {
        while (tmp && tmp->data < value && n--)
        {
            ra(stack_a);
            tmp = *stack_a;
            counter++;
        }
        
        pa(stack_a, stack_b);
        while (counter--)
            rra(stack_a);
    }
}

void    five_sort(t_stack **stack_a)
{
    t_stack *stack_b = NULL;
    int first;
    int second;
    
    pb(stack_a, &stack_b);
    pb(stack_a, &stack_b);

    three_sort(stack_a);
    
    first = stack_b->data;
    second = stack_b->next->data;

    insert_sorted(stack_a, &stack_b, first, 3);
    insert_sorted(stack_a, &stack_b, second, 4);
}
