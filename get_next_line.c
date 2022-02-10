/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:54:18 by tberube-          #+#    #+#             */
/*   Updated: 2022/02/10 13:00:49 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*end_line(char *buffer, char *buff_check)
{
	char	tmp;
	
	tmp = (char *)malloc(ft_strlen(ft_strchr(buffer, '\n')));
	if (!tmp)
		return (0);
	tmp = ft_strchr(buffer, '\n');
	// chercher et joindre ,,,,, static doit resté avec ce quil y a après le '\n' 
	// donc si je return buff_check je renvoie ce quil y a après aussi???
}



char	*no_end_line(char *buffer, char *buff_check)
{
	int	i;

	i = 0;
	buffer[BUFFER_SIZE + 1] = '\0';
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			end_line(buffer, buff_check);
		}
		i++;
	}
	buff_check == ft_strjoin( buff_check, buffer);
	return (buff_check);
}

char	*find_end_fd(char *buffer, char *buff_check, int ret)
{
	buffer = (char *)malloc(sizeof(char) * ret + 1);
	if (!buffer)
		return (0);
	buffer[ret] = '\0';
	buff_check = ft_strjoin(buff_check, ft_substr(buffer, 0, ret));
	return (buff_check);
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
	static char	*buff_check;
	char		*buffer;
	int			ret;
	
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return (0);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		no_end_line(buffer, buff_check);
	}
	if ( BUFFER_SIZE > (ret = read(fd, buffer, BUFFER_SIZE)))
	{	
		find_end_fd(buffer, buff_check, ret);
	}
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return(NULL);
	}
	free(buffer);
	return (buff_check);
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