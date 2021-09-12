/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:24:12 by ensebast          #+#    #+#             */
/*   Updated: 2021/09/12 15:39:52 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	pre_format_print(t_attr_f *flag_info)
{
	int	i;

	i = write(1, "%", 1);
	if (flag_info -> octo_flag)
		i += write(1, "#", 1);
	if (flag_info -> plus_flag)
		i += write(1, "+", 1);
	if (flag_info -> minus_flag)
		i += write(1, "-", 1);
	else if (flag_info -> zero_quant)
		i += write(1, "0", 1);
	if (flag_info -> dot_flag >= 0)
	{
		i += write(1, ".", 1);
		count_num_s(flag_info -> dot_flag, &i);
		int_print_s(flag_info -> dot_flag, 0);
	}
	return (i);
}

static void	scan(int i, int *control_arr, const char *str)
{
	while (str[i] != '.')
	{
		if (str[i] == '#')
			control_arr[0] = 1;
		else if (str[i] == '+')
			control_arr[1] = 1;
		else if (str[i] == '-')
			control_arr[2] = 1;
		else if (str[i] == '0')
			control_arr[3] = 1;
		i += 1;
	}
}

static void	control_init(int *arr)
{
	int	k;

	k = 0;
	while (k < 4)
		arr[k] = 0;
}

//control_arr index
//0 = #
//1 = +
//2 = -
//3 = 0
static int	print_in_order(const char *str)
{
	int	i;
	int	control_arr[4];

	i = 0;
	scan(i, control_arr, str);
	control_init(control_arr);
	if (control_arr[0])
		i += write(1, "#", 1);
	if (control_arr[1])
		i += write(1, "+", 1);
	if (control_arr[2])
		i += write(1, "-", 1);
	else if (control_arr[3])
		i += write(1, "0", 1);
	return (i);
}

void	format_null(t_attr_f *flag_info, const char *str, int *i, int *count)
{
	if (flag_info -> format_flag == 0)
	{
		if (flag_info -> dot_flag >= 0)
		{
			*count += write(1, "%", 1);
			*count += print_in_order(str);
			*count += write(1, ".0", 2);
			find(str, '.', i, 1);
		}
		else
			*count = -1;
	}
	else
	{
		*count += pre_format_print(flag_info);
		find(str, flag_info -> format_flag, i, 1);
	}
}
