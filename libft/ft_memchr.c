/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:33:54 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/06 15:33:56 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*stmp;
	unsigned char	ctmp;
	size_t			i;

	stmp = (unsigned char*)s;
	ctmp = (unsigned char)c;
	i = 0;
	while (i != n)
	{
		if (*stmp == ctmp)
			return ((void*)stmp);
		stmp++;
		i++;
	}
	return (NULL);
}
