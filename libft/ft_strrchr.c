/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidzhang <lidzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:22:46 by lidzhang          #+#    #+#             */
/*   Updated: 2022/11/10 14:42:48 by lidzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*dest;
	int		i;

	dest = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			dest = &((char *)s)[i];
		i++;
	}
	if (c == '\0')
		dest = &((char *)s)[i];
	return (dest);
}
