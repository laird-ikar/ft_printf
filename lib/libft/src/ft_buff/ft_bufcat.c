/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:01:53 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/01 08:05:46 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_buff.h"

t_buff	ft_bufcat(t_buff a, t_buff b)
{
	t_buff	ret;

	ret.data = ft_memcat(a.data, b.data, a.len, b.len);
	return (ret);
}
