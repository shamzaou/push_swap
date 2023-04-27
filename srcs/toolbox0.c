/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:40:59 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/27 14:27:29 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_isdigit(int n)
{
	return (n >= '0' && n <= '9');
}

int	skip_space(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	return (i);
}

int	ft_atoi(char *str, t_error_data *error_data)
{
	long long	result;
	int			sign;
	int			i;

	i = skip_space(str);
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX) || (sign == -1
				&& (-result < INT_MIN)))
			ft_error_handler(error_data);
		i++;
	}
	return (sign * result);
}

int	is_int(char *str)
{
	int	i;

	i = 0;
	if (is_sign(&str[i]) && str[i + 1] != '\0')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] && !ft_isdigit(str[i]) && !isspace(str[i]))
		return (0);
	return (1);
}
