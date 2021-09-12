/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:24:07 by ensebast          #+#    #+#             */
/*   Updated: 2021/09/11 23:03:25 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	sign_print(int sign, int *i)
{
	if (sign)
	{
		write(1, "-", 1);
		*i += 1;
	}
}

static void	prefix_print(t_attr_f *flag_info, int d, int *i, int dec)
{
	int	count_sign;

	if (flag_info -> plus_flag)
		count_sign = 1;
	else if (d >= 0)
		count_sign = 0;
	else
		count_sign = 1;
	if (flag_info -> width_size)
		width(flag_info -> width_size - count_sign, i);
	else if (flag_info -> zero_quant && flag_info -> dot_flag != -1)
		width(flag_info -> zero_quant - count_sign, i);
	if (!(flag_info -> plus_flag) && flag_info -> space_flag)
		space_flag(flag_info -> space_flag, d >= 0, i);
	else if (flag_info -> plus_flag)
		plus_flag(flag_info -> plus_flag, d >= 0, i);
	else
		sign_print(d < 0, i);
	dot_flag(flag_info -> dot_flag - dec);
	if (flag_info -> zero_quant
		&& !(flag_info -> minus_flag || (flag_info -> dot_flag != -1)))
		zero_flag(flag_info -> zero_quant, i);
}

static void	print_decision(int d, int *i, t_attr_f *flag_info)
{
	if ((d == 0 && flag_info -> dot_flag == 0)
		&& (flag_info -> zero_quant > 0
			|| flag_info -> width_size > 0
			|| flag_info -> minus_flag > 0))
		write(1, " ", 1);
	else if (!(flag_info -> dot_flag == 0 && d == 0))
		int_print_s(d, 0);
	else
		*i -= 1;
}

void	format_int(t_attr_f *flag_info, int d, int *count)
{
	int	i;
	int	dec_count;

	i = 0;
	dec_count = count_num_s(d, &i);
	i = check_diff(flag_info -> dot_flag - dec_count, i);
	prefix_print(flag_info, d, &i, dec_count);
	print_decision(d, &i, flag_info);
	minus_flag(flag_info -> minus_flag, &i);
	*count += i;
}
