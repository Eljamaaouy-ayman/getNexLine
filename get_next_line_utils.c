/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:40:42 by ael-jama          #+#    #+#             */
/*   Updated: 2024/11/14 16:51:01 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
size_t	ft_strlen(const char *s)
{
	int	i;

	if(s == NULL){
		printf("ana NULL");
		return 0;}
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (dst == NULL && dstsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	i = dst_len;
	while (i < dstsize - 1 && src[i - dst_len] != '\0')
	{
		dst[i] = src[i - dst_len];
		i++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = count * size;
	if (count != 0 && total_size / count != size)
		return (NULL);
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}
char	*ft_strdup(char *s1)
{
	size_t	s_len;
	size_t	i;
	char	*s2;

	s_len = ft_strlen(s1);
	s2 = (char *)malloc(s_len + 1);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char **s1, char **s2)
{
	char	*s3;
	int		i;
	int		j;
	int		k;

	if (*s1 == NULL)
		return (ft_strdup(*s2));
	if (*s2 == NULL)
		return (ft_strdup(*s1));
	i = -1;
	k = ft_strlen(*s1);
	j = ft_strlen(*s2);
	s3 = malloc(k + j + 1);
	if (s3 == NULL)
		return (NULL);
	while (++i < k)
		s3[i] = (*s1)[i];
	i--;
	while (i++ < k + j - 1)
		s3[i] = (*s2)[i - k];
	s3[i] = '\0';
	free((void *)*s1);
	// free((void *)*s2);
	return (s3);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
// hello world\nthis is
// this is
void ft_rest(char **stock)
{
	int i;
	int j;
	char *buffer;
	
	i = 0;
	while((*stock)[i] != '\n')
		i++;
	buffer = malloc(ft_strlen(*stock) - i + 1);
	if(buffer == NULL)
		return ;
	buffer[ft_strlen(*stock) - i] = '\0';
	j = 0;
	while((*stock)[i + j + 1] != '\0')
	{
		buffer[j] = (*stock)[i + j + 1];
		j++;
	}
	free(*stock);
	*stock = ft_strdup(buffer);
	free(buffer);
}
char *ft_line(char *s)
{
	int i;
	char *new_s;

	i = 0;
	if(!ft_contains(s, '\n'))
		return s;
	while(s[i] != '\0' && s[i] != '\n')
		i++;
	if(s[i] == '\0')
	{
		new_s = (char *)malloc(i + 1);
		ft_strlcpy(new_s, s, i + 1);
	}
	if(s[i] == '\n')
	{
		new_s = (char *)malloc(i + 2);
		ft_strlcpy(new_s, s, i + 2);
	}
	return new_s;
}
