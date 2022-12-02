/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:03:34 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/02 09:38:42 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/_ft_printf.h"

void	apply_width(t_buff *buff, int min_width, int padding_type)
{
	char	*data;

	if ((int) buff->len >= min_width)
		return ;
	data = ft_calloc(min_width, sizeof (char));
	ft_memset(data, ' ', min_width);
	ft_memmove(data, buff->data, buff->len);
	free(buff->data);
	buff->data = data;
	buff->len = min_width;
	(void) padding_type;
}
