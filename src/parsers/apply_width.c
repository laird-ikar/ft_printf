/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:03:34 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/02 17:34:54 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/_ft_printf.h"

void	apply_width(t_buff *buff, t_flag *flag)
{
	char	*parts[5];

	//fill part 3
	if (flag->padding_type == 0)
		;//fill part4
	else if (flag->padding_type == '-')
		;//fill part0
	else if (flag->padding_type == '0')
		;//fill part2
	if (flag->sign != 42)
		;//fill part 1
}

/*
 *	[padding spaces][sign symbole][0 padding][mainstr][left padding space]
 */
