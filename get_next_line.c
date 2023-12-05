/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:03:51 by lsampiet          #+#    #+#             */
/*   Updated: 2023/12/05 18:38:45 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	str_len = 0;
	if (NULL == list)
		return (NULL);
	str_len = ft_line_len(list);
	next_str = malloc(str_len + 1);
	if (next_str == NULL)
		return (NULL);
	ft_strcpy(list, next_str);
	return (next_str);
}

void	ft_tideup_list(t_list **list)
{
	t_list	*last_node;
	t_list	*new_node;
	int		i;
	int		n;
	char	*buffer;

	i = 0;
	n = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	new_node = malloc(sizeof(t_list));
	if (buffer == NULL || new_node == NULL)
		return ;
	last_node = ft_find_last_node(*list);
	while (last_node->str_buffer[i] != '\0' \
		&& last_node->str_buffer[i] != '\n')
		i++;
	while (last_node->str_buffer[i] != '\0' \
		&& last_node->str_buffer[i++] != '\0')
		buffer[n++] = last_node->str_buffer[i];
	buffer[n] = '\0';
	new_node->str_buffer = buffer;
	new_node->next = NULL;
	ft_dealloc(*list, new_node, buffer);
}

void	ft_add_new_str(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buffer = buffer;
	new_node->next = NULL;
}

void	ft_create_list(t_list **list, int fd)
{
	int		chars_read;
	char	*buffer;

	while (!ft_find_newline(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return ;
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (!chars_read)
		{
			free(buffer);
			return ;
		}
		buffer[chars_read] = '\0';
		ft_add_new_str(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, &next_line, 0) < 0)
	{
		ft_dealloc(&list[fd], NULL, NULL);
		return (NULL);
	}	
	ft_create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = ft_get_line(list);
	ft_tideup_list(&list);
	return (next_line);
}
