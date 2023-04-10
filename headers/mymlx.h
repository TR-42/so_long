/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:21:03 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/10 20:35:49 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYMLX_H
# define MYMLX_H

# include <stdbool.h>

# include "so_long.h"

t_img	mymlx_img_open(const t_so_long *d, const char *fname);
bool	mymlx_img_put(const t_so_long *d, const t_img *info, int x, int y);
bool	mymlx_img_destory(const t_so_long *d, t_img *info);

#endif
