/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 23:46:10 by shamzaou          #+#    #+#             */
/*   Updated: 2023/04/10 14:41:01 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		ft_strlcpy(str, s + start, s_len - start + 1);
		return (str);
	}
	str = (char *)calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;

	if (!size)
		return (ft_strlen(src));
	index = 0;
	while (src[index] && index < (size - 1))
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_set_check(const char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && ft_set_check(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_set_check(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, (end - start)));
}