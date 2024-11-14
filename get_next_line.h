/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:28:26 by ael-jama          #+#    #+#             */
/*   Updated: 2024/11/14 16:53:37 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>


char    *get_next_line(int fd);
char    *ft_line(char *s);
int	    ft_contains(char *s, char c);
void    ft_rest(char **stock);
char	*ft_strdup(char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char  **s1, char **s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);

#endif