/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:39:52 by tberube-          #+#    #+#             */
/*   Updated: 2022/01/26 11:05:24 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

typedef struct s_get
{
	char	str;
	int		b_size;
	char	tmp;
} t_get;

char	*get_next_line(int const fd);

#endif

