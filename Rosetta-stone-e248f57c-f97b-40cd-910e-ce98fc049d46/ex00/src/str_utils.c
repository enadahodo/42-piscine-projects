/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhuri <azhuri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:00:00 by azhuri            #+#    #+#             */
/*   Updated: 2024/05/18 00:00:00 by azhuri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s != NULL && s[index] != '\0')
		index++;
	return (index);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	index;

	dup = (char *)malloc(n + 1);
	if (dup == NULL)
		return (NULL);
	index = 0;
	while (index < n)
	{
		dup[index] = s[index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}

char	*ft_strdup(const char *s)
{
	return (ft_strndup(s, ft_strlen(s)));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	index;

	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0' && s1[index] == s2[index])
		index++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

int	is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}
