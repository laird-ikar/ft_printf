/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabmed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:16:44 by bguyot            #+#    #+#             */
/*   Updated: 2022/03/09 12:16:45 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	part2(int *greater, int *i, int *tab, int *size);

int	ft_tabmed(int *tab, int size)
{
	int	i;
	int	tmp;
	int	greater;
	int	smaller;

	i = 0;
	while (i < size)
	{
		smaller = part2(&greater, &i, tab, &size);
		tmp = tab[i];
		if (greater > smaller && ft_abs(greater - smaller) > 2)
			while (tab[i] <= tmp)
				i++;
		else if (greater < smaller && ft_abs(greater - smaller) > 2)
			while (tab[i] >= tmp)
				i++;
		else
			return (tmp);
	}
	return (0);
}

static int	part2(int *greater, int *i, int *tab, int *size)
{
	int	j;
	int	smaller;

	smaller = 0;
	*greater = 0;
	j = 0;
	while (++j < *size)
	{
		if (tab[*i] < tab[j])
			(*greater)++;
		else if (tab[*i] > tab[j])
			smaller++;
	}
	return (smaller);
}
