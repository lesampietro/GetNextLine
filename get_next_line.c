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
	t_list	*clean_node;
	int		i;
	int		n;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buffer == NULL || clean_node == NULL)
		return (NULL);
	last_node == ft_find_last_node(*list);
	
	i = 0;
	n = 0;
	while (last_node->str_buffer[i] != '\0' \ 
		&& last_node->str_buffer[i] != '\n')
		i++;
		while (last_node->str_buffer[i])
			buffer[j++] = last_node->str_buffer[i++];
		buffer[j] = '\0';
		clean_node->str_buffer = buffer;
		clean_node->next = NULL;
		ft_lstadd_back(list, clean_node);
		return ;
	}
			i++;
		}
		last_node = last_node->next;
	}
}

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
	ft_tideup_list(&list);
	return (next_line);
}
