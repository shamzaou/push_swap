/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:23:21 by shamzaou          #+#    #+#             */
/*   Updated: 2023/03/28 21:41:24 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    append_node(int data, t_stack **prevNode)
{
    t_stack *newNode = malloc(sizeof(t_stack));
    (*prevNode)->next = newNode;
    newNode->next = NULL;
    newNode->data = data;
}

t_stack *create_stack(int argc, char **argv)
{
    int i;
    t_stack *head;
    
    t_stack *node = malloc(sizeof(t_stack));
    node->data = atoi(argv[1]);
    node->previous = NULL;
    node->next = NULL;
    head = node;
    
    i = 2;
    if (argc > 2)
    {
        while (i < argc)
        {
            append_node(atoi(argv[i]), &node);
            node = node->next;
            i++;
        }    
    }
    return (head);
}
