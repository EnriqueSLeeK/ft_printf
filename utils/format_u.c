/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:24:30 by ensebast          #+#    #+#             */
/*   Updated: 2021/09/08 15:29:38 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	int_print(unsigned int d, int flag)
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

static void	count_num(unsigned int d, int *i)
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

void	format_unsig(t_attr_f *flag_info, unsigned int d, int *count)
{
	int	i;

	i = 0;
	count_num(d, &i);
	if (flag_info -> dot_flag != -1)
		dot_flag(flag_info -> dot_flag, &i);
	else if (!(flag_info -> minus_flag))
		zero_flag(flag_info -> zero_quant, &i);
	int_print(d, 0);
	minus_flag(flag_info -> minus_flag, &i);
	*count += i;
}
