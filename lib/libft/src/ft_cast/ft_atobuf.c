/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atobuf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 07:54:40 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/01 08:16:01 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_cast.h"

t_buff	ft_atobuf(char *str)
{
	t_buff	ret;

	ret.data = ft_strdup(str);
	ret.len = ft_strlen(ret.data);
	return (ret);
}
