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

	if (list == NULL)
		return (0);
	while (list)
		len++;
	return (len);
}

void	ft_is_newline(t_list **list)
{
	while (*list != '\n')
		list++;
}

ahahah