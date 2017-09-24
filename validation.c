/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 14:57:42 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/07/31 15:03:40 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	validate_ants(char *str, t_li *li)
{
	size_t i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (i > ft_strlen(str) || li->start == 1 || li->end == 1)
		error();
	i = 0;
	while (str[i])
		(ft_isdigit(str[i]) == 1) ? i++ : error();
	(ft_atoi(str) > 0) ? li->ants = ft_atoi(str) : error();
	store_str(str, &li->output);
}

void	roomname(char *str, size_t size, t_li *li)
{
	t_room	*new_node;
	size_t	i;

	i = 0;
	while ((size_t)str[i] < size)
		if (ft_isalnum(str[i++]) == 0)
			error();
	if (!(new_node = (t_room *)malloc(sizeof(t_room))))
		error();
	new_node->name = ft_strsub(str, 0, size);
	new_node->next = li->room;
	new_node->room_link = NULL;
	new_node->index = (new_node->next == NULL) ? 1 : new_node->next->index + 1;
	initialize_room(&new_node);
	li->room = new_node;
	if (li->start == 1)
	{
		li->start_n = ft_strsub(str, 0, size);
		li->start = -1;
	}
	if (li->end == 1)
	{
		li->end_n = ft_strsub(str, 0, size);
		li->end = -1;
	}
}

void	store_room(char *str, t_li *lem_in)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	while (ft_isprint(str[i]) && str[i] != ' ')
		i++;
	roomname(str, (size_t)i++, lem_in);
	j = i;
	while (str[i] != ' ' && str[i])
		i++;
	tmp = ft_strsub(str, j, i - j);
	check_coordinates(tmp);
	lem_in->room->x_cor = ft_atoi(tmp);
	(str[i] == ' ') ? i++ : error();
	j = i;
	while (str[i])
		i++;
	ft_strdel(&tmp);
	tmp = ft_strsub(str, j, i - j);
	check_coordinates(tmp);
	lem_in->room->y_cor = ft_atoi(tmp);
	ft_strdel(&tmp);
	check_name(lem_in->room);
	store_str(str, &lem_in->output);
}

void	validate_string(char *str, t_li *li)
{
	if (str[0] == 0)
		error();
	if (ft_isdigit(str[0]) == 1 && li->ants == -1)
		validate_ants(str, li);
	else if (ft_strcmp(str, "##start") == 0 && li->start == 0)
	{
		store_str(str, &li->output);
		li->start = 1;
	}
	else if (ft_strcmp(str, "##end") == 0 && li->end == 0)
	{
		store_str(str, &li->output);
		li->end = 1;
	}
	else if (str[0] == '#' && (ft_strcmp(str, "##end") != 0 && \
		ft_strcmp(str, "##start") != 0))
		store_str(str, &li->output);
	else if (check_dash(str, li->room) == 0 && li->connect == 0 && li->ants > 0)
		(str[0] != 'L' && str[0] != '-') ? store_room(str, li) : error();
	else
		validate_connection(str, li);
}
