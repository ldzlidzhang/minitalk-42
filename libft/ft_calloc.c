/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidzhang <lidzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:11:51 by lidanzhang        #+#    #+#             */
/*   Updated: 2022/11/10 14:35:32 by lidzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The C library function void *calloc(size_t nitems, size_t size) allocates 
the requested memory and returns a pointer to it. The difference in 
malloc and calloc is that malloc does not set the memory to zero 
where as calloc sets allocated memory to zero.
*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		len;
	void	*ptr;

	len = count * size;
	if (len % count != 0 || len % size != 0)
		return (NULL);
	ptr = malloc(len);
	if (ptr)
	{
		ft_bzero(ptr, len);
		return (ptr);
	}
	return (NULL);
}
