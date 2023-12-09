/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:12:40 by lsampiet          #+#    #+#             */
/*   Updated: 2023/12/09 17:08:23 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd = open("example.txt", O_RDONLY);
	int		line_count = 0;
	char	*line;
	
	// line = get_next_line(fd);
	// printf("call_01->%s", line);
	// line = get_next_line(fd);
	// printf("call_02->%s", line);
	// line = get_next_line(fd);
	// printf("call_03git add->%s", line);

	while ((line = get_next_line(fd)))
	{
		printf("line %d->%s", line_count++, line);
		free(line);
	}
	printf("line %d->NULL", line_count++);

	close(fd);
	return (0);
}
