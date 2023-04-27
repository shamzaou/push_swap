/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:45:11 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/27 11:29:59 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_a;

	if (*stack_a == NULL)
		return ;
	first_a = *stack_a;
	*stack_a = (*first_a).next;
	if (*stack_a != NULL)
		(*stack_a)->prev = NULL;
	first_a->next = *stack_b;
	if (*stack_b != NULL)
		(*stack_b)->prev = first_a;
	*stack_b = first_a;
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}
