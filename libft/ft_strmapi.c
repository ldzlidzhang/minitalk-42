/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidzhang <lidzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:07:49 by lidanzhang        #+#    #+#             */
/*   Updated: 2022/11/10 14:42:11 by lidzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	dest = ft_strdup(s);
	if (!s || !f || !dest)
		return (0);
	i = 0;
	while (dest[i])
	{
		dest[i] = f(i, dest[i]);
		i++;
	}
	return (dest);
}
