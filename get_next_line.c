/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:09:30 by tberube-          #+#    #+#             */
/*   Updated: 2022/02/23 09:18:22 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "get_next_line.h"

void	no_end_line(char **save, char *tampon)
{
	char *temp;
	
	temp = NULL;
	if (!*save)
	{
		temp  = ft_substr(tampon, 0, 0);
		*save = temp;
	}
		// leak here
	*save = ft_strjoin(*save, tampon);
	free(temp);
}

char	*check_line(int fd, char *tampon, char **save)
{
	int	ret_bytes;
	char	*tmp;

	tmp = NULL;
	ret_bytes = read(fd, tampon, BUFFER_SIZE);
	tampon[ret_bytes] = '\0';
		//printf("debug1: %i\n", ret_bytes);
	if (ret_bytes <= 0)
	{
			// end_fd(save, tampon, tmp);
		free(tampon);
			//printf("%s\n", save);
		if (ft_strlen(*save) == 0)
			return (NULL);
		tmp = *save;			
		*save = ft_substr(*save, line_lenght(*save, '\n'), line_lenght(*save, '\0') - line_lenght(*save, '\n'));
		return (tmp);
	}
	return(0);
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
	// int			ret_bytes;
	char		*tampon;
	static char	*save;
	char		*tmp;
	
	tmp = NULL;
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	tampon = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tampon)
		return (NULL);
	while (!save || !ft_strchr(save, '\n'))
	{
		check_line(fd, tampon, &save);
		no_end_line(&save, tampon);
	}		
	free(tampon);
	tmp = ft_substr(save, 0, line_lenght(save, '\n'));
	// free this save
	save = ft_substr(save, line_lenght(save, '\n'), line_lenght(save, '\0') - line_lenght(save, '\n'));
	return (tmp);
}

