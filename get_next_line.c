/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:54:18 by tberube-          #+#    #+#             */
/*   Updated: 2022/02/08 11:35:37 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_line(int fd, char *buffer, char *buff_check)
{	
	int	i;
	int j;
	
	j = ft_strlen(buffer);
	while (buffer[i] != '\n' || buffer[i] != '\0')
	{	
		if (j ==  0)
			{
				if (!buff)
				ft_strjoin()
			}
		i++;
		j--
	}
	if (buffer[i] == '\n')
	{
		ft_substr(buffer, 0, BUFFER_SIZE); // questionnement?????????
		return (buffer);
	}
	if (read(fd, buffer, BUFFER_SIZE) < BUFFER_SIZE && ft_strlen(buff_check) != 0)
		return(buffer);
			
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char		*ret_line;
	static char	*buff_check;
	char		*buffer;
	
	if (!buff_check)
		buff_check = malloc(sizeof(char));
	if (!buff_check)
		return (NULL);
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return(NULL);
	}
	read()
	return (check_line(fd, buffer, buff_check));
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