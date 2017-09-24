/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:14:18 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/02 13:25:45 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long i;
	unsigned char *u;

	u = b;
	i = -1;
	while (i++ != len - 1)
		u[i] = (unsigned char)c;
	return (b);
}
