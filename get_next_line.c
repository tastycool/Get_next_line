/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:54:18 by tberube-          #+#    #+#             */
/*   Updated: 2022/02/07 13:22:06 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	check_line(int fd, char *str);
{
	int	i;

	i = 0;
	while (str != '\n' || str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return ();
	if (str[i] == '\n')
			
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
		buff_check = malloc(sizeof(char) + 1);
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
	return (check_line(fd, buffer));
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
}