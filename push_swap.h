/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:53:02 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/29 02:04:54 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <ctype.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	struct s_stack	*prev;
	int				data;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_error_data
{
	int				*arr;
	char			**tokens;
}					t_error_data;

# ifndef STDERR_FILENO
#  define STDERR_FILENO 2
# endif

int					parse_args(int argc, char **argv, int **arr_ptr);
int					count_numbers(const char *str);

t_stack				*create_stack(int argc, int *arr);
void				append_node(int data, t_stack **prevNode);

void				ft_error_handler(t_error_data *error_data);
void				ft_error(void);
void				free_stack(t_stack **stack);
void				free_tokens(char **tokens);

int					ft_atoi(char *str, t_error_data *s_error_data);
int					is_sign(char *str);
int					is_int(char *str);
int					is_int2(char *str);
int					is_only_spaces(const char *str);
int					is_empty_or_whitespace(const char *str);
void				print_list(t_stack *head);
int					skip_space(char *str);

t_stack				*swap(t_stack *stack_to_swap);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);

t_stack				*rotate(t_stack *stack);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);

t_stack				*rev_rotate(t_stack *stack);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
int					ra_or_rra(t_stack *stack, int position);

void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);

char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
void				ft_putstr(char *str);
int					ft_isdigit(int n);
void				ft_swap(int *a, int *b);

void				is_stack_sorted(t_stack **stack);
t_stack				*get_next_min_value(t_stack *stack, long last_min_value);
void				assign_indexes(t_stack **stack);
int					stack_len(t_stack *stack);

void				sort(t_stack **stack_a);
void				two_sort(t_stack **stack);
void				three_sort(t_stack **stack_a);
void				five_sort(t_stack **stack_a);
void				radix_sort(t_stack **stack_a, t_stack **stack_b);
int					get_max_bits(t_stack *stack);

int					parse_and_count_args(int argc, char **argv);
void				fill_array(int argc, char **argv, int *arr,
						t_error_data *error_data);
void				check_duplicates(int *arr, int total_numbers,
						t_error_data *error_data);
int					find_smallest_node_position(t_stack *head);
void				push_smallest_to_b(t_stack **stack_a, t_stack **stack_b);

#endif