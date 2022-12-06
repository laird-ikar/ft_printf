/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:50:37 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/06 09:39:53 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/_ft_printf.h"

t_buff	*x(va_list lst, t_flag *flag)
{
	t_buff			*ret;
	char			*tmp;
	unsigned int	data;

	ret = ft_calloc(1, sizeof (t_buff));
	data = va_arg(lst, unsigned);
	ret->data = ft_utoa_base(data, "0123456789abcdef");
	if (data && flag->do_alt_form)
	{
		tmp = ft_strjoin("0x", ret->data);
		free(ret->data);
		ret->data = tmp;
	}
	ret->len = ft_strlen(ret->data);
	update_zero_flag(flag, ret);
	return (ret);
}
