/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:24:30 by ensebast          #+#    #+#             */
/*   Updated: 2021/09/11 23:14:25 by ensebast         ###   ########.br       */
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
		int_print_u(d, 0);
	else
		*i -= 1;
}

static void	prefix_print(t_attr_f *flag_info, int *i, int dec)
{
	if (flag_info -> width_size)
		width(flag_info -> width_size, i);
	else if (flag_info -> zero_quant && flag_info -> dot_flag != -1)
		width(flag_info -> zero_quant, i);
	dot_flag(flag_info -> dot_flag - dec);
	if (flag_info -> zero_quant
		&& !(flag_info -> minus_flag || (flag_info -> dot_flag != -1)))
		zero_flag(flag_info -> zero_quant, i);
}

void	format_unsig(t_attr_f *flag_info, unsigned int d, int *count)
{
	int	i;
	int	dec_count_u;

	i = 0;
	dec_count_u = count_num_u(d, &i);
	i = check_diff(flag_info -> dot_flag - dec_count_u, i);
	prefix_print(flag_info, &i, dec_count_u);
	print_decision(flag_info, d, &i);
	minus_flag(flag_info -> minus_flag, &i);
	*count += i;
}
