/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:47:50 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/28 16:02:32 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_printf(const char *ft_format, ...)
{
	t_list	*modules;
	char	*out_str;
	int		ret;
	va_list	args;

	if (ft_strlen(ft_format) == 0)
		return (0);
	va_start(args, ft_format);
	modules = ft_split_modules(ft_format);
	ft_parse(&modules, args);
	out_str = ft_stringify(&modules);
	ft_putstr_fd(out_str, 1);
	ret = ft_strlen(out_str);
	free(out_str);
	va_end(args);
	return (ret);
}

/*
**	fill modules avec les morceaux
**	i.e. "bla bvla lda % 0 'fefiuf ejfiusr "
**	[bla bvla lda ]
**	[% 0x]
**	[ fefiuf ejfiusr]
*/
// %d%%
int	need_cut(const char *ft_format, int inside_flag)
{
	if (inside_flag)
	{
		if (ft_strchr(CONVERSIONS, *ft_format))
			return (1);
		else
			return (0);
	}
	else if (*(ft_format + 1) == '%')
		return (1);
	return (0);
}


t_list	*ft_split_modules(const char *ft_format)
{
	t_list		*ret;
	int			inside_flag;
	const char	*ptr;

	ret = NULL;
	inside_flag = 0;
	ptr = ft_format;
	while (*ft_format)
	{
		if (need_cut(ft_format, inside_flag))
		{
			ft_lstadd_back(
				&ret,
				ft_lstnew(ft_strndup(ft_format, ft_format - ptr)));
			ft_format++;
			ptr = ft_format;
		}
		ft_format++;
	}
	return (ret);
}

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
		//if (flags.to_parse)
		//	(char *)(module->content) = parse_arg(args, flags)
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

/*
**	on foure tout dans out_str
**	on print out_str
**	on return strlen(out_str)
*/
char	*ft_stringify(t_list **modules)
{
	(void) modules;
	return (NULL);
}
