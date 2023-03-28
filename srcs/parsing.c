/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:13:39 by shamzaou          #+#    #+#             */
/*   Updated: 2023/03/28 13:02:55 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* is_sign():
*   Returns 1 if the element is a sign.
*   Returns 0 if the element isn't a sign.
*/
int is_sign(char *str)
{
    int i;

    i = 0;
    if ((str[i] == '-') || (str[i] == '+'))
        return (1);
    else
        return (0);
}

int is_int(char *str)
{
    int i;

    i = 0;

    if (is_sign(str[i]) && str[i + 1] != '\0')
        i++;
    while (str[i] && is_digit(str[i]))
        i++;
    if (str[i] && !is_digit(str[i]))
        return (0);
    return (0);

}

int *parse_args(int argc, char **argv)
{
    int *arr = NULL;
    int i;
    int j;

    if (argc < 2)
        error();

    i = 1;
    j = 0;
    while (i < argc)
    {
        
    }
    
}