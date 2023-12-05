/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:48:49 by lsampiet          #+#    #+#             */
/*   Updated: 2023/12/05 18:12:09 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*str_buffer;
	struct s_list	*next;
}					t_list;

int		ft_line_len(t_list *list);
int		ft_find_newline(t_list *list);
char	*get_next_line(int fd);
char	*ft_get_line(t_list *list);
void	ft_tideup_list(t_list **list);
void	*ft_strcpy(t_list *list, char *nxt_str);
void	ft_add_new_str(t_list **list, char *buffer);
void	ft_create_list(t_list **list, int fd);
void	ft_dealloc(t_list *list, t_list *clean_node, char *buffer);
t_list	*ft_find_last_node(t_list *list);

#endif