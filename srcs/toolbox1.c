/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:26:46 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/27 13:56:49 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_smallest_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_len_a;
	int	min_pos;
	int	direction;

	stack_len_a = stack_len(*stack_a);
	min_pos = find_smallest_node_position(*stack_a);
	direction = ra_or_rra(*stack_a, min_pos);
	if (direction == 1)
	{
		min_pos = min_pos - 1;
		while (min_pos-- > 0)
			ra(stack_a);
	}
	else
	{
		min_pos = stack_len_a - min_pos + 1;
		while (min_pos-- > 0)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

int	stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

int	find_smallest_node_position(t_stack *head)
{
	t_stack	*current;
	int		smallest;
	int		position;
	int		smallest_position;

	if (head == NULL)
		return (-1);
	current = head;
	smallest = current->data;
	position = 1;
	smallest_position = 0;
	while (current != NULL)
	{
		if (current->data < smallest)
		{
			smallest = current->data;
			smallest_position = position;
		}
		position++;
		current = current->next;
	}
	return (smallest_position);
}

int	ra_or_rra(t_stack *stack, int position)
{
	int	stack_size;

	stack_size = stack_len(stack);
	if (position <= stack_size / 2)
		return (1);
	else
		return (-1);
}
