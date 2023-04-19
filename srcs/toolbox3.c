/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:19:00 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/18 08:49:24 by shamzaou         ###   ########.fr       */
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



int lst_last(t_stack *head)
{
    if (!head)
        return(0);
    while (head && head->next)
        head = head->next;
    return (head->data);
}

int find_pos(t_stack *stack, int data)
{
    int pos;
    int len;
    t_stack *current;

    pos = 0;
    len = stack_len(stack);
    current = stack;
    while (current && data > current->data)
    {
        pos++;
        current = current->next;
    }
    if (pos == len)
        return (0);
    return (pos);
}
