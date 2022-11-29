/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:41:11 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/29 07:42:47 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf_helpers.h"

/*
**	on transforme toutes les boites qui commencent par %
**	en le string que ca devrait etre
*/
void	ft_parse(t_list **modules, va_list args)
{
	t_list	*module;
	t_flags	flags;

	module = *modules;
	while (module)
	{
		if (((char *)module->content)[0] == '%')
			flags = decompose_pur_flags(*module);
		// if (flags.to_parse)
		// 	(char *)(module->content) = parse_arg(args, flags)
		module = module->next;
	}
	(void) args;
}

t_flags	decompose_pur_flags(t_list module)
{
	t_flags	flags;
	int		i;

	i = -1;
	while (((char *)module.content)[++i])
	{
		if (((char *)module.content)[i] == '#')
			flags.hashtag = 1;
		else if (((char *)module.content)[i] == '0' && !flags.minus)
			flags.zero = 1;
		else
			decompose_numbered_flags(&module, &flags, &i);
	}
	return (flags);
}

void	decompose_numbered_flags(t_list *module, t_flags *flags, int *i)
{
	if (((char *)module->content)[*i] == '-')
	{
		flags->minus = 1;
		flags->zero = 0;
	}
	else if (((char *)module->content)[*i] == '.')
		flags->dot = 1;
	else if (((char *)module->content)[*i] == ' ')
		flags->space = 1;
	else if (((char *)module->content)[*i] == '+')
	{
		flags->plus = 1;
		flags->space = 0;
	}
}
