/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:09:30 by tberube-          #+#    #+#             */
/*   Updated: 2022/02/21 11:05:00 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "get_next_line.h"

char	*no_end_line(char **save, char *tampon)
{
	if (!*save)
	{
		*save = ft_substr(tampon, 0, 0);
	}
	*save = ft_strjoin(*save, tampon);
	// free(tampon);
	return (*save);
}

int	line_lenght(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != c)
		i++;
	return (i + 1);
}

char	*get_next_line(int fd)
{
	int			ret_bytes;
	char		*tampon;
	static char	*save;
	char		*tmp;
	// char		*free_tmp;
	
	ret_bytes = 0;
	tampon = NULL;
	tmp = NULL;
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	while (!tampon || !ft_strchr(tampon, '\n'))
	{
		tampon = malloc(sizeof(char) * BUFFER_SIZE + 1);
		ret_bytes = read(fd, tampon, BUFFER_SIZE);
		tampon[ret_bytes] = '\0';
		save = no_end_line(&save, tampon);
	}
	tmp = ft_substr(save, 0, line_lenght(save, '\n'));
	save = ft_substr(save, line_lenght(save, '\n'), line_lenght(save, '\0') - line_lenght(save, '\n'));
	// free_tmp = tmp;
	// free(tmp);
	free(tampon);
	return (tmp);
}

// int	main()
// {
// 	int	fd;

// 	fd = open("message.txt", O_RDONLY);
// 	printf("1 :%s\n", get_next_line(fd));
// 	printf("2 :%s\n", get_next_line(fd));
// 	printf("3 :%s\n", get_next_line(fd));
// 	printf("4 :%s\n", get_next_line(fd));
// 	printf("5 :%s\n", get_next_line(fd));
// 	printf("6 :%s\n", get_next_line(fd));
// 	printf("7 :%s\n", get_next_line(fd));
// 	printf("8 :%s\n", get_next_line(fd));
// 	printf("9 :%s\n", get_next_line(fd));
// 	printf("10 :%s\n", get_next_line(fd));
// 	printf("11 :%s\n", get_next_line(fd));
// 	printf("12 :%s\n", get_next_line(fd));
// 	printf("13 :%s\n", get_next_line(fd));
// 	printf("14 :%s\n", get_next_line(fd));
// 	printf("15 :%s\n", get_next_line(fd));
// 	printf("16 :%s\n", get_next_line(fd));
//  }