/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:24:07 by ensebast          #+#    #+#             */
/*   Updated: 2021/09/06 18:31:13 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	int_print(int d, int flag)
{
	char	*charset;

	charset = "0123456789";
	if (flag && d == 0)
		return ;
	if (d == 0)
		write(1, "0", 1);
	else
	{
		int_print(d / 10, 1);
		write(1, &charset[d % 10], 1);
	}
}

static void	count_num(int d, int *i)
{
	if (d == 0)
		*i += 1;
	else
	{
		while (d != 0)
		{
			*i += 1;
			d /= 10;
		}
	}
}

static void	sign_print(int sign)
{
	if (sign)
		write(1, "-", 1);
}

void	format_int(t_attr_f *flag_info, int d, int *count)
{
	int	i;

	i = 0;
	count_num(d, &i);
	if (!(flag_info -> plus_flag))
		space_flag(flag_info -> plus_flag, d >= 0, count);
	else if (flag_info -> plus_flag)
		plus_flag(flag_info -> plus_flag, d >= 0, count);
	else
		sign_print(d < 0);
	if (flag_info -> dot_flag != -1)
		dot_flag(flag_info -> dot_flag, &i);
	else if (!(flag_info -> minus_flag))
		zero_flag(flag_info -> zero_quant, &i);
	int_print(d, 0);
	minus_flag(flag_info -> minus_flag, &i);
	*count += i;
}
