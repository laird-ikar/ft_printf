/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:06:19 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/01 08:32:40 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/_ft_printf.h"

/*\*/
static t_parse	*g_parser[] = {
	['u'] = *u,
	['x'] = *x,
	['X'] = *great_x,
	['i'] = *i,
	['p'] = *p,
	['d'] = *d,
	['%'] = *percent,
	['s'] = *s,
	['c'] = *c
};
/**/

t_buff	expend_arg(va_list args, t_flag flag)
{
	t_buff	ret;

	ret = g_parser[flag.conv_type](args, flag);
	return (ret);
}
