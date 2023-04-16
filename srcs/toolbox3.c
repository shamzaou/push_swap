/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:19:00 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/16 03:02:15 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void    is_stack_sorted(t_stack *stack)
{
    t_stack *current;

    current = stack;
    while (current->next != NULL)
    {
        if (current->data > current->next->data)
            return;
        current = current->next;
    }
    exit(1);
}

int find_pos(t_stack *stack, int data)
{
    int pos;

    pos = 0;
    while (stack && stack->next)
    {
        pos++;
        if (data > stack->data && data <= stack->next->data)
            break;
        stack = stack->next;
    }
    return (pos + 1);
}
