/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayderha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:53:53 by rayderha          #+#    #+#             */
/*   Updated: 2024/03/13 14:14:24 by rayderha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42 

# endif

typedef struct s_list
{
	char			*current;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	read_buff_pile(t_list **pile, int fd);
void	get_line(t_list *pile, char *line);
void	clean_list(t_list **pile);
void	newnode(t_list **pile, char *current, int len);
void	freealllist(t_list *pile);
int		newline(t_list *pile);
int		size_line(t_list *pile);
t_list	*ft_lst_get_last(t_list *pile);

#endif
