/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:45:19 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/27 11:06:54 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* ra():
*   1. Checks if there's enough elements to rotate.
*   2. Find the last element in the list.
*   3. Assign the correct values to First, Second and Last.
*/
static t_stack *rotate(t_stack *stack)
{
    t_stack *first;
    t_stack *second;
    t_stack *last;

    if (stack == NULL || stack->next == NULL)
        return (stack);
    first = stack;
    second = stack->next;
    last = stack;
    while (last->next != NULL)
        last = last->next;
    first->next = NULL;
    first->prev = last;
    last->next = first;
    second->prev = NULL;
    return (second);
}

void    ra(t_stack **stack_a)
{
    *stack_a = rotate(*stack_a);
    ft_putstr("ra\n");
}

void    rb(t_stack **stack_b)
{
    *stack_b = rotate(*stack_b);
    ft_putstr("rb\n");
}

void    rr(t_stack **stack_a, t_stack **stack_b)
{
    *stack_a = rotate(*stack_a);
    *stack_b = rotate(*stack_b);
    ft_putstr("rr\n");
}