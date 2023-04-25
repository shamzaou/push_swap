/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:40:59 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/25 10:23:38 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_error_handler(t_error_data *error_data)
{
    int i;

    if (error_data->arr)
        free(error_data->arr);
    
    if (error_data->tokens)
    {
        i = 0;
        while (error_data->tokens[i])
        {
            free(error_data->tokens[i]);
            i++;
        }
        free(error_data->tokens);
    }
    
    ft_error();
}

void ft_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}
void    ft_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i++;
    }
}

int	ft_isdigit(int n)
{
	return (n >= '0' && n <= '9');
}

int skip_space(char *str)
{
    int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	return (i);
}

int ft_atoi(char *str)
{
    long long   result;
    int         sign;
    int         i;

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
        if ((sign == 1 && result > INT_MAX) || (sign == -1 && -result < INT_MIN))
                ft_error();
        i++;
    }
    return (sign * result);
}
