/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:44:33 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/20 07:15:49 by shamzaou         ###   ########.fr       */
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

// Helper function to convert the number to its signed magnitude representation
int to_signed_magnitude(int num)
{
    if (num < 0)
        return ((-num) << 1) | 1;
    else
        return num << 1;
}

// Helper function to convert the number to its two's complement representation
unsigned int to_twos_complement(int num)
{
    return (unsigned int)num;
}

int find_min_value(t_stack *stack)
{
    int min_value = INT_MAX;
    while (stack)
    {
        if (stack->data < min_value)
            min_value = stack->data;
        stack = stack->next;
    }
    return min_value;
}

void add_offset_to_stack(t_stack **stack, int offset)
{
    t_stack *current = *stack;
    while (current)
    {
        current->data += offset;
        current = current->next;
    }
}

unsigned int get_unsigned_data(int data, int offset)
{
    return (unsigned int)(data + offset);
}

void radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int bits;
    int index1;
    int stack_size;
    int min_value = find_min_value(*stack_a);
    unsigned int offset = (unsigned int)abs(min_value);

    bits = get_max_bits(*stack_a);
    stack_size = get_stack_size(*stack_a);

    index1 = 0;
    while (index1 < bits)
    {
        int index2 = 0;
        while (index2 < stack_size)
        {
            unsigned int unsigned_data = get_unsigned_data((*stack_a)->data, offset);
            if (unsigned_data & (1u << index1))
                ra(stack_a);
            else
                pb(stack_a, stack_b);
            index2++;
        }
        while (*stack_b)
            pa(stack_a, stack_b);
        index1++;
    }
}




