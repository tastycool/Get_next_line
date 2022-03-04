/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:45:22 by tberube-          #+#    #+#             */
/*   Updated: 2022/03/04 07:28:12 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*end_line(char *all_Line, char **save)
{
	char	*tmp;
	
	free (*save);	
	*save = ft_substr(all_Line, l_cnt(all_Line, '\n'), ft_strlen(all_Line) - l_cnt(all_Line, '\n'));
	if (ft_strchr(all_Line, '\n'))
	{
		tmp = ft_substr(all_Line, 0, l_cnt(all_Line, '\n'));
		free(all_Line);
		return (tmp);
	}
	else
		return (all_Line); // coupé all line
	return (NULL);
}

void	free_pointer(char **str)
{
	free(*str);
	*str = NULL;
}

int	l_cnt(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i + 1);
}

char	*read_line(int fd, char *all_Line, int *Bytes_read, char **save)
{
	char	*tmp;
	char	tampax[BUFFER_SIZE + 1];

	(*Bytes_read) = read(fd, tampax, BUFFER_SIZE);
	printf("tampax = %s\n", tampax);
	tampax[*Bytes_read] = '\0';
	if (*Bytes_read <= 0)
	{
		if (all_Line && save)
		{
			//printf("save = %s\n", *save);
			// printf("tampax = %s\n", tampax);
			return (all_Line);
		}			
		return (NULL);
	}
	if (!all_Line)
	{
		all_Line = ft_substr(tampax, 0, ft_strlen(tampax));
		printf("all_line = %s\n", all_Line);
		return (all_Line);
	}
	tmp = ft_strjoin(all_Line, tampax);
	free(all_Line);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*all_Line;
	int			Bytes_read;

	all_Line = NULL;
	if (fd == -1 || fd >= 1000 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strlen(save) > 0)
		all_Line = ft_strjoin(save, "");
	while (!all_Line || !ft_strchr(all_Line, '\n'))
	{
		all_Line = read_line(fd, all_Line, &Bytes_read, &save);
		if (Bytes_read <= 0)
		{
			free_pointer(&save);
			//DEBUG;
			if (all_Line || Bytes_read == 0)
				return (all_Line);	
			return (NULL);
		}
		if (Bytes_read < BUFFER_SIZE)
			break;
	}
	if (ft_strchr(all_Line, '\n'))	
		return (end_line(all_Line, &save));
	return (all_Line);
}
