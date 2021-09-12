/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 22:48:57 by ensebast          #+#    #+#             */
/*   Updated: 2021/09/12 15:36:38 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	find(const char *str, char target, int *i, int control)
{
	while (str[*i] && str[*i] != target)
		*i += 1;
	if (control)
	{
		if (target == '%')
		{
			*i += 1;
			while (str[*i] && str[*i] != target)
				*i += 1;
			*i += 1;
		}
		else
			*i += 1;
	}
}
