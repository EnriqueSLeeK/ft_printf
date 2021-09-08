/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 14:25:01 by ensebast          #+#    #+#             */
/*   Updated: 2021/09/06 18:35:51 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	count_hex(unsigned int d, int *i)
{
	if (d == 0)
		*i += 1;
	else
	{
		while (d != 0)
		{
			d /= 16;
			*i += 1;
		}
	}
}

void	format_hex(t_attr_f *flag_info, unsigned int d, int *count)
{
	int	i;
	int	check_minus_zero;

	i = 0;
	check_minus_zero = flag_info -> zero_quant
		&& !(flag_info -> zero_quant && flag_info -> minus_flag);
	count_hex(d, &i);
	octo_flag(flag_info -> octo_flag, &i);
	if (!(check_minus_zero))
		zero_flag(flag_info -> zero_quant, &i);
	hex_to_dec_u(d, 0);
	if (check_minus_zero)
		minus_flag(flag_info -> zero_quant, &i);
	*count += i;
}
