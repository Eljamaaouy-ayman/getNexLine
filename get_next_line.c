/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:38:36 by ael-jama          #+#    #+#             */
/*   Updated: 2024/11/14 20:26:35 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 100

int	ft_contains(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == c)
		return (1);
	return (0);
}

char	*ft_read(int fd, char **stock)
{
	char	*buffer;
	int		bytes_read;
	char	*s;

	s = "\0";
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free(buffer);
		return (NULL);
	}
    if (bytes_read == 0) {
		free(buffer);
		return *stock;  // Keep stock if already populated
	}
	buffer[bytes_read] = '\0';
	if (bytes_read == 0) {
		free(buffer);  // Keep stock if already populated
		return *stock;
	}
	*stock = ft_strjoin(stock, &buffer); // Join and update stock
	free(buffer);
	return (*stock);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// Initialize stock with data read
	if (stock == NULL)
		stock = ft_read(fd, &stock);
	while (stock && !ft_contains(stock, '\n') && stock != ft_read(fd, &stock))
	{
		stock = ft_read(fd, &stock);
		if (!stock)
			break ;
	}
    if(!stock && stock == ft_read(fd, &stock))
        return NULL;
	res = ft_line(stock);
	ft_rest(&stock);
	return (res);
}

int	main(void)
{
	int	fd;

	fd = open("ayman.txt", O_RDWR);
	
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    char *s = get_next_line(fd);
    while(s != NULL){
        printf("%s", s);
        s = get_next_line(fd);
    }
}
