/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 15:38:15 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/09/10 15:38:19 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		addlnk(char *r2, t_link **r1lnk, t_room *room2)
{
	t_room	*current_room2;
	t_link	*newnode;

	current_room2 = room2;
	if (!(newnode = (t_link*)malloc(sizeof(t_link))))
		perror("error");
	newnode->lnext = *r1lnk;
	while (current_room2 != NULL)
	{
		if (ft_strcmp(r2, current_room2->name) == 0)
		{
			newnode->room = current_room2;
			break ;
		}
		current_room2 = current_room2->next;
	}
	*r1lnk = newnode;
	return (0);
}

int		store_link(t_li *li, char *room1, char *room2)
{
	t_room	*tmp;

	tmp = li->room;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, room1) == 0)
		{
			addlnk(room2, &tmp->room_link, li->room);
			break ;
		}
		tmp = tmp->next;
	}
	tmp = li->room;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, room2) == 0)
		{
			addlnk(room1, &tmp->room_link, li->room);
			ft_strdel(&room1);
			ft_strdel(&room2);
			return (0);
		}
		tmp = tmp->next;
	}
	return (-1);
}

int		check_room(char *str, t_room *head)
{
	t_room *current;

	current = head;
	while (current != NULL)
	{
		if (ft_strcmp(current->name, str) == 0)
			return (1);
		current = current->next;
	}
	return (0);
}

void	validate_connection(char *str, t_li *li)
{
	size_t	i;
	size_t	i2;
	char	*room1;
	char	*room2;

	i = 0;
	while (str[i] != '-' && str[i])
		i++;
	room1 = ft_strsub(str, 0, i++);
	i2 = i;
	while (str[i2])
		i2++;
	room2 = ft_strsub(str, i, i2);
	if (check_room(room1, li->room) == 0 || check_room(room2, li->room) == 0)
		error();
	store_str(str, &li->output);
	store_link(li, room1, room2);
	li->connect = 1;
}
