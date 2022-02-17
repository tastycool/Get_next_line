/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:09:30 by tberube-          #+#    #+#             */
/*   Updated: 2022/02/17 10:18:10 by tberube-         ###   ########.fr       */
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
		DEBUG;
		*save = ft_substr(tampon, 0, 0);
	}
	*save = ft_strjoin(*save, tampon);
	printf("valeur de save : %s\n", *save);
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
	// char		*line;
	int			ret_bytes;
	char		*tampon;
	static char	*save;
	char		*tmp;
	
	ret_bytes = 0;
	tampon = NULL;
	tmp = NULL;
	while (!tampon || !ft_strchr(tampon, '\n'))
	{
		tampon = malloc(sizeof(char) * BUFFER_SIZE + 1); // ne pas oublier de remettre le + 1
		ret_bytes = read(fd, tampon, BUFFER_SIZE);
		// printf("nb Bytes : %d\n", tampon_bytes);
		tampon[ret_bytes] = '\0';
		printf("save : %s\n", save);
		save = no_end_line(&save, tampon);
		printf("tampon: %s\n", tampon);
		// printf("save : %s\n", save);
	}
	printf("save : %s\n", save);
	tmp = ft_substr(save, 0, line_lenght(save, '\n'));
	save = ft_substr(save, line_lenght(save, '\n'), line_lenght(save, '\0') - line_lenght(save, '\n'));
	printf("tmp : %s\n", tmp);
	free(tampon);
	return (tmp);
}

int	main()
{
	int	fd;

	fd = open("message.txt", O_RDONLY);
	printf("%s\n\n\n\n\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}