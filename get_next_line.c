/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:03:51 by lsampiet          #+#    #+#             */
/*   Updated: 2023/11/30 21:29:38 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(t_list *list)
{
	int		str_len;
	char	*next_line;

	if (NULL == list)
		return (NULL);
	str_len = ft_line_len(list);
	next_line = malloc((str_len + 1) * sizeof(char));
	if (next_line == NULL)
		return (NULL);
	ft_linecpy(list, next_line);
	return (next_line);
}

// void	ft_clean_input(t_list **list)
// {
	
// }

void	ft_add_new_str(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	if (NULL == *list)
		return (NULL);
	if (last_node == NULL)
		*list = new_node;
	new_node->str_buffer = buffer;
	new_node->next = NULL;
}

void	ft_create_list(t_list **list, int fd)
{
	int		chars_read;
	char	*buffer;

	while (!ft_is_newline(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return (NULL);
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (!chars_read)
		{
			free(buffer);
			return (NULL);
		}
		buffer[chars_read] = '\0';
		ft_add_new_str(list, buffer);
	}
}

char	*ft_get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	ft_create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = ft_get_line(list);
	ft_clean_input(&list);
	return (next_line);
}
