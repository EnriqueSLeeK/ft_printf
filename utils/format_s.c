/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 14:47:06 by ensebast          #+#    #+#             */
/*   Updated: 2021/08/31 00:25:17 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	format_string(t_attr_f *flag_info, char *str, int *count)
{
	int	i;

	i = 0;
	while (str[i])
		i += 1;
	write(1, str, i);
	minus_flag(flag_info -> minus_flag, &i);
	*count += i;
}
