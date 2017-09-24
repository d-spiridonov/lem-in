/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 19:40:18 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/12 19:40:20 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *buf;

	if (!(buf = (char*)malloc(sizeof(*buf) * (size + 1))))
		return (NULL);
	ft_bzero(buf, size + 1);
	return (buf);
}
