/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:12:40 by lsampiet          #+#    #+#             */
/*   Updated: 2023/12/05 20:06:05 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("/nfs/homes/lsampiet/Documents/example.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("call_01->%s", line);
	line = get_next_line(fd);
	printf("call_02->%s", line);
	line = get_next_line(fd);
	printf("call_03git add->%s", line);
	close(fd);
	return (0);
}
