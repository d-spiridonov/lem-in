/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 19:41:02 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/25 19:41:13 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *prev;
	t_list *new;

	if (lst == NULL)
		return (NULL);
	new = f(lst);
	prev = new;
	while (lst->next)
	{
		lst = lst->next;
		prev->next = f(lst);
		prev = prev->next;
	}
	return (new);
}
