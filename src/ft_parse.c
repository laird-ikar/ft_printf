/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:41:11 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/29 08:58:59 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/_ft_printf.h"

/*
**	on transforme toutes les boites qui commencent par %
**	en le string que ca devrait etre
*/
void	ft_parse(t_list *module, va_list args)
{
	t_flag	flag;

	while (module)
	{
		flag = get_flag(module->content);
		if (flag.to_parse)
			module->content = parse_arg(args, flag);
		module = module->next;
	}
	(void) args;
}

t_flag	get_flag(char *token)
{
	t_flag	ret;

	ret.to_parse = 0;
	return (ret);
	(void) token;
}

char	*parse_arg(va_list args, t_flag flag)
{
	(void) args;
	(void) flag;
	return (NULL);
}
