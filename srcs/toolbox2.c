/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 23:46:10 by shamzaou          #+#    #+#             */
/*   Updated: 2023/03/31 23:46:26 by shamzaou         ###   ########.fr       */
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
		strlcpy(str, s + start, s_len - start + 1);
		return (str);
	}
	str = (char *)calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	strlcpy(str, s + start, len + 1);
	return (str);
}
