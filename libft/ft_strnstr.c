/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 20:31:55 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/11 20:31:57 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t c;

	c = 0;
	i = ft_strlen((char*)little);
	if (i < 1)
		return ((char*)big);
	while (c < len && *big && (c + i <= len))
	{
		if (ft_strncmp(big, little, i) == 0)
			return ((char*)big);
		big++;
		c++;
	}
	return (NULL);
}
