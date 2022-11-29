/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:41:11 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/29 08:51:06 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/_ft_printf.h"

/*
**	on transforme toutes les boites qui commencent par %
**	en le string que ca devrait etre
*/
void	ft_parse(t_list *modules, va_list args)
{
	t_flags	flags;

	while (modules)
	{
		flags = get_flags(module->content);
		if (flags.to_parse)
			(char *)(module->content) = parse_arg(args, flags);
		modules = module->next;
	}
	(void) args;
}

t_flags	get_flags(char *token)
{
	t_flags	ret;

	ret.to_parse = 0;
	return (ret);
}
