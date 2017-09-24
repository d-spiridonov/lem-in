/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 21:46:12 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/11 21:46:14 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t i;

	i = ft_strlen((char*)little);
	if (i < 1)
		return ((char*)big);
	while (*big)
	{
		if (ft_strncmp(big, little, i) == 0)
			return ((char*)big);
		big++;
	}
	return (NULL);
}
