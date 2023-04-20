/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:47:29 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/20 06:48:28 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *head)
{
	t_stack	*current;

	current = head;
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	int		*arr;
	int		count;
	t_stack	*stack_a;

	count = parse_args(argc, argv, &arr);
	if (count == 0)
		ft_error();
	stack_a = create_stack(count, arr);
	free(arr);
	is_stack_sorted(stack_a);
	sort(&stack_a);
	print_list(stack_a);
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
	{
		printf("THIS IS A 3 SORT : \n");
		three_sort(stack_a);
	}
	else if (len_stack_a <= 6)
	{
		// printf("THIS IS A 5 SORT : \n");
		five_sort(stack_a);
	}
	else
		radix_sort(stack_a, &stack_b);
}
