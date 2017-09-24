/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:27:14 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/08 11:27:21 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*tsrc;
	size_t	i;
	size_t	i2;

	tsrc = (char *)src;
	i = ft_strlen(dst);
	i2 = 0;
	if (i > size)
		return (size + ft_strlen(tsrc));
	while ((i + i2 + 1) < size)
	{
		dst[i + i2] = tsrc[i2];
		i2++;
	}
	dst[i + i2] = '\0';
	return (i + ft_strlen(tsrc));
}
