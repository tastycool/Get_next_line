/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:09:30 by tberube-          #+#    #+#             */
/*   Updated: 2022/02/16 14:08:31 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "get_next_line.h"

// char	*no_end_line(char *tampon, char **save)
// {
// 	if (!save)
// 		DEBUG;
// 		*save = ft_substr(*save, 0, 0);
// 	*save = ft_strjoin(tampon, *save);
// 	// save = ft_substr(save, 0, 2);
// 	printf("valeur de save : %s\n", *save);
// 	return (*save);
// }

// int	*line_lenght(char *str, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != c)
// 		i++;
// 	tamponurn (i + 1);
// }

char	*get_next_line(int fd)
{
	char		*line;
	int			ret_bytes;
	char		*tampon;
	static char	*save;
	
	ret_bytes = 0;
	tampon = NULL;
	while (!tampon || !ft_strchr(tampon, '\n'))
	{
		tampon = malloc(sizeof(char) * BUFFER_SIZE + 1); // ne pas oublier de remettre le + 1
		ret_bytes = read(fd, tampon, BUFFER_SIZE);
		// printf("nb Bytes : %d\n", tampon_bytes);
		tampon[ret_bytes] = '\0';
		printf("tampon : %s\n", tampon);
		line = ft_strjoin(tampon, save);
		printf("line %s\n", line);
		// printf("save : %s\n", save);
	}
	free(tampon);
	return (line);
}

int	main()
{
	int	fd;

	fd = open("message.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
}