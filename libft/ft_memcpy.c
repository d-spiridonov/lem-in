/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:00:25 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/02 15:00:26 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*adst;
	unsigned char	*asrc;

	adst = (unsigned char*)dst;
	asrc = (unsigned char*)src;
	i = 0;
	while (i != n)
	{
		adst[i] = asrc[i];
		i++;
	}
	return (dst);
}
