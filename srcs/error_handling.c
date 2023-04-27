/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:50:38 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/27 13:52:23 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error_handler(t_error_data *error_data)
{
	if (error_data->arr)
		free(error_data->arr);
	if (error_data->tokens)
	{
		free_tokens(error_data->tokens);
	}
	ft_error();
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
