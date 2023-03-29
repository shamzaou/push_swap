/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:45:11 by shamzaou          #+#    #+#             */
/*   Updated: 2023/03/30 00:41:07 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *first_a;
    
    if (*stack_a == NULL)
        return;
    first_a = *stack_a;
    *stack_a = (*first_a).next;
    if (*stack_a != NULL)
        (*stack_a)->prev = NULL;
    first_a->next = *stack_b;
    if (*stack_b != NULL)
        (*stack_b)->prev = first_a;
    *stack_b = first_a;
    ft_putstr("pb\n");
}

void    pa(t_stack **stack_a, t_stack **stack_b)
{
    pb(stack_b, stack_a);
    ft_putstr("pa\n");
}