/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octo_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:24:40 by ensebast          #+#    #+#             */
/*   Updated: 2021/09/09 16:35:26 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	octo_flag(char format, int flag, int *i)
{
	if (flag)
	{
		if (format == 'x')
		{
			write(1, "0x", 2);
			*i += 2;
		}
		else if (format == 'X')
		{
			write(1, "0X", 2);
			*i += 2;
		}
	}
}
