/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:23:21 by shamzaou          #+#    #+#             */
/*   Updated: 2023/03/30 07:20:53 by shamzaou         ###   ########.fr       */
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
/*
t_stack *create_stack(int argc, int *arr)
{
    int i;
    t_stack *head = NULL;
    
    t_stack *node = malloc(sizeof(t_stack));
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
}*/

t_stack *create_stack(int argc, int *arr)
{
    int i;
    t_stack *head = NULL;
    
    t_stack *node = malloc(sizeof(t_stack));
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
    
    printf("Array size: %d\n", argc);
    printf("Array elements: ");
    for (i = 0; i < argc; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return (head);
}
