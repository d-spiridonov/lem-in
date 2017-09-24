/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:00:03 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/11/28 20:00:11 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	i2;

	i = ft_strlen(dst);
	i2 = 0;
	while (i2 < n && src[i2] != '\0')
	{
		dst[i2 + i] = src[i2];
		i2++;
	}
	dst[i2 + i] = '\0';
	return (dst);
}
