/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayderha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:53:41 by rayderha          #+#    #+#             */
/*   Updated: 2024/03/13 14:05:03 by rayderha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <string.h>

void	newnode(t_list **pile, char *current, int len)
{
	t_list	*nouveau;
	t_list	*temp;
	int		i;

	i = 0;
	nouveau = malloc(sizeof(t_list));
	if (!nouveau)
		return ;
	nouveau->next = NULL;
	nouveau->current = malloc(sizeof(char) * len + 1);
	if (nouveau->current == NULL)
		return ;
	while (current[i])
	{
		nouveau->current[i] = current[i];
		i++;
	}
	nouveau->current[i] = '\0';
	if (*pile == NULL)
	{
		*pile = nouveau;
		return ;
	}
	temp = ft_lst_get_last(*pile);
	temp->next = nouveau;
}

void	read_buff_pile(t_list **pile, int fd)
{
	char	*line;
	int		i;

	i = 1;
	while (!newline(*pile) && i != 0)
	{
		line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (line == NULL)
			return ;
		i = (int)read(fd, line, BUFFER_SIZE);
		if ((*pile == NULL && i == 0) || i == -1)
		{
			free(line);
			return ;
		}
		line[i] = '\0';
		newnode(pile, line, i);
		free(line);
	}
}

void	get_line(t_list *pile, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (pile)
	{
		while (pile->current[i])
		{
			if (pile->current[i] == '\n')
			{
				line[j] = pile->current[i];
				line[j + 1] = '\0';
				return ;
			}
			line[j] = pile->current[i];
			j++;
			i++;
		}
		i = 0;
		pile = pile->next;
	}
	line[j] = '\0';
}

void	clean_list(t_list **pile)
{
	t_list	*clean;
	t_list	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	clean = malloc(sizeof(t_list));
	if (clean == NULL || *pile == NULL)
		return ;
	clean->next = NULL;
	temp = ft_lst_get_last(*pile);
	while (temp->current[i] && temp->current[i] != '\n')
		i++;
	if (temp->current[i] == '\n')
		i++;
	while (temp->current[j])
		j++;
	clean->current = malloc(sizeof(char) * (j - i) + 1);
	j = 0;
	while (temp->current[i])
		clean->current[j++] = temp->current[i++];
	clean->current[j] = '\0';
	freealllist(*pile);
	*pile = clean;
}

char	*get_next_line(int fd)
{
	static t_list	*pile = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, (void *)(0), 0) < 0)
		return (NULL);
	read_buff_pile(&pile, fd);
	if (pile == NULL )
		return (NULL);
	line = malloc(sizeof(char) * size_line(pile) + 1);
	get_line(pile, line);
	clean_list(&pile);
	if (line[0] == '\0')
	{
		freealllist(pile);
		pile = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
