/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:50:37 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/01 16:38:56 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/_ft_printf.h"

t_buff	*x(va_list lst, t_flag flag)
{
	t_buff			*ret;
	unsigned int	data;

	ret = ft_calloc(1, sizeof (t_buff));
	data = va_arg(lst, unsigned);
	ret->data = ft_utoa_base(data, "0123456789abcdef");
	ret->len = ft_strlen(ret->data);
	return (ret);
	(void) flag;
}
