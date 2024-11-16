/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:53:28 by ael-jama          #+#    #+#             */
/*   Updated: 2024/11/16 11:39:44 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		totale_size;
	char	*res;
	int		i;
	int		j;

	i = 0;
	totale_size = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (totale_size + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[totale_size] = 0;
	return (res);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*d;

	i = 0;
	d = (char *)s;
	while (i < n)
	{
		*d++ = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	tab = NULL;
	if (count == 0 || size == 0 || count > SIZE_MAX / size)
		return (tab);
	tab = malloc(count * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, count * size);
	return (tab);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c && *str != 0)
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}