/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 23:05:47 by ensebast          #+#    #+#             */
/*   Updated: 2021/08/31 00:27:12 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	format_char(t_attr_f *flag_info, char c, int *count)
{
	int	i;

	i = 1;
	write(1, &c, 1);
	minus_flag(flag_info -> minus_flag, &i);
	*count += i;
}
