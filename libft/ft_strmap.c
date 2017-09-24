/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:46:40 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/13 17:46:43 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
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
			dst[i] = f((char)*s);
			i++;
			s++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
