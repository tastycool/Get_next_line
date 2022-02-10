/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:25:10 by tberube-          #+#    #+#             */
/*   Updated: 2022/02/10 09:44:29 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }


// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	char		*a_dst;
// 	const char	*a_src;
// 	size_t		j;

// 	a_dst = dst;
// 	a_src = src;
// 	j = 0;
// 	if (dstsize == 0)
// 		return (ft_strlen(src));
// 	while (dstsize > 1 && a_src[j] != '\0')
// 	{
// 		a_dst[j] = a_src[j];
// 		j++;
// 		dstsize--;
// 	}
// 	a_dst[j] = '\0';
// 	while (a_src[j] != '\0')
// 		j++;
// 	return (j);
// }

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


// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*str;

// 	if (!s)
// 		return (0);
// 	// if (len == 0 || start > ft_strlen(s))
// 	// 	return (ft_strdup(""));
// 	if (len > ft_strlen(s))
// 		len = ft_strlen(s);
// 	str = malloc((len + 1) * sizeof(char));
// 	if (!str)
// 		return (0);
// 	ft_strlcpy(str, s + start, len + 1);
// 	return (str);
// }
int main()
{
	char	str[] = "sal\nut";
	printf("%s\n", ft_strchr(str, '\n'));
}

