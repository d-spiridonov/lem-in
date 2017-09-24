/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 08:16:05 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/03/18 18:41:49 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	backslashn(char *str, int bcount, int bnlen)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	if (str)
	{
		while (str[i] && bcount == 1)
			if (str[i++] == '\n')
				count++;
		while (str[i] != '\n' && str[i++] != '\0' && bnlen == 1)
			count++;
	}
	return (count);
}

char	*ft_trim(char *str)
{
	char	*tmp;
	int		i;
	int		a;

	i = 0;
	a = 0;
	tmp = ft_strnew(ft_strlen(str));
	while (str[i] != '\n')
		i++;
	i++;
	while (str[i])
		tmp[a++] = str[i++];
	ft_strdel(&str);
	tmp[a] = '\0';
	return (tmp);
}

int		joinchar(char **tmp, int fd, char **sub)
{
	char	*subt;
	char	*buf;
	ssize_t ret;

	buf = ft_strnew(BUFF_SIZE);
	ret = read(fd, buf, BUFF_SIZE);
	if (ret == -1)
		return (-1);
	while (backslashn(buf, 1, 0) == 0 && ret > 0)
	{
		subt = *tmp;
		*tmp = ft_strjoin(subt, buf);
		ft_strdel(&subt);
		ft_strclr(buf);
		ret = read(fd, buf, BUFF_SIZE);
	}
	subt = *tmp;
	*tmp = ft_strjoin(subt, buf);
	ft_strdel(&subt);
	ft_strdel(&buf);
	subt = ft_strsub(*tmp, 0, backslashn(*tmp, 0, 1));
	if (subt == NULL)
		subt = ft_strnew(0);
	*sub = subt;
	return (0);
}

t_gnl	*multfd(t_gnl **head, int fd)
{
	t_gnl	*current;

	current = *head;
	while (current != NULL)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	current = (t_gnl *)malloc(sizeof(t_gnl));
	current->tmp = ft_strnew(0);
	current->fd = fd;
	current->next = *head;
	*head = current;
	return (current);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl;
	char			*sub;
	t_gnl			*tmp;

	tmp = multfd(&gnl, fd);
	if (joinchar(&tmp->tmp, fd, &sub) != 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (*sub == '\0' && backslashn(tmp->tmp, 1, 0) == 0)
	{
		*line = sub;
		return (0);
	}
	if (backslashn(tmp->tmp, 1, 0) > 0)
	{
		*line = sub;
		tmp->tmp = ft_trim(tmp->tmp);
		return (1);
	}
	*line = sub;
	ft_strclr(tmp->tmp);
	return (1);
}
