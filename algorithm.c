/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 16:07:33 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/09/10 16:07:36 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		findhead(t_li *li)
{
	t_room *current;

	current = li->room;
	while (current != NULL)
	{
		if (current->start == 1)
		{
			current->visited = 1;
			current->n_wave = 0;
			return (current->index);
		}
		current = current->next;
	}
	error();
	return (-1);
}

void	findpath(t_li *li, int w)
{
	t_room	*current_room;
	t_link	*current_link;

	current_room = li->room;
	while (current_room->end != 1)
		current_room = current_room->next;
	addtopath(current_room, li);
	while (current_room->start != 1)
	{
		current_link = current_room->room_link;
		while (current_link->room->n_wave != w - 1)
		{
			current_link = current_link->lnext;
			if (current_link == NULL)
				error();
		}
		addtopath(current_link->room, li);
		current_room = current_link->room;
		w--;
	}
	ants(li);
	exit(0);
}

void	wave_process_node(int *q, size_t add_to_q, t_room *tmp, t_room *current)
{
	q[add_to_q] = tmp->index;
	tmp->n_wave = current->n_wave + 1;
	tmp->visited = 1;
}

void	bfs_wave(t_li *li, int *q)
{
	t_room *current;
	t_link *tmp;
	size_t add_to_q;
	size_t pop_from_q;

	add_to_q = 0;
	pop_from_q = 0;
	current = li->room;
	while (current != NULL)
	{
		current = li->room;
		while (q[pop_from_q] != current->index && current->next != NULL)
			current = current->next;
		tmp = current->room_link;
		while (tmp)
		{
			if (tmp->room->visited == 0)
				wave_process_node(q, ++add_to_q, tmp->room, current);
			if (tmp->room->end == 1)
				findpath(li, tmp->room->n_wave);
			tmp = tmp->lnext;
		}
		if (q[++pop_from_q] == 0)
			error();
	}
}

void	bfs_algorithm(t_li *li)
{
	int *q;

	if (!(q = (int*)malloc(sizeof(int) * li->room->index)))
		perror("error");
	q[0] = findhead(li);
	bfs_wave(li, q);
	free(q);
}
