/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:13:39 by shamzaou          #+#    #+#             */
/*   Updated: 2023/03/31 01:48:57 by shamzaou         ###   ########.fr       */
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
/*int *parse_args(int argc, char **argv)
{
    int *arr = NULL;
    int i;

        // this must be verified
    if (argc < 2)
        exit(1);

    i = 1;
    while (i < argc)
    {
        if (!is_int(argv[i]))
            ft_error();
        i++;
    }
    arr = convert(argc, argv);

    

    return (arr);
}*/

/*int main(int ac, char **av)
{
    int i = 0;
    int *arr = parse_args(ac, av);

    while (i < ac - 1)
    {
        printf("element : %d\n", arr[i]);
        i++;
    }
    
}*/
/*
int *parse_args(int argc, char **argv)
{
    int *arr = NULL;
    int token_count = 0;
    int i, j;

    if (argc < 2)
        exit(1);

    // Count the total number of tokens (numbers) across all arguments
    for (i = 1; i < argc; ++i)
    {
        char *token = strtok(argv[i], " ");
        while (token != NULL)
        {
            token_count++;
            token = strtok(NULL, " ");
        }
    }

    // Allocate memory for the array
    arr = (int *)malloc(sizeof(int) * token_count);

    // Fill the array with the numbers from each argument
    j = 0;
    for (i = 1; i < argc; ++i)
    {
        char *token = strtok(argv[i], " ");
        while (token != NULL)
        {
            if (!is_int(token))
                ft_error();
            arr[j++] = ft_atoi(token);
            token = strtok(NULL, " ");
        }
    }

    return (arr);
}
*/

/*
                THIS IS THE CORRECT VERSION====================
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

int parse_args(int argc, char **argv, int **arr_ptr)
{
    int total_numbers = 0;
    int *arr;
    int i;
    int j;
    char *token;

    for (i = 1; i < argc; i++)
        total_numbers += count_numbers(argv[i]);

    arr = (int *)malloc(sizeof(int) * total_numbers);
    if (!arr)
        return (0);

    j = 0;
    for (i = 1; i < argc; i++)
    {
        token = strtok(argv[i], " \t");
        while (token != NULL)
        {
            if (!is_int(token))
                ft_error();
            arr[j++] = ft_atoi(token);
            token = strtok(NULL, " \t");
        }
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
*/

int parse_args(int argc, char **argv, int **arr_ptr)
{
    int total_numbers = 0;
    int *arr;
    int i;
    int j;
    char **tokens;

    for (i = 1; i < argc; i++)
        total_numbers += count_numbers(argv[i]);

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
