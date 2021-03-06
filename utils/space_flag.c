/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:24:45 by ensebast          #+#    #+#             */
/*   Updated: 2021/09/03 11:24:47 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	space_flag(int flag, int sign, int *i)
{
	if (flag)
	{
		if (sign)
			write(1, " ", 1);
		else
			write(1, "-", 1);
		*i += 1;
	}
}
