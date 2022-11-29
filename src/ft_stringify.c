/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:42:03 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/29 08:58:17 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/_ft_printf.h"

/*
**	on foure tout dans out_str
**	on print out_str
**	on return strlen(out_str)
*/
char	*ft_stringify(t_list *module)
{
	char	*ret;
	char	*tmp;

	ret = ft_calloc(1, sizeof(char));
	while (module)
	{
		tmp = ret;
		ret = ft_strjoin(tmp, module->content);
		free(tmp);
		module = module->next;
	}
	return (ret);
}
