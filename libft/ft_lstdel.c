/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 20:18:05 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/23 20:19:22 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	while (*alst != NULL)
	{
		tmp = *alst;
		*alst = (*alst)->next;
		del(tmp->content, sizeof(tmp->content_size));
		free(tmp);
	}
	*alst = NULL;
}
