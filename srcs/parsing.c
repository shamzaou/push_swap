/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:13:39 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/11 18:20:53 by shamzaou         ###   ########.fr       */
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

/* parse_args():
*   This funct will perform parsing of the user input
*   1. Checks the existence of at least one argument.
*   2. Checks for non integer numeric input.
*   3. Convert the input to an int array with ft_atoi
*       that will check for overflow and underflow.
*   4. Checks for duplicates inside convert().
*/
int parse_args(int argc, char **argv, int **arr_ptr)
{
    int total_numbers = 0;
    int *arr;
    int i;
    int j;
    char **tokens;

    if (argc < 2)
        exit(1);

    // add condiition

    for (i = 1; i < argc; i++)
    {
        if (is_empty_or_whitespace(argv[i]))
            ft_error();
        total_numbers += count_numbers(argv[i]);
    }

    arr = (int *)malloc(sizeof(int) * total_numbers);
    if (!arr)
        return (0);

    j = 0;
    for (i = 1; i < argc; i++)
    {
        tokens = ft_split(argv[i], ' ');
        int k = 0;
        while (tokens[k] != NULL)
        {
            if (!is_int(tokens[k]))
                ft_error();
            arr[j++] = ft_atoi(tokens[k]);
            k++;
        }

        // Free the memory allocated for the tokens
        int l = 0;
        while (tokens[l] != NULL)
        {
            free(tokens[l]);
            l++;
        }
        free(tokens);
    }

    for (i = 0; i < total_numbers; i++)
    {
        for (j = i + 1; j < total_numbers; j++)
        {
            if (arr[i] == arr[j])
                ft_error();
        }
    }

    *arr_ptr = arr;
    return total_numbers;
}

// Add a new helper function to check if a string contains only spaces
int is_only_spaces(const char *str)
{
    while (*str)
    {
        if (*str != ' ' && *str != '\t')
            return 0;
        str++;
    }
    return 1;
}


int count_numbers(const char *str)
{
    int count = 0;
    char **tokens = ft_split(str, ' ');

    int i = 0;
    while (tokens[i] != NULL)
    {
        count++;
        i++;
    }
    // Free the memory allocated for the tokens
    int j = 0;
    while (tokens[j] != NULL)
    {
        free(tokens[j]);
        j++;
    }
    free(tokens);
    return count;
}

int is_empty_or_whitespace(const char *str)
{
    while (*str)
    {
        if (!isspace((unsigned char)*str))
            return 0;
        str++;
    }
    return 1;
}
