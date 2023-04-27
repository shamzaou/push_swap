/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:26:46 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/27 11:16:26 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	two_sort(t_stack **stack)
{
	if (*stack && (*stack)->next != NULL)
	{
		if ((*stack)->data > (*stack)->next->data)
			sa(stack);
	}
}
void	three_sort(t_stack **stack_a)
{
	int	top;
	int	mid;
	int	bot;

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
	else if ((top < mid) && (mid > bot) && (top < bot))
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((top < mid) && (mid > bot) && (top > bot))
		rra(stack_a);
}

/*void	insert_sorted(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;

	pos = find_pos(*stack_a, (*stack_b)->data);
	if (!((*stack_b)->data < (*stack_a)->data
			&& (*stack_b)->data > lst_last(*stack_a)))
		to_the_top(stack_a, pos - 1);
	pa(stack_a, stack_b);
	print_list(*stack_a);
}*/

void	five_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		stack_len_a;
	int		elements_to_move;
	int		min_pos;
	int		direction;

	stack_b = NULL;
	stack_len_a = stack_len(*stack_a);
	if (stack_len_a < 4 || stack_len_a > 6)
		return ;
	// Push the smallest element(s) to stack_b
	elements_to_move = stack_len_a - 3;
	while (elements_to_move > 0)
	{
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
		pb(stack_a, &stack_b);
		elements_to_move--;
	}
	three_sort(stack_a);
	// Move elements back from stack_b to stack_a
	while (stack_b)
	{
		pa(stack_a, &stack_b);
	}
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

int	find_largest_node_position(t_stack *head)
{
	int		pos;
	int		largest_pos;
	t_stack	*current;
	t_stack	*largest_node;

	pos = 1;
	largest_pos = 1;
	if (head == NULL)
	{
		return (0);
	}
	current = head;
	largest_node = head;
	while (current != NULL)
	{
		if (current->data > largest_node->data)
		{
			largest_node = current;
			largest_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (largest_pos);
}

int	ra_or_rra(t_stack *stack, int position)
{
	int	stack_size;

	stack_size = stack_len(stack);
	if (position <= stack_size / 2)
	{
		// Use ra to reach the position
		return (1);
	}
	else
	{
		// Use rra to reach the position
		return (-1);
	}
}
