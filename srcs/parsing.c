/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:13:39 by shamzaou          #+#    #+#             */
/*   Updated: 2023/03/30 07:23:48 by shamzaou         ###   ########.fr       */
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

/* convert():
*   Converts values and stores them in an int array.
*   Checks for duplicates and return Error if found.
*/
int *convert(int argc, char **argv)
{
    int *arr;
    int i;
    int j;
    
    arr = (int *)malloc(sizeof(int) * (argc - 1));
    if (!arr)
        return (0);
    i = 1;
    j = 0;
    while (argv[i])
    {
        arr[i - 1] = ft_atoi(argv[i]);
        j = 0;
        while (j < i - 1)
        {
            if (arr[i - 1] == arr[j])
                ft_error();
            j++;
        }
        i++;
    }
    return (arr);
}

int count_numbers(char *str)
{
    int count = 0;
    int i = 0;

    while (str[i])
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\t'))
            i++;
        if (str[i] && (str[i] != ' ' && str[i] != '\t'))
        {
            count++;
            while (str[i] && (str[i] != ' ' && str[i] != '\t'))
                i++;
        }
    }
    return (count);
}

int count_args(int argc, char **argv)
{
    int i, j, count;

    count = 0;
    for (i = 1; i < argc; i++)
    {
        j = 0;
        while (argv[i][j])
        {
            if (ft_isdigit(argv[i][j]) || is_sign(&argv[i][j]))
            {
                count++;
                while (argv[i][j] && (ft_isdigit(argv[i][j]) || is_sign(&argv[i][j])))
                {
                    j++;
                }
            }
            else
            {
                j++;
            }
        }
    }
    return count;
}

int *parse_args(int argc, char **argv)
{
    int *arr;
    int arg_count;
    int i, j, k;

    arg_count = count_args(argc, argv);
    arr = (int *)malloc(sizeof(int) * arg_count);
    if (!arr)
        return (0);

    k = 0;
    for (i = 1; i < argc; i++)
    {
        j = 0;
        while (argv[i][j])
        {
            if (ft_isdigit(argv[i][j]) || is_sign(&argv[i][j]))
            {
                arr[k++] = ft_atoi(&argv[i][j]);
                while (argv[i][j] && (ft_isdigit(argv[i][j]) || is_sign(&argv[i][j])))
                {
                    j++;
                }
            }
            else
            {
                j++;
            }
        }
    }

    for (i = 0; i < arg_count; i++)
    {
        for (j = i + 1; j < arg_count; j++)
        {
            if (arr[i] == arr[j])
                ft_error();
        }
    }

    return arr;
}