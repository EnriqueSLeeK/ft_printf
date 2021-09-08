/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:24:12 by ensebast          #+#    #+#             */
/*   Updated: 2021/09/04 01:16:08 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	format_null(t_attr_f *flag_info, const char *str, int *d, int *count)
{
	int	i;

	i = 0;
	if (flag_info -> format_flag == 0)
	{
		if (flag_info -> dot_flag)
		{
			while (str[i])
			{
				write(1, &str[i], 1);
				i += 1;
			}
		}
		else
			*count = -1;
	}
	else
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i += 1;
		}
	}
	*d += i;
}
