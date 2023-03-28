/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:53:02 by shamzaou          #+#    #+#             */
/*   Updated: 2023/03/28 13:00:55 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
    struct s_stack *previous;
    int data;
    struct s_stack *next;
}       t_stack;

#ifndef STDERR_FILENO
#define STDERR_FILENO 2
#endif 


t_stack *create_stack(int argc, char **argv);
void    append_node(int data, t_stack **prevNode);
void    print_list(t_stack* head);
void    error(void);
int	    ft_isdigit(int n);

#endif