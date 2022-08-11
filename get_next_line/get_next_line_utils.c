/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdulla <dj.ali9292@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:29:25 by mabdulla          #+#    #+#             */
/*   Updated: 2022/08/11 09:48:41 by mabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char	*s, int c)
{
	char	*s1;

	s1 = (char *)s;
	if (s1 == 0)
		return (0);
	while ((char)c != *s1)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
	}
	return (s1);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ss;

	if (s1 == 0)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	ss = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ss)
		return (0);
	i = -1;
	while (s1[++i] != '\0')
		ss[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		ss[i++] = s2[j];
	ss[i] = '\0';
	free (s1);
	return (ss);
}
