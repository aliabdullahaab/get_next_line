/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdulla <dj.ali9292@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:29:14 by mabdulla          #+#    #+#             */
/*   Updated: 2022/08/11 09:43:38 by mabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_nextstr(char *str)
{
	int		i;
	int		j;
	char	*str1;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		free (str);
		return (0);
	}
	str1 = (char *)malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (str1 == 0)
		return (0);
	i++;
	j = 0;
	while (str[i] != '\0')
		str1[j++] = str[i++];
	str1[j] = '\0';
	free (str);
	return (str1);
}

static char	*ft_firststr(char *str)
{
	char	*str1;
	int		i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		str1 = (char *)malloc((i + 2) * sizeof(char));
	else
		str1 = (char *)malloc((i + 1) * sizeof(char));
	if (str1 == 0)
		return (0);
	i = -1;
	while (str[++i] != '\n' && str[i] != '\0')
		str1[i] = str[i];
	if (str[i] == '\n')
	{
		str1[i] = '\n';
		i++;
	}
	str1[i] = '\0';
	return (str1);
}

static char	*ft_read(int fd, char *str)
{
	char	*temp;
	int		len;

	len = 1;
	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (temp == 0)
		return (0);
	while (0 == ft_strchr(str, '\n') && len != 0)
	{
		len = read(fd, temp, BUFFER_SIZE);
		if (len == -1)
		{
			free (temp);
			return (0);
		}
		temp[len] = '\0';
		str = ft_strjoin(str, temp);
	}
	free (temp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*str1;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read(fd, str);
	if (str == 0)
		return (0);
	str1 = ft_firststr(str);
	str = ft_nextstr(str);
	return (str1);
}
