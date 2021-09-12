/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 14:25:01 by ensebast          #+#    #+#             */
/*   Updated: 2021/09/11 22:17:53 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	print_decision(t_attr_f *flag_info, unsigned int d, int *i)
{
	if ((d == 0 && flag_info -> dot_flag == 0)
		&& (flag_info -> zero_quant > 0
			|| flag_info -> width_size > 0
			|| flag_info -> minus_flag > 0))
		write(1, " ", 1);
	else if (!(flag_info -> dot_flag == 0 && d == 0))
	{
		if (flag_info -> format_flag == 'X')
			hex_to_dec(d, 0, "0123456789ABCDEF");
		else
			hex_to_dec(d, 0, "0123456789abcdef");
	}
	else
		*i -= 1;
}

static void	prefix_print(t_attr_f *flag_info, unsigned int d, int *i, int hex)
{
	if (flag_info -> width_size)
		width(flag_info -> width_size, i);
	else if (flag_info -> zero_quant && flag_info -> dot_flag != -1)
		width(flag_info -> zero_quant, i);
	dot_flag(flag_info -> dot_flag - hex);
	if (d > 0)
		octo_flag(flag_info -> format_flag, flag_info -> octo_flag, i);
	if (flag_info -> zero_quant
		&& !(flag_info -> minus_flag || (flag_info -> dot_flag != -1)))
		zero_flag(flag_info -> zero_quant, i);
}

void	format_hex(t_attr_f *flag_info, unsigned int d, int *count)
{
	int	i;
	int	hex_count;

	i = 0;
	hex_count = count_hex(d, &i);
	i = check_diff(flag_info -> dot_flag - hex_count, i);
	prefix_print(flag_info, d, &i, hex_count);
	print_decision(flag_info, d, &i);
	minus_flag(flag_info -> minus_flag, &i);
	*count += i;
}
