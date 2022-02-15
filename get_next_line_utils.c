/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:59:27 by tberube-          #+#    #+#             */
/*   Updated: 2022/02/15 09:55:12 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (0);
	// if (len == 0 || start > ft_strlen(s))
	// 	return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

// char	*ft_strdup(const char *s1)
// {
// 	char	*str;
// 	int		len;

// 	str = (char *)s1;
// 	len = ft_strlen(s1) + 1;
// 	str = malloc(len * sizeof(char));
// 	if (str == NULL)
// 		return (0);
// 	ft_memcpy(str, s1, len);
// 	return (str);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	if (!s1)
		return (0);
	dst = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dst)
		return (0);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
		dst[i++] = s2[j++];
	dst[i] = '\0';
	return (dst);
}

// void	*ft_memcpy(void *dst, const void *src, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*str1;
// 	const char		*str2;

// 	i = 0;
// 	str1 = dst;
// 	str2 = src;
// 	if (!str1 && !str2)
// 		return (0);
// 	while (n > i)
// 	{
// 		str1[i] = str2[i];
// 		i++;
// 	}
// 	return (str1);
// }

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*a_dst;
	const char	*a_src;
	size_t		j;

	a_dst = dst;
	a_src = src;
	j = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (dstsize > 1 && a_src[j] != '\0')
	{
		a_dst[j] = a_src[j];
		j++;
		dstsize--;
	}
	a_dst[j] = '\0';
	while (a_src[j] != '\0')
		j++;
	return (j);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != '\0')
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if (*s == '\0' && c == '\0')
		return ((char *) s);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}