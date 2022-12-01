/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_buff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:01:33 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/01 10:02:38 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/_ft_printf.h"

void	free_buff(void *buff)
{
	ft_bufclear((t_buff *) buff);
	free(buff);
}
