/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:47:29 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/27 11:15:23 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	print_list(t_stack *head)
{
	t_stack	*current;

	current = head;
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}*/

int	main(int argc, char **argv)
{
	int		*arr;
	int		count;
	t_stack	*stack_a;

	stack_a = NULL;
	count = parse_args(argc, argv, &arr);
	if (count == 0)
		ft_error();
	stack_a = create_stack(count, arr);
	assign_indexes(&stack_a);
	free(arr);
	is_stack_sorted(&stack_a);
	sort(&stack_a);
	free_stack(&stack_a);
	return (0);
}

void	sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		len_stack_a;

	stack_b = NULL;
	len_stack_a = stack_len(*stack_a);
	if (len_stack_a == 2)
		two_sort(stack_a);
	else if (len_stack_a == 3)
		three_sort(stack_a);
	else if (len_stack_a <= 6)
		five_sort(stack_a);
	else
		radix_sort(stack_a, &stack_b);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = NULL;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}