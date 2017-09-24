/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 18:39:01 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/09/10 18:39:15 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	addtopath(t_room *current, t_li *li)
{
	t_path	*newnode;

	if (!(newnode = (t_path*)malloc(sizeof(t_path))))
		error();
	newnode->ants = 0;
	newnode->name = current->name;
	newnode->maxant = li->ants;
	newnode->next = li->path;
	newnode->end = current->end;
	li->path = newnode;
}

void	printants(t_path *head)
{
	t_path	*current;
	int		i;
	size_t	space;

	current = head->next;
	i = 0;
	space = 0;
	while (i++ < current->maxant + 1)
	{
		while (current != NULL)
		{
			if (current->ants == i && current->maxant + 1 > current->ants)
			{
				if (space > 0)
					ft_printf(" ");
				ft_printf("L%d-%s", current->ants, current->name);
				space++;
			}
			current = current->next;
		}
		current = head->next;
	}
	ft_printf("\n");
}

void	ants(t_li *li)
{
	t_path *current;

	print_input(li->output);
	current = li->path;
	while ((current->end != 1 || current->ants != current->maxant))
	{
		current = li->path->next;
		while (current->ants != current->maxant || current->end != 1)
		{
			if (current->ants < current->maxant + 1 && current->ants != 0)
				current->ants++;
			if (current->ants < current->maxant + 1 && current->ants == 0)
			{
				current->ants++;
				break ;
			}
			if (current->next == NULL)
				break ;
			current = current->next;
		}
		printants(li->path);
	}
}
