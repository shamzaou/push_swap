/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:40:59 by shamzaou          #+#    #+#             */
/*   Updated: 2023/03/28 13:00:06 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    error(void)
{
    write(STDERR_FILENO, "Error\n", 6);
    exit(1);
}

int	ft_isdigit(int n)
{
	return (n >= '0' && n <= '9');
}

