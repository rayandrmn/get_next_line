/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayderha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:15:42 by rayderha          #+#    #+#             */
/*   Updated: 2024/03/13 14:03:44 by rayderha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	newline(t_list *pile)
{
	t_list	*temp;
	int		i;
	int		j;

	j = 0;
	temp = pile;
	if (pile == NULL)
		return (0);
	while (temp)
	{
		i = 0;
		while (temp->current[i])
		{
			if (temp->current[i] == '\n')
			{
				j++;
				return (j);
			}
			j++;
			i++;
		}
		temp = temp->next;
	}
	return (0);
}

void	freealllist(t_list *pile)
{
	t_list	*lapile;
	t_list	*temp;

	lapile = pile;
	while (lapile)
	{
		free(lapile->current);
		temp = lapile->next;
		free(lapile);
		lapile = temp;
	}
}

t_list	*ft_lst_get_last(t_list *pile)
{
	t_list	*temp;

	temp = pile;
	while (temp && temp->next)
		temp = temp->next;
	return (temp);
}

int	size_line(t_list *pile)
{
	t_list	*temp;
	int		i;
	int		j;

	temp = pile;
	j = 0;
	while (temp)
	{
		i = 0;
		while (temp->current[i])
		{
			if (temp->current[i] == '\n')
			{
				j++;
				return (j);
			}
			i++;
			j++;
		}
		temp = temp->next;
	}
	return (j);
}
