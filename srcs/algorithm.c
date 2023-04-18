/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:26:46 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/18 09:21:39 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    two_sort(t_stack **stack)
{
    if (*stack && (*stack)->next != NULL)
    {
        if ((*stack)->data > (*stack)->next->data)
            sa(stack);
    }
}
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

void insert_sorted(t_stack **stack_a, t_stack **stack_b)
{
    int pos;

    pos = find_pos(*stack_a, (*stack_b)->data);
    to_the_top(stack_a, pos);
    pa(stack_a, stack_b);
    print_list(*stack_a);
    printf("smallest : %d\n", find_smallest_node_position(*stack_a));
    to_the_top(stack_a, find_smallest_node_position(*stack_a));
    printf("after to the top : ");
    print_list(*stack_a);
}

void five_sort(t_stack **stack_a)
{
    t_stack *stack_b = NULL;
    int stack_len_a = stack_len(*stack_a);
    
    if (stack_len_a < 4 || stack_len_a > 6)
        return;

    if (stack_len_a >= 4)
        pb(stack_a, &stack_b);
    if (stack_len_a >= 5)
        pb(stack_a, &stack_b);
    if (stack_len_a == 6)
        pb(stack_a, &stack_b);
    
    three_sort(stack_a);
    
    while (stack_b)
        {
            insert_sorted(stack_a, &stack_b);
            
        }
        
    to_the_top(stack_a, find_smallest_node_position(*stack_a) - 1);
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
    int pos = 0;
    int smallest_pos = head->data;

    if (head == NULL) {
        return 0;
    }

    t_stack* current = head;
    t_stack* smallest_node = head;

    while (current) {
        pos++;
        if (current->data < smallest_node->data)
        {
            smallest_node = current;
            smallest_pos = pos;
        }
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

void    to_the_top(t_stack **stack, int position)
{
    int len;
    int i;

     len = stack_len(*stack);
    if (!stack || !(*stack))
        return;
    
    if (position == 0)
        return;
    else if (len == position)
        rra(stack);
    else if (position > len / 2)
    {
        i = len - position;
        while (i-- > 0)
            rra(stack);
    }
    else if(position == len / 2)
        ra(stack);
    else
    {
        while (position > 0)
        {
            ra(stack);
            position--;
        }
    }
    printf("to the top result : ");
    print_list(*stack);
}