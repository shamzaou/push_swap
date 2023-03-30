/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:40:59 by shamzaou          #+#    #+#             */
/*   Updated: 2023/03/30 20:20:20 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void    ft_error(void)
{
    write(STDERR_FILENO, "Error\n", 6);
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
        if (sign == 1 && result > INT_MAX)
            ft_error();
        if (sign == -1 && -result < INT_MIN)
            ft_error();
        i++;
    }
    return (sign * result);
}

/*int main(int ac, char **av)
{
    printf("Value : %d\n", ft_atoi(av[1]));
}*/

static size_t	str_length(char const *str, char c, size_t	start)
{
	size_t	length;

	length = start;
	while (str[length] && str[length] != c)
	{
		length++;
	}
	length = length - start;
	return (length);
}

static size_t	str_count(char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	len = strlen(s);
	while (i < len)
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != '\0')
			count++;
		i = i + str_length(s, c, i);
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**split;

	i = 0;
	j = 0;
	split = (char **)calloc(sizeof(char *), (str_count(s, c) + 1));
	if (!split || !s)
	{
		free((void **)split);
		return (NULL);
	}
	while (j < (str_count(s, c)))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] && s[i] != '\0')
			split[j] = ft_substr(s, i, str_length(s, c, i));
		if (!split[j])
			return (NULL);
		i = i + str_length(s, c, i);
		j++;
	}
	return (split);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = strlen(s);
	if (start > s_len || len <= 0)
		return (strdup(""));
	if ((start + len) > s_len)
	{
		str = (char *)calloc(s_len - start + 1, sizeof(char));
		if (str == NULL)
			return (NULL);
		strlcpy(str, s + start, s_len - start + 1);
		return (str);
	}
	str = (char *)calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	strlcpy(str, s + start, len + 1);
	return (str);
}
