/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:41:03 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/07 12:41:05 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char *tmp;

	tmp = (char*)malloc(sizeof(*s1) * ft_strlen((char *)s1) + 1);
	if (tmp == NULL)
		return (NULL);
	ft_strcpy(tmp, (char*)s1);
	return (tmp);
}
