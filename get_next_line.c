/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:54:18 by tberube-          #+#    #+#             */
/*   Updated: 2022/02/16 11:53:02 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

char	*end_line(char *buffer, char *buff_check)
{
	int	tmp;

	tmp = ft_strlen(ft_strchr(buffer, '\n'));
	//tmp = (char *)malloc(ft_strlen(ft_strchr(buffer, '\n')));
	// if (!tmp)
	// 	return (0);
	buffer = ft_strjoin(buff_check, buffer);
	buff_check = ft_substr(buffer, tmp + 1, ft_strlen(buffer) - tmp);
	//tmp = ft_strchr(buffer, '\n');       test sans tmp;
	buffer = ft_substr(buffer, 0, tmp);
	// ne peut pas return (buff_check) triqué le code 
	return (buffer);
}



char	*no_end_line(char *buffer, char *buff_check)
{
	int	i;

	i = 0;
	fd_end = read(fd, buffer, BUFFER_SIZE)
	buffer[fd_end] = '\0';
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			end_line(buffer, buff_check);
			return (buffer);
		}
		i++;
	}
	if (!buff_check)
		buff_check = ft_substr(buff_check, 0, 0);
	buffer = ft_strjoin(buff_check, buffer);
	return (buffer);
}
// regarder demain mardi
char	*find_end_fd(char *buffer, char *buff_check, int fd_end)
{
	buff_check = (char *)malloc(sizeof(char) * fd_end + 1);
	if (!buff_check)
		return (0);
	//buffer[ret] = '\0';
	buffer = ft_strjoin(buff_check, ft_substr(buffer, 0, fd_end));
	//buffer[ret] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buff_check;
	char		*buffer;
	int			fd_end;
	
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (read(fd, buffer, BUFFER_SIZE) == BUFFER_SIZE)
	{
		buffer = no_end_line(buffer, &buff_check);
	}
	
	if (BUFFER_SIZE > (fd_end = read(fd, buffer, BUFFER_SIZE)))
	{	
		find_end_fd(buffer, buff_check, fd_end);
	}
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return(NULL);
	}
	//free(buffer);
	return (buffer);
}
int	main()
{
	int	fd;
	//char	*str;

	fd = open("message.txt", O_RDONLY);
	// open file
	//printf("%d\n", fd);
	//str = get_next_line(fd);
	// print fd
	printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// while (*str == '\n')
	// 	printf("%s", str);
	// call gnl 
	close(fd);
}