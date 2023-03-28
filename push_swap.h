/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:53:02 by shamzaou          #+#    #+#             */
/*   Updated: 2023/03/28 22:06:30 by shamzaou         ###   ########.fr       */
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
void    ft_error(void);
int	    ft_isdigit(int n);
int     skip_space(char *str);
int     ft_atoi(char *str);
int     is_sign(char *str);
int     is_int(char *str);
int     *convert(int argc, char **argv);
int     *parse_args(int argc, char **argv);


#endif