/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:01:24 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/03 20:01:25 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*adst;
	const unsigned char	*asrc;

	adst = (unsigned char*)dst;
	asrc = (unsigned char*)src;
	if (dst > src)
	{
		while (len--)
		{
			adst[len] = asrc[len];
		}
	}
	else
		ft_memcpy((char *)adst, (char *)asrc, len);
	return (dst);
}
