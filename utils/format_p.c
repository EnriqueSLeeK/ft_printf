/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:24:17 by ensebast          #+#    #+#             */
/*   Updated: 2021/09/12 17:08:09 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	print_decision(t_attr_f *flag_info, long unsigned int ptr, int *i)
{
	if ((ptr == 0 && flag_info -> dot_flag == 0)
		&& (flag_info -> zero_quant > 0
			|| flag_info -> width_size > 0
			|| flag_info -> minus_flag > 0))
		write(1, " ", 1);
	else if (!(flag_info -> dot_flag == 0 && ptr == 0))
		hex_to_dec_lower_lu(ptr, 0);
	else
		*i -= 1;
}

static void	prefix_print(t_attr_f *flag_info, int *i, int hex)
{
	if (flag_info -> width_size)
		width(flag_info -> width_size - 2, i);
	else if (flag_info -> zero_quant && flag_info -> dot_flag != -1)
		width(flag_info -> zero_quant - 2, i);
	dot_flag(flag_info -> dot_flag - hex);
	octo_flag('x', 1, i);
	if (flag_info -> zero_quant
		&& !(flag_info -> minus_flag || (flag_info -> dot_flag != -1)))
		zero_flag(flag_info -> zero_quant, i);
}

void	format_address(t_attr_f *flag_info, long unsigned int ptr, int *count)
{
	int	i;
	int	address_dig_c;

	i = 0;
	address_dig_c = hex_count_lu(ptr, &i);
	i = check_diff(flag_info -> dot_flag - address_dig_c, i);
	prefix_print(flag_info, &i, address_dig_c);
	print_decision(flag_info, ptr, &i);
	minus_flag(flag_info -> minus_flag, &i);
	*count += i;
}
