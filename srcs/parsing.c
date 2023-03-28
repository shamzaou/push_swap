/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:13:39 by shamzaou          #+#    #+#             */
/*   Updated: 2023/03/28 22:05:41 by shamzaou         ###   ########.fr       */
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
    if (is_sign(&str[i]) && str[i + 1] != '\0')
        i++;
    while (str[i] && ft_isdigit(str[i]))
        i++;
    if (str[i] && !ft_isdigit(str[i]))
        return (0);
    return (1);
}

int *convert(int argc, char **argv)
{
    int *arr;
    int i;

    arr = (int *)malloc(sizeof(int) * (argc - 1));
    if (!arr)
        return (0);
    i = 1;
    while (argv[i])
    {
        arr[i - 1] = ft_atoi(argv[i]);
        i++;
    }
    return (arr);
}

/* parse_args:
*   This funct will perform parsing of the user input
*   1. Checks the existence of at least one argument.
*   2. Checks for non integer numeric input.
*   3. Convert the input to an int array with ft_atoi
        that will check for overflow and underflow.
    4. Checks for duplicates.
*/
int *parse_args(int argc, char **argv)
{
    int *arr = NULL;
    int i;
    int j;

    if (argc < 2)
        ft_error();

    i = 1;
    j = 0;
    while (i < argc)
    {
        if (!is_int(argv[i]))
            ft_error();
        i++;
    }
    arr = convert(argc, argv);
    return (arr);
}

int main(int ac, char **av)
{
    int i = 0;
    int *arr = parse_args(ac, av);

    while (i < ac - 1)
    {
        printf("element : %d\n", arr[i]);
        i++;
    }
    
}