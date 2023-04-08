/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 23:25:39 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/08 23:33:34 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_INPUT_H
# define READ_INPUT_H

# include <stdbool.h>

# include "ft_vect/ft_vect.h"

t_vect	read_from_fname(const char *fname);
t_vect	read_from_fd(int fd);

#endif
