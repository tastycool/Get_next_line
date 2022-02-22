/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:09:30 by tberube-          #+#    #+#             */
/*   Updated: 2022/02/22 10:14:05 by tberube-         ###   ########.fr       */
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
	return (*save);
}

char	*end_fd(char *save, char *tampon, char *tmp)
{
	free(tampon);
	DEBUG;
	tmp = save;
	free(save);
	return (tmp);
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
	
	tmp = NULL;
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	tampon = malloc(sizeof(char) * BUFFER_SIZE + 1);
	printf("malloc 1 : %p\n", tampon);
	if (!tampon)
		return (NULL);
	while (!save || !ft_strchr(save, '\n'))
	{
		ret_bytes = read(fd, tampon, BUFFER_SIZE);
		tampon[ret_bytes + 1] = '\0';
		if (ret_bytes <= 0)
		{
			// end_fd(save, tampon, tmp);
			free(tampon);
			tmp = save;
			free(save);
			return (tmp);
		}
		save = no_end_line(&save, tampon);
	}
	// end_line(&save, tmp);
	free(tampon);
	tmp = ft_substr(save, 0, line_lenght(save, '\n'));
	save = ft_substr(save, line_lenght(save, '\n'), line_lenght(save, '\0') - line_lenght(save, '\n'));
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
// 	printf("17 :%s\n", get_next_line(fd));
// 	printf("18 :%s\n", get_next_line(fd));
// 	printf("19 :%s\n", get_next_line(fd));
// 	printf("20 :%s\n", get_next_line(fd));
// 	printf("21 :%s\n", get_next_line(fd));
// 	printf("22 :%s\n", get_next_line(fd));
// 	printf("23 :%s\n", get_next_line(fd));
// 	printf("24 :%s\n", get_next_line(fd));
// 	printf("25 :%s\n", get_next_line(fd));
// 	printf("26 :%s\n", get_next_line(fd));
// 	printf("27 :%s\n", get_next_line(fd));
// 	printf("28 :%s\n", get_next_line(fd));
// 	printf("29 :%s\n", get_next_line(fd));
// 	printf("30 :%s\n", get_next_line(fd));
// 	printf("31 :%s\n", get_next_line(fd));
// 	printf("32 :%s\n", get_next_line(fd));
// 	printf("33 :%s\n", get_next_line(fd));
// 	printf("34 :%s\n", get_next_line(fd));
// 	printf("35 :%s\n", get_next_line(fd));
// 	printf("36 :%s\n", get_next_line(fd));
// 	printf("37 :%s\n", get_next_line(fd));
// 	printf("38 :%s\n", get_next_line(fd));
// 	printf("39 :%s\n", get_next_line(fd));
// 	printf("40 :%s\n", get_next_line(fd));
// 	printf("41 :%s\n", get_next_line(fd));
// 	printf("42 :%s\n", get_next_line(fd));
// 	printf("43 :%s\n", get_next_line(fd));
// 	printf("44 :%s\n", get_next_line(fd));
// 	printf("45 :%s\n", get_next_line(fd));
// 	printf("46 :%s\n", get_next_line(fd));
// 	printf("47 :%s\n", get_next_line(fd));
// 	printf("48 :%s\n", get_next_line(fd));
// 	printf("49 :%s\n", get_next_line(fd));
// 	printf("50 :%s\n", get_next_line(fd));	
//  }
