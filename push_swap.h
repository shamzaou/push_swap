/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:53:02 by shamzaou          #+#    #+#             */
/*   Updated: 2023/03/29 23:57:47 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
    struct s_stack *prev;
    int data;
    struct s_stack *next;
}       t_stack;

#ifndef STDERR_FILENO
#define STDERR_FILENO 2
#endif 

void    ft_putstr(char *str);
t_stack *create_stack(int argc, int *arr);
void    append_node(int data, t_stack **prevNode);
void    print_list(t_stack* head);
void    ft_error(void);
int	    ft_isdigit(int n);
int     skip_space(char *str);
int     ft_atoi(char *str);
int     is_sign(char *str);
int     is_int(char *str);
int     *convert(int argc, char **argv);
int     *parse_args(int argc, char **argv);
t_stack *swap(t_stack *stack_to_swap);
void    sa(t_stack **stack_a);
void    sb(t_stack **stack_b);
void    ss(t_stack **stack_a, t_stack **stack_b);
t_stack *rotate(t_stack *stack);
void    ra(t_stack **stack_a);
void    rb(t_stack **stack_b);
void    rr(t_stack **stack_a, t_stack **stack_b);
t_stack *rev_rotate(t_stack *stack);
void    rra(t_stack **stack_a);
void    rrb(t_stack **stack_b);
void    rrr(t_stack **stack_a, t_stack **stack_b);
void    pa(t_stack **stack_b, t_stack **stack_a);
void    pb(t_stack **stack_a, t_stack **stack_b);

#endif