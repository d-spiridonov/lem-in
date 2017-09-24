/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 18:43:24 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/09/10 18:43:27 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# include "./libft/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

/*
** t_str - list to store strings from gnl:
** str - string read from gnl
*/

typedef struct	s_str
{
	char			*str;
	struct s_str	*next;
}				t_str;

/*
** t_room - list to storeroom name and coordinates:
** name - name of the room
** x_cor - coordinate
** y_cor - coordinate
** index - room index for queue
** visited - was visited
** p - processed. This vertice was processed
** n_wave - bfs_wave number
*/

typedef struct	s_room
{
	char			*name;
	long			x_cor;
	long			y_cor;
	int				start;
	int				end;
	int				index;
	int				visited;
	int				n_wave;
	struct s_link	*room_link;
	struct s_room	*next;
}				t_room;

/*
** t_link - links to rooms
** room - link to room
** lnext - if the room has more links
*/

typedef struct	s_link
{
	t_room			*room;
	struct s_link	*lnext;
}				t_link;

/*
** index - room index;
** *name - name of the room;
** ants - if ants is currently in this room
*/

typedef struct	s_path
{
	char			*name;
	int				ants;
	int				maxant;
	struct s_path	*next;
	int				end;
}				t_path;

/*
** t_li - main list to work with
** ants - number of ants
** start - if #start string was read - to write lnext line into t_room
** if we have started validating connections
** end if #end string was read-to write lnext line into t_room and indicate end
** *start_n - name of the start room
** *end_n - name of the end room
** *output - list with the output
** room - list with rooms data
** path - struct with path data
*/

typedef struct	s_li
{
	int		ants;
	int		start;
	int		end;
	int		connect;
	char	*start_n;
	char	*end_n;
	t_str	*output;
	t_room	*room;
	t_path	*path;
}				t_li;

/*
** void	roomname - function to write new roomname into a list;
** void	validate - main validation function
** void validate_room - function to validate rooms
** error - func to display an error and exit
** print - func to print_input the input from a linked list
** initialize - func to initialize variables and lists
** startend - func to show ERROR and exit if there are no start and exit rooms \
** input
** final_validation - func for the final validation;
** check_name - func to check for the room with the same name + chck on max int
** checkEmptyString - func to check the empty string
** check_dash - func to check if dash is present in the string
** validate_connection - func to validate_string connections
** func to check if the room from the connection is present in the string
** checkcorr - func to check if coordinates are valid
*/

void			roomname(char *str, size_t size, t_li *li);
void			validate_string(char *str, t_li *li);
void			store_str(char *str, t_str **head);
void			validate_ants(char *str, t_li *li);
void			error(void);
void			print_input(t_str *head);
void			initialize(t_li *li);
void			startend(t_li *li);
void			final_validation(t_li *li);
int				check_name(t_room *head);
int				check_dash(char *str, t_room *head);
void			validate_connection(char *str, t_li *li);
int				check_room(char *str, t_room *head);
void			check_coordinates(char *str);
int				store_link(t_li *li, char *room1, char *room2);
int				addlnk(char *r2, t_link **r1lnk, t_room *room2);
void			bfs_algorithm(t_li *li);
void			addtopath(t_room *current, t_li *li);
void			ants(t_li *li);
void			initialize_room(t_room **node);

#endif
