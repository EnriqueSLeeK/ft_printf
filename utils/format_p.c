/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:24:17 by ensebast          #+#    #+#             */
/*   Updated: 2021/09/06 18:32:37 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	hex_count_lu(long unsigned int hex, int *i)
{
	if (hex == 0)
		*i += 1;
	else
	{
		while (hex != 0)
		{
			hex /= 16;
			*i += 1;
		}
	}
}

void	format_address(t_attr_f *flag_info, long unsigned int ptr, int *count)
{
	int	i;

	i = 0;
	hex_count_lu(ptr, &i);
	octo_flag(flag_info -> octo_flag, &i);
	if (flag_info -> dot_flag)
		dot_flag(flag_info -> dot_flag, &i);
	else if (!(flag_info -> minus_flag))
		zero_flag(flag_info -> zero_quant, &i);
	hex_to_dec_lu(ptr, 0);
	minus_flag(flag_info -> minus_flag, &i);
	*count += i;
}
