/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:45:22 by tberube-          #+#    #+#             */
/*   Updated: 2022/03/02 20:22:05 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*end_line(char *all_Line, char **save)
{
	char	*tmp;

	free (*save);	
	*save = ft_substr(all_Line, l_cnt(all_Line, '\n'), ft_strlen(all_Line) - l_cnt(all_Line, '\n')); // probleme ce n'est pas une static
	tmp = ft_substr(all_Line, 0, l_cnt(all_Line, '\n'));
	free(all_Line);
	//printf("tmp = %s\n", tmp);
	return (tmp);
}

int	l_cnt(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i + 1);
}

char	*read_line(int fd, char *all_Line, int *Bytes_read)
{
	char	*tmp;
	char	tampax[BUFFER_SIZE + 1];

	// printf("addresse all_Line = %s\n", all_Line);
	*Bytes_read = read(fd, tampax, BUFFER_SIZE);
	if (*Bytes_read <= 0)
	{
		if (all_Line && all_Line[0])
			return (all_Line);
		return (NULL);
	}
	tampax[*Bytes_read] = '\0';
	if (Bytes_read == 0)
		return (all_Line);
	if (!all_Line)
	{
		all_Line = ft_substr(tampax, 0, ft_strlen(tampax));
		return (all_Line);
	}
	tmp = ft_strjoin(all_Line, tampax);
	free(all_Line);
	//printf("tmp = : %s\n", tmp);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*all_Line;
	int			Bytes_read;

	all_Line = NULL;
	if (fd == -1 || fd >= 1000 || BUFFER_SIZE <= 0) // a voir pour le 1000
		return (all_Line);
	if (ft_strlen(save) > 0)
		all_Line = ft_strjoin(save, "");
	while (!all_Line || !ft_strchr(all_Line, '\n'))
	{
		all_Line = read_line(fd, all_Line, &Bytes_read); //peut etre un leak;
		if (Bytes_read <= 0) //|| (Bytes_read == 0 && (!save || !save[0])))
		{
			free (save);
			save = NULL;
			if (all_Line)
				return (all_Line);	
			return (NULL);
		}
		if (Bytes_read < BUFFER_SIZE)
			break;
	}
	if (ft_strchr(all_Line, '\n'))	
		return (end_line(all_Line, &save));
	if ((!save || !save[0]) && Bytes_read == 0)
		return (all_Line);
	return (all_Line);
}

// int main()
// {
// 	int fd = open("./gnlTester/files/empty", O_RDWR);
// 	get_next_line(fd);
// 	return (0);
// }