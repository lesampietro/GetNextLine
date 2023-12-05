/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:04:26 by lsampiet          #+#    #+#             */
/*   Updated: 2023/11/30 21:40:46 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_line_len(t_list *list)
{
	int	len;
	int	i;

	len = 0;
	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buffer[i])
		{
			if (list->str_buffer[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

void	*ft_strcpy(t_list *list, char *nxt_str)
{
	int	i;
	int	n;

	n = 0;
	if (list == NULL)
		return (NULL);
	while (list)
	{
		i = 0;
		while (list->str_buffer[i])
		{
			if (list->str_buffer[i] == '\n')
			{
				nxt_str[n++] = '\n';
				nxt_str[n] = '\0';
				return (nxt_str);
			}
			nxt_str[n++] = list->str_buffer[i++];
		}
		list = list->next;
	}
	nxt_str[n] = '\0';
}

void	ft_is_newline(t_list **list)
{
	while (*list != '\n')
		list++;
}