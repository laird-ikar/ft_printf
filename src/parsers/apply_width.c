/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:03:34 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/05 09:13:33 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/_ft_printf.h"

/*
 *	[padding spaces][sign symbole][0 padding][mainstr][left padding space]
 */
void	apply_width(t_buff *buff, t_flag *flag)
{
	t_buff	segment[5];
	t_buff	*tmp;
	t_buff	*ret;
	int		padding_space;
	int		i;

	ft_bzero(segment, 5 * sizeof (t_buff *));
	segment[3].data = ft_memdup(buff->data, buff->len);
	segment[3].len = buff->len;
	padding_space = ft_max(0, flag->min_width - buff->len - ft_abs(flag->sign));
	create_padding(segment, flag, padding_space);
	create_sign(segment, flag);
	ft_bufclear(buff);
	ret = NULL;
	i = 5;
	while (i--)
	{
		tmp = ret;
		ret = ft_bufcat(tmp, &segment[i]);
		ft_bufclear(tmp);
		free(segment[i].data);
	}
	buff->data = ret->data;
	buff->len = ret->len;
}

void	create_padding(t_buff segment[5], t_flag *flag, int padding_space)
{
	segment[4].data = NULL;
	segment[4].len = 0;
	segment[0].data = NULL;
	segment[0].len = 0;
	segment[2].data = NULL;
	segment[2].len = 0;
	if (flag->padding_type == 0)
	{
		segment[4].data = ft_strgen(' ', padding_space);
		segment[4].len = ft_strlen(segment[4].data);
	}
	else if (flag->padding_type == '-')
	{
		segment[0].data = ft_strgen(' ', padding_space);
		segment[0].len = ft_strlen(segment[0].data);
	}
	else if (flag->padding_type == '0')
	{
		segment[2].data = ft_strgen('0', padding_space);
		segment[2].len = ft_strlen(segment[2].data);
	}
}

void	create_sign(t_buff segment[5], t_flag *flag)
{
	segment[1].data = NULL;
	segment[1].len = 0;
	if (flag->sign)
	{
		if (flag->sign < 0)
			segment[1].data = ft_strgen('-', 1);
		else if (flag->positive_sign)
			segment[1].data = ft_strgen(flag->positive_sign, 1);
		else
			segment[1].data = NULL;
		segment[1].len = ft_strlen(segment[1].data);
	}
}
