/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:44:33 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/12 22:21:28 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	insertion_sort_arr(int *array, int args)
{
	int	index1;
	int	index2;

	index1 = 1;
	while (index1 < args)
	{
		if (array[index1] < array[index1 - 1])
		{
			index2 = index1;
			while (array[index2] < array[index2 - 1] && index2 > 0)
			{
				ft_swap(&array[index2], &array[index2 - 1]);
				if (index2 - 1 > 0)
					index2--;
			}
		}
		index1++;
	}
}

int	get_max_bits(t_stack *stack)
{
	int	max_value;
	int	bits;

	max_value = INT_MIN;
	bits = 0;
	while (stack)
	{
		if (stack->data > max_value)
			max_value = stack->data;
		stack = stack->next;
	}
	while (max_value)
	{
		max_value >>= 1;
		bits++;
	}
	return (bits);
}

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	bits;
	int	index1;
	int	stack_size;

	bits = get_max_bits(*stack_a);
	stack_size = get_stack_size(*stack_a);
	for (index1 = 0; index1 < bits; index1++)
	{
		for (int index2 = 0; index2 < stack_size; index2++)
		{
			if ((*stack_a)->data & (1 << index1))
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (*stack_b)
			pa(stack_a, stack_b);
	}
}

