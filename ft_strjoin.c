/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:54:45 by ael-jama          #+#    #+#             */
/*   Updated: 2024/11/05 15:44:34 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;
	int		k;

	if (s1 == NULL)
		return ((char *)s2);
	if (s2 == NULL)
		return ((char *)s1);
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	i = -1;
	k = ft_strlen(s1);
	j = ft_strlen(s2);
	s3 = malloc(k + j + 1);
	if (s3 == NULL)
		return (NULL);
	while (++i < k)
		s3[i] = s1[i];
	i--;
	while (i++ < k + j - 1)
		s3[i] = s2[i - k];
	s3[i] = '\0';
	return (s3);
}
