/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidzhang <lidzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:20:22 by lidanzhang        #+#    #+#             */
/*   Updated: 2022/11/10 14:40:14 by lidzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	word_num;
	int		mark;

	word_num = 0;
	mark = 1;
	while (*s)
	{
		if (*s != c && mark)
		{
			mark = 0;
			word_num++;
		}
		else if (*s == c)
			mark = 1;
		s++;
	}
	return (word_num);
}

static void	split_words(char **dest, char const *s, char c, size_t n)
{
	char	*res_s;

	while (*s && *s == c)
		s++;
	while (n--)
	{
		res_s = ft_strchr(s, c);
		if (res_s != NULL)
		{
			*dest = ft_substr(s, 0, res_s - s);
			while (*res_s && *res_s == c)
				res_s++;
			s = res_s;
		}
		else
			*dest = ft_substr(s, 0, ft_strlen(s) + 1);
		dest++;
	}
	*dest = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	n;
	char	**dest;

	if (s == NULL)
		return (NULL);
	n = count_words(s, c);
	dest = malloc(sizeof(char **) * (n + 1));
	if (dest == NULL)
	{
		free(dest);
		return (NULL);
	}
	split_words(dest, s, c, n);
	return (dest);
}
