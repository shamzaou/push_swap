/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:45:16 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/08 11:54:11 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack *rev_rotate(t_stack *stack)
{
    t_stack *first;
    //t_stack *second;
    t_stack *last;
    
    if (stack == NULL || stack->next == NULL)
        return (stack);
    first = stack;
    //second = stack->next;
    last = stack;
    while (last->next != NULL)
        last = last->next;
    last->prev->next = NULL;
    last->prev = NULL;
    last->next = first;
    first->prev = last;
    return (last);
}

void    rra(t_stack **stack_a)
{
    *stack_a = rev_rotate(*stack_a);
    ft_putstr("rra\n");
}

void    rrb(t_stack **stack_b)
{
    *stack_b = rev_rotate(*stack_b);
    ft_putstr("rrb\n");
}

void    rrr(t_stack **stack_a, t_stack **stack_b)
{
    *stack_a = rev_rotate(*stack_a);
    *stack_b = rev_rotate(*stack_b);
    ft_putstr("rrr\n");
}