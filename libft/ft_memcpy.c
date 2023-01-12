/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidzhang <lidzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:52:02 by lidanzhang        #+#    #+#             */
/*   Updated: 2022/11/10 14:38:31 by lidzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned const char	*pt_src;
	unsigned char		*pt_dest;
	size_t				i;

	pt_dest = (unsigned char *)dest;
	pt_src = (unsigned char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		*((char *)dest + i) = *((char *)pt_src + i);
		i++;
	}
	return (pt_dest);
}
