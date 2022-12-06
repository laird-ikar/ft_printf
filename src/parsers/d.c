/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:48:18 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/06 09:20:53 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/_ft_printf.h"

t_buff	*d(va_list lst, t_flag *flag)
{
	t_buff	*ret;
	int		data;
	char	*tmp;

	ret = ft_calloc(1, sizeof (t_buff));
	data = va_arg(lst, int);
	ret->data = ft_itoa(data);
	if (data < 0)
	{
		tmp = ft_substr(ret->data, 1, ft_strlen(ret->data) - 1);
		free(ret->data);
		ret->data = tmp;
	}
	ret->len = ft_strlen(ret->data);
	update_flag(flag, data, ret);
	return (ret);
}

void	update_flag(t_flag *flag, int data, t_buff *ret)
{
	flag->sign = ft_sign(data);
	if (!data)
		flag->sign = 1;
	if (data >= 0 && !flag->positive_sign)
		flag->sign = 0;
	if (flag->precision >= 0)
	{
		if (flag->padding_type == '0')
			flag->padding_type = 0;
		flag->zero_prec = flag->precision - ft_strlen(ret->data);
	}
}
