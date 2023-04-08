/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:26:46 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/08 14:03:57 by shamzaou         ###   ########.fr       */
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

int find_smallest_node_position(t_stack *head)
{
    int pos = 1;
    int smallest_pos = 1;

    if (head == NULL) {
        return 0;
    }

    t_stack* current = head;
    t_stack* smallest_node = head;

    while (current != NULL) {
        if (current->data < smallest_node->data) {
            smallest_node = current;
            smallest_pos = pos;
        }
        pos++;
        current = current->next;
    }

    return smallest_pos;
}

int find_largest_node_position(t_stack *head)
{
    int pos = 1;
    int largest_pos = 1;

    if (head == NULL) {
        return 0;
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

    return largest_pos;
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

int is_sorted(t_stack *stack)
{
    t_stack *current;

    current = stack;
    while (current && current->next)
    {
        if ( current->data > current->next->data)
            return (0);
        current = current->next;
    }
    return (1);
}

int to_the_top(t_stack **stack)
{
    int index;
    int pos_largest;
    int pos_smallest;
    int len;
    int i;
    int moved_element = 0; // 0 for the smallest element, 1 for the largest element

    if (!stack || !(*stack))
        return -1;

    pos_smallest = find_smallest_node_position(*stack);
    pos_largest = find_largest_node_position(*stack);
    len = stack_len(*stack);

    if ((pos_largest <= len / 2 && pos_smallest <= len / 2) || (pos_largest > len / 2 && pos_smallest > len / 2))
    {
        if (pos_largest < pos_smallest)
        {
            index = pos_largest;
            moved_element = 1;
        }
        else
        {
            index = pos_smallest;
            moved_element = 0;
        }
    }
    else
    {
        index = pos_smallest;
        moved_element = 0;
    }

    if (index > len / 2)
    {
        i = len - index + 1;
        while (i--)
            rra(stack);
    }
    else
    {
        while (--index >= 0)
        {
            ra(stack);
        }
    }

    return moved_element;
}


void    sort(t_stack **stack_a, t_stack **stack_b)
{
    int large_or_small;

    if (!stack_a || !(*stack_a) || is_sorted(*stack_a))
        return;
    while ((*stack_a))
    {
        large_or_small = to_the_top(stack_a);
        pb(stack_a, stack_b);
        if (large_or_small == 0)
            rb(stack_b);
    }
    
    print_list(*stack_b);
    /*while (*stack_b)
    {
        pa(stack_a, stack_b);
    }*/
}