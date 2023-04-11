/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 05:26:35 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/11 19:26:15 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_INPUT_H
# define VALIDATE_INPUT_H

# include <stdbool.h>

# include "so_long.h"

// checks...
// - col count
// - invalid chars
bool	is_valid_map_style(const t_so_long *d);

// checks...
// - is it closed/surrounded with wall?
// - start/exit/collectable count
bool	is_valid_map_data(t_so_long *d);

// checks...
// - is it solvable?
bool	is_map_solvable(t_so_long *d);

#endif
