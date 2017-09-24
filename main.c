/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 21:24:15 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/09/12 20:06:35 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	char	*str;
	t_li	lem_in;

	initialize(&lem_in);
	while (get_next_line(0, &str) == 1)
	{
		validate_string(str, &lem_in);
		ft_strdel(&str);
	}
	final_validation(&lem_in);
	bfs_algorithm(&lem_in);
	return (0);
}
