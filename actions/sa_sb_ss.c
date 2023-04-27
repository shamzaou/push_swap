/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:49:33 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/27 11:30:18 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*swap(t_stack *stack_to_swap)
{
	t_stack	*first;
	t_stack	*second;

	if (stack_to_swap == NULL || stack_to_swap->next == NULL)
		return (stack_to_swap);
	first = stack_to_swap;
	second = stack_to_swap->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->prev = first->prev;
	if (first->prev != NULL)
		first->prev->next = second;
	second->next = first;
	first->prev = second;
	return (second);
}

void	sa(t_stack **stack_a)
{
	*stack_a = swap(*stack_a);
	ft_putstr("sa\n");
}

void	sb(t_stack **stack_b)
{
	*stack_b = swap(*stack_b);
	ft_putstr("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = swap(*stack_a);
	*stack_b = swap(*stack_b);
	ft_putstr("ss\n");
}
