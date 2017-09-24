/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:05:00 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/13 20:05:41 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dst;
	size_t	i;

	if (s != NULL && *f != NULL)
	{
		i = 0;
		if (!(dst = (char*)malloc(sizeof(*dst) * (ft_strlen((char*)s) + 1))))
			return (NULL);
		while (*s)
		{
			dst[i] = f(i, (char)*s);
			i++;
			s++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
