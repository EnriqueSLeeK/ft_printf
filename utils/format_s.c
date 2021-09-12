/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 14:47:06 by ensebast          #+#    #+#             */
/*   Updated: 2021/09/12 15:40:16 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	how_many_print(char *str, int dot_flag, int *i)
{
	if (dot_flag == -1)
	{
		if (str == 0 && dot_flag == -1)
		{
			*i += 6;
			return (6);
		}
		while (str[*i])
			*i += 1;
		return (*i);
	}
	if (str == 0)
	{
		if (dot_flag > 6)
			*i += 6;
		else
			*i += dot_flag;
		return (*i);
	}
	while (str[*i] && *i < dot_flag)
		*i += 1;
	return (*i);
}

static void	prefix_print(t_attr_f *flag_info, int *i)
{
	if (flag_info -> width_size)
		width(flag_info -> width_size, i);
	else if (flag_info -> zero_quant && flag_info -> dot_flag != -1)
		width(flag_info -> zero_quant, i);
}

void	format_string(t_attr_f *flag_info, char *str, int *count)
{
	int	i;
	int	char_quant_p;

	i = 0;
	char_quant_p = how_many_print(str, flag_info -> dot_flag, &i);
	prefix_print(flag_info, &i);
	if (str == 0)
	{
		write(1, "(null)", char_quant_p);
		*count += i;
		return ;
	}
	write(1, str, char_quant_p);
	minus_flag(flag_info -> minus_flag, &i);
	*count += i;
}
