/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:28:41 by lsampiet          #+#    #+#             */
/*   Updated: 2023/11/28 17:50:35 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

// size_t	read(int fd, void *buf, size_t count)ç
// {,
// }

int	main(void)
{
	int		fd;
	char	buff[1024];
	char	*path;
	int		chars_read;

	path = "/nfs/homes/lsampiet/Documents/example.txt";
	fd = open(path, O_RDONLY);
	while (chars_read = read(fd, buff, 10))
	{	
		buff[chars_read] = '\0';
		printf("buff-> %s\n", buff);
	}
	printf("olá");
}

// Once we have the file open, we read its contents by calling the 
// read() function and passing the “fd” descriptor that is returned by 
// the open() function as the first argument.We pass the pointer to 
// the “buff” buffer as the second argument where we store the 
// contents to be read.Finally, we pass the size of the buffer which 
// is 1024 bytes in this case.We then use the printf() function to 
// display the contents that are stored in “buff” in the command console.