/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:26:46 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/07 15:06:50 by shamzaou         ###   ########.fr       */
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

t_stack *find_largest_node(t_stack *head, int *pos_ptr)
{
    int pos = 1;
    int largest_pos = 0;
    if (head == NULL) {
        return NULL;
    }

    t_stack* current = head;
    t_stack* largest_node = head;

    while (current != NULL) {
        if (current->data > largest_node->data) {
            largest_node = current;
            largest_pos = pos;
        }
        pos++;
        current = current->next;
    }
    *pos_ptr = largest_pos;
    return largest_node;
}

int ra_or_rra(t_stack *stack, int position)
{
    int len;
    
    len = stack_len(stack);
    if (position > len / 2)
        return (0);
    else
        return (1);
}

void    to_the_top(t_stack **stack)
{
    t_stack *largest_node;
    int pos;
    int *pos_ptr;
    int len;
    int i;
    
    pos_ptr = &pos;
    largest_node = find_largest_node(*stack, pos_ptr);
    len = stack_len(*stack);
    if(pos > len / 2)
    {
        i = len - pos + 1;
        while (i--)
            rra(stack);
    }
    else
    {
        while(--pos)
            ra(stack);
    }
}