/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:47:29 by shamzaou          #+#    #+#             */
/*   Updated: 2023/03/27 19:53:20 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack stack_assign(int argc, char **numbers)
{
    t_stack *stack_elem;
    t_stack *tmp = NULL;
    int i;

    i = 1;
    while (i < argc)
    {
        stack_elem = malloc(sizeof(t_stack));
        stack_elem->previous = tmp;
        stack_elem->data = atoi(numbers[i]);
        stack_elem->next = malloc(sizeof(t_stack));
        tmp = stack_elem->next;
        i++;
    }
}

int main(int argc, char **argv)
{
    
}