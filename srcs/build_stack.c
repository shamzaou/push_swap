/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:23:21 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/27 11:05:49 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    append_node(int data, t_stack **prevNode)
{
    t_stack *newNode = malloc(sizeof(t_stack));
    (*prevNode)->next = newNode;
    newNode->prev = *prevNode;
    newNode->next = NULL;
    newNode->data = data;
}

t_stack *create_stack(int argc, int *arr)
{
    int i;
    t_stack *head;
    
    head = NULL;
    t_stack *node = malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->data = arr[0];
    node->prev = NULL;
    node->next = NULL;
    head = node;
    i = 1;
    if (argc > 1)
    {
        while (i < argc)
        {
            append_node(arr[i], &node);
            node = node->next;
            i++;
        }    
    }
    return (head);
}

t_stack *get_next_min_value(t_stack *stack, long last_min_value)
{
    long min_value;
    t_stack *smallest_next_node;

    min_value = 2147483649;
    smallest_next_node = NULL;
    while (stack)
    {
        if (stack->data < min_value && stack->data > last_min_value)
        {
            min_value = stack->data;
            smallest_next_node = stack;   
        }
        stack = stack->next;
    }
    return (smallest_next_node);
}

void    assign_indexes(t_stack **stack)
{
    int len;
    int index;
    t_stack *node;
    long last_min_value;
    
    len = stack_len(*stack);
    index = 0;
    node = NULL;
    last_min_value = -2147483649;
    while (len-- > 0)
    {
        node = get_next_min_value(*stack, last_min_value);
        last_min_value = node->data;
        node->index = index;
        index++;
    }
}
