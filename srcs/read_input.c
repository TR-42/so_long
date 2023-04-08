/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 23:22:00 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/09 00:45:52 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - errno
#include <errno.h>

// - open
#include <fcntl.h>

// - perror
#include <stdio.h>

// - free
#include <stdlib.h>

// - read
#include <unistd.h>

#include "gnl/get_next_line.h"
#include "read_input.h"

static t_vect	_perror_return(const char *str, errno_t err)
{
	if (err != 0)
		errno = err;
	perror(str);
	return ((t_vect){});
}

t_vect	read_from_fname(const char *fname)
{
	int		fd;
	t_vect	vect;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (_perror_return("read_from_fname (open file)", 0));
	vect = read_from_fd(fd);
	close(fd);
	return (vect);
}

t_vect	read_from_fd(int fd)
{
	t_vect		vect;
	t_gnl_state	gnl_state;
	char		*tmp;

	gnl_state = gen_gnl_state(fd, 256);
	if (gnl_state.buf == NULL)
		return (_perror_return("read_from_fd (gen_gnl_state)", 0));
	vect = vect_init(16, sizeof(char *));
	if (vect.p == NULL)
		return (_perror_return("read_from_fd (vect_init)", 0));
	while (vect.p != NULL)
	{
		tmp = get_next_line(&gnl_state);
		if (tmp == NULL)
			break ;
		if (!vect_push_back(&vect, &tmp, NULL))
			vect_dispose_each(&vect, free);
	}
	if (vect.p == NULL)
		perror("read_from_fd (vect_push_back)");
	dispose_gnl_state(&gnl_state);
	return (vect);
}
