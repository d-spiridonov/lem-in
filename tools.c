/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 17:49:31 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/09/10 17:49:33 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	initialize_room(t_room **node)
{
	t_room *tmp;

	tmp = *node;
	tmp->x_cor = -1;
	tmp->y_cor = -1;
	tmp->start = 0;
	tmp->end = 0;
	tmp->visited = 0;
	tmp->n_wave = -1;
}

void	initialize(t_li *li)
{
	li->start = 0;
	li->end = 0;
	li->ants = -1;
	li->connect = 0;
	li->start_n = NULL;
	li->room = NULL;
}

void	print_input(t_str *head)
{
	t_str *current;

	current = head;
	while (current != NULL)
	{
		ft_printf("%s\n", current->str);
		current = current->next;
	}
	ft_printf("\n");
}

void	error(void)
{
	ft_printf("ERROR\n");
	exit(0);
}

void	store_str(char *str, t_str **head)
{
	t_str	*tmp;
	t_str	*new_node;

	tmp = *head;
	if (!(new_node = (t_str*)malloc(sizeof(t_str))))
		error();
	new_node->str = ft_strdup(str);
	new_node->next = NULL;
	if (tmp == NULL)
		*head = new_node;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}
