/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:54:57 by tberube-          #+#    #+#             */
/*   Updated: 2022/02/16 14:53:32 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <limits.h>

char	*end_line(char *buffer, char **remening, int i)
{
	i = ft_strlen(ft_strchr(buffer, '\n'));
	buffer = ft_strjoin(remening, buffer);
	remening = ft_substr(buffer, i + 1, ft_strlen(buffer) - i);
	buffer = ft_substr(buffer, 0, i);
	return (buffer);
}

char	*end_fd(char *buffer, char **remening, int ret_bytes)
{
	remening = (char *)malloc(sizeof(char) * ret_bytes + 1);
	if (!remening)
		return (0);
	buffer = ft_strjoin(remening, ft_substr(buffer, 0, ret_bytes));
	return (buffer);
}

char	*check_line(int fd, char *buffer, char **remening, int ret_bytes)
{
	int	i;

	i = 0;
	ret_bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[ret_bytes] = '\0';
	while (!ft_strchr(buffer, '\n'))
	{
		buffer
		if (ret_bytes < BUFFER_SIZE)
		{
			buffer = end_fd(buffer, remening, ret_bytes);
			return (buffer);
		}
		if (*buffer == '\n')
		{
			buffer = end_line(buffer, remening, i);
			return (buffer);
		}
	}
	if (!remening)
		remening = ft_substr(remening, 0, 0);
	buffer = ft_strjoin(remening, buffer);
	return (buffer);
}

int	search_lenght(char *str, int c)
{
	int	i;
	
	i = 0;
	while (str[i] != c)
		i++;
	return (i + 1);
}

char	*get_next_line(int fd)
{
	static char	*remening;
	char		*buffer;
	int			ret_bytes;

	ret_bytes = 0;
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = check_line(fd, buffer, remening, ret_bytes);
	return (buffer);
}
int main()
{
	int	fd;

	fd = open("message.txt", O_RDONLY);
	DEBUG;
	printf("%s", get_next_line(fd));
	close(fd);
}