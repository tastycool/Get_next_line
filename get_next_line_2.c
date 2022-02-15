/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:54:57 by tberube-          #+#    #+#             */
/*   Updated: 2022/02/15 11:50:20 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <limits.h>

void	*end_fd(char *buffer, char *buff_check, int end_BS)
{
	buff_check = (char *)malloc(sizeof(char) * end_BS + 1)
	if (!buff_check)
		return (0)
	buffer = ft_strjoin(&buff_check, ft_substr(buffer, 0, end_BS));
}

void	*check_line(int fd, char *buffer, char *buff_check, int end_BS)
{
	int	i;

	i = 0;
	end_BS = read(fd, buffer, BUFFER_SIZE);
	buffer[end_BS] = '\0';
	if (end_BS < BUFFER_SIZE)
		{
			buffer = end_fd(buffer, &buff_check, end_BS);
			return (0);
		}
	while (*buffer++)
	{
		if (*buffer == '\n')
		{
			i = ft_strlen(ft_strchr(buffer, '\n'));
			buffer = ft_strjoin(buff_check, buffer);
			buff_check = ft_substr(buffer, i + 1, ft_strlen(buffer) - i);
			buffer = ft_substr(buffer, 0, i);
		}
	}
	if (!buff_check)
		buff_check = ft_substr(&buff_check, 0, 0);
	buffer = ft_strjoin(buff_check, buffer);
}

char	*get_next_line(int fd)
{
	static char	*buff_check;
	char		*buffer;
	int			end_BS;

	end_BS = 0;
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	buffer = check_line(fd, buffer, &buff_check, end_BS);
}