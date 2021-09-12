/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 23:05:47 by ensebast          #+#    #+#             */
/*   Updated: 2021/09/12 00:45:18 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	format_char(t_attr_f *flag_info, char c, int *count)
{
	int	i;

	i = 0;
	width(flag_info -> width_size - 1, &i);
	i += write(1, &c, 1);
	minus_flag(flag_info -> minus_flag, &i);
	*count += i;
}
