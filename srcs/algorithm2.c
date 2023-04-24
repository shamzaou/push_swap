/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:44:33 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/24 11:12:43 by shamzaou         ###   ########.fr       */
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
		if (stack->index > max_value)
			max_value = stack->index;
		stack = stack->next;
	}
	while (max_value)
	{
		max_value >>= 1;
		bits++;
	}
	return (bits);
}

void    radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int i;
    int j;
    int max_bits;
    t_stack *head;
    int len;
    
    i = -1;
    j = 0;
    max_bits = get_max_bits(*stack_a);
    head = *stack_a;
    
    while (++i < max_bits)
    {
        len = stack_len(*stack_a);
        while (len-- > 0)
        {
            if ((((*stack_a)->index >> i) & 1) == 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
            
        }
        while (*stack_b)
            pa(stack_a, stack_b);
    }
}
