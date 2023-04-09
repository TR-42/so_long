/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endwith.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:15:44 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/09 11:19:16 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENDWITH_H
# define FT_ENDWITH_H

// - bool
# include <stdbool.h>

// - size_t
# include <stddef.h>

bool	ft_endwith(const void *target, size_t target_bytes,
			const void *sample, size_t sample_bytes);

bool	ft_endwith_str(const char *target, const char *sample);

#endif