/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 19:08:04 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/11 19:08:09 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				count;
	size_t			i;
	unsigned char	*stmp1;
	unsigned char	*stmp2;

	stmp1 = (unsigned char*)s1;
	stmp2 = (unsigned char*)s2;
	count = 0;
	i = 0;
	while (i < n && (*stmp1 || *stmp2))
	{
		if (*stmp1 < *stmp2 || *stmp1 > *stmp2)
		{
			count = *stmp1 - *stmp2;
			return (count);
		}
		stmp1++;
		stmp2++;
		i++;
	}
	return (count);
}
