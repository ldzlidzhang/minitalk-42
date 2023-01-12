/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:42:37 by lidzhang          #+#    #+#             */
/*   Updated: 2022/11/16 16:54:23 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *rest_str, char *buff)
{
	unsigned int	i;
	unsigned int	j;
	char			*dest;

	if (!rest_str)
	{
		rest_str = (char *)malloc(1 * sizeof(char));
		rest_str[0] = '\0';
	}
	if (!rest_str || !buff)
		return (NULL);
	i = ft_strlen(rest_str);
	j = ft_strlen(buff);
	dest = malloc(sizeof(char) * (i + j + 1));
	i = -1;
	j = -1;
	while (rest_str[++i])
		dest[i] = rest_str[i];
	while (buff[++j])
		dest[i++] = buff[j];
	dest[i] = '\0';
	free(rest_str);
	return (dest);
}

char	*extract_line(char *rest_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!rest_str[i])
		return (NULL);
	while (rest_str[i] && rest_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (rest_str[i] && rest_str[i] != '\n')
	{
		str[i] = rest_str[i];
		i++;
	}
	if (rest_str[i] == '\n')
	{
		str[i] = rest_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*extract_rest(char *rest_str)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (rest_str[i] && rest_str[i] != '\n')
		i++;
	if (!rest_str[i])
	{
		free(rest_str);
		return (NULL);
	}
	dest = (char *)malloc(sizeof(char) * (ft_strlen(rest_str) - i + 1));
	if (!dest)
		return (NULL);
	i++;
	j = 0;
	while (rest_str[i])
		dest[j++] = rest_str[i++];
	dest[j] = '\0';
	free(rest_str);
	return (dest);
}
