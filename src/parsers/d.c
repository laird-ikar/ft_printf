/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:48:18 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/02 09:40:21 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/_ft_printf.h"

t_buff	*d(va_list lst, t_flag flag)
{
	t_buff	*ret;
	int		data;

	ret = ft_calloc(1, sizeof (t_buff));
	data = va_arg(lst, int);
	ret->data = ft_itoa(data);
	ret->len = ft_strlen(ret->data);
	apply_width(ret, flag.min_width, flag.padding_type);
	return (ret);
}
