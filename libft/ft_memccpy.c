/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:52:53 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/03 12:52:55 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*adst;
	unsigned char	*asrc;
	unsigned char	c2;

	adst = (unsigned char*)dst;
	asrc = (unsigned char*)src;
	i = 0;
	c2 = c;
	while (i != n)
	{
		if (*asrc == c2)
		{
			*adst++ = *asrc++;
			return ((void*)adst);
		}
		*adst = *asrc;
		adst++;
		asrc++;
		i++;
	}
	return (NULL);
}
