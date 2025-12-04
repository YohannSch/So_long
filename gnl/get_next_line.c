/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheupl <yscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:56:04 by yscheupl          #+#    #+#             */
/*   Updated: 2025/09/12 23:34:27 by yscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(char *str, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*fill_the_line(char *temp, char *newline_pos, char *buffer)
{
	int		len;
	char	*res;
	int		i;

	i = 0;
	len = 0;
	if (!temp)
		return (NULL);
	while (temp[len] && temp[len] != '\n')
		len++;
	if (temp[len] == '\n')
		res = ft_substr(temp, 0, len + 1);
	else
		res = ft_substr(temp, 0, len);
	newline_pos++;
	while (*newline_pos)
		buffer[i++] = *newline_pos++;
	buffer[i] = '\0';
	free(temp);
	return (res);
}

char	*getting_the_line(int fd, char *buffer, char *temp)
{
	int		flag;
	char	*res;
	char	*newline_pos;

	flag = 1;
	newline_pos = ft_strchr(temp, '\n');
	while (flag > 0 && !newline_pos)
	{
		flag = read(fd, buffer, BUFFER_SIZE);
		if (flag == -1)
			return (free(temp), NULL);
		buffer[flag] = '\0';
		temp = ft_strjoin(temp, buffer);
		newline_pos = ft_strchr(temp, '\n');
	}
	if (newline_pos)
		return (fill_the_line(temp, newline_pos, buffer));
	else if (*temp)
	{
		res = ft_strdup(temp);
		ft_bzero(buffer, BUFFER_SIZE);
		return (free(temp), res);
	}
	return (free(temp), NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*temp;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_strdup(buffer);
	ft_bzero(buffer, BUFFER_SIZE);
	if (!temp)
		return (NULL);
	res = getting_the_line(fd, buffer, temp);
	return (res);
}
