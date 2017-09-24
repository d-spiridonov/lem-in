/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 15:49:04 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/18 15:49:12 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwords(char const *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	check;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
			check = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i > check)
			count++;
	}
	return (count);
}
