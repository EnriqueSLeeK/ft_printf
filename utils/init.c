/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 19:20:45 by ensebast          #+#    #+#             */
/*   Updated: 2021/09/09 19:28:58 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_attr_f	*init(t_attr_f *node)
{
	node -> format_flag = 0;
	node -> width_size = 0;
	node -> minus_flag = 0;
	node -> plus_flag = 0;
	node -> zero_quant = 0;
	node -> dot_flag = -1;
	node -> octo_flag = 0;
	node -> space_flag = 0;
	node -> next = 0;
	return (node);
}

void	init_counter(int *count, int *index)
{
	*count = 0;
	*index = 0;
}
