/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 18:34:30 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/11 18:35:34 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*stmp1;
	unsigned char	*stmp2;
	int				count;

	stmp1 = (unsigned char*)s1;
	stmp2 = (unsigned char*)s2;
	count = 0;
	while (*stmp1 != '\0' || *stmp2 != '\0')
	{
		if (*stmp1 < *stmp2 || *stmp1 > *stmp2)
		{
			count = *stmp1 - *stmp2;
			return (count);
		}
		stmp1++;
		stmp2++;
	}
	return (count);
}
