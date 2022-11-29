/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:41:11 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/29 10:06:30 by bguyot           ###   ########.fr       */
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
		if (flag.conv_type)
			module->content = expend_arg(args, flag);
		module = module->next;
	}
	(void) args;
}

t_flag	get_flag(char *token)
{
	t_flag	ret;
	char	conv;

	conv = token[ft_strlen(token) - 1];
	ft_bzero(&ret, sizeof(t_flag));
	ret.precision = -1;
	if (token[0] != '%' || !is_conversion(conv))
	{
		ret.conv_type = 0;
		return (ret);
	}
	ret.conv_type = conv;
	while (is_flag(*(++token)))
		parse_flag(&ret, *token);
	ret.min_width = ft_atoi(token);
	token = ft_strnstr(token, ".", ft_strlen(token));
	if (token++)
		ret.precision = ft_atoi(token);
	return (ret);
}

void	parse_flag(t_flag *flag, char c)
{
	if (c == '#')
		flag->do_alt_form = 1;
	else if (c == '+')
		flag->positive_sign = '+';
	else if (c == ' ')
		flag->positive_sign = ' ';
	else if (c == '0')
		flag->padding_type = '0';
	else if (c == '-')
		flag->padding_type = '-';
}
