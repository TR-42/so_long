/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endwith.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:19:38 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/09 11:27:10 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string/ft_string.h"
#include "ft_endwith.h"

bool	ft_endwith(const void *target, size_t target_bytes,
			const void *sample, size_t sample_bytes)
{
	unsigned char	*_target;
	unsigned char	*_sample;

	if (target == NULL || sample == NULL || target_bytes < sample_bytes)
		return (false);
	_target = (unsigned char *)target + target_bytes;
	_sample = (unsigned char *)sample + sample_bytes;
	while (0 < sample_bytes)
	{
		_target--;
		_sample--;
		sample_bytes--;
		if (*_target != *_sample)
			return (false);
	}
	return (true);
}

bool	ft_endwith_str(const char *target, const char *sample)
{
	if (target == NULL || sample == NULL)
		return (false);
	return (ft_endwith(target, sizeof(char) * ft_strlen(target),
			sample, sizeof(char) * ft_strlen(sample)));
}
