/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 15:53:37 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/09/10 15:53:41 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_coordinates(char *str)
{
	size_t	i;
	size_t	minus;

	i = 0;
	minus = 0;
	while (str[i])
	{
		if (str[i] == '-' && i == 0)
		{
			minus++;
			i++;
		}
		else if ((str[i] == '-' && i > 0) || minus > 1)
			error();
		if (ft_isdigit(str[i]) == 1)
			i++;
		else
			error();
	}
}

void	final_validation(t_li *li)
{
	startend(li);
	if (li->connect == 0)
		error();
}

void	startend(t_li *li)
{
	t_room *current;
	size_t i;

	i = 0;
	current = li->room;
	if (current == NULL)
		error();
	while (current != NULL && li->start_n != NULL && li->end_n != NULL)
	{
		if (ft_strcmp(current->name, li->start_n) == 0)
		{
			i++;
			current->start = 1;
		}
		else if (ft_strcmp(current->name, li->end_n) == 0)
		{
			i++;
			current->end = 1;
		}
		current = current->next;
	}
	if (i != 2)
		error();
}

int		check_name(t_room *head)
{
	t_room *check_room;

	if (head->next != NULL)
		check_room = head->next;
	else
		return (0);
	if (check_room->x_cor > INT_MAX || check_room->y_cor > INT_MAX)
		error();
	while (check_room != NULL)
	{
		if (ft_strcmp(head->name, check_room->name) == 0 || (head->x_cor == \
		check_room->x_cor && head->y_cor == check_room->y_cor))
			error();
		check_room = check_room->next;
	}
	return (0);
}

int		check_dash(char *str, t_room *head)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (str[i] != '-' && str[i])
		i++;
	if (str[i] == '-')
	{
		tmp = ft_strsub(str, 0, i);
		if (check_room(tmp, head) == 1)
		{
			ft_strdel(&tmp);
			return (1);
		}
		ft_strdel(&tmp);
	}
	return (0);
}
