/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:24:08 by ensebast          #+#    #+#             */
/*   Updated: 2021/09/06 18:24:09 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init(int *count, int *index)
{
	*count = 0;
	*index = 0;
}

static int	valid_flag(char flag)
{
	char	*flag_list;
	int		i;

	i = 0;
	flag_list = "csdiuxp%";
	while (flag_list[i])
	{
		if (flag_list[i] == flag)
			return (1);
		i += 1;
	}
	return (-1);
}

static void	sp_format(int *c_i, t_attr_f *flag_info, va_list flag_arg)
{
	if (flag_info -> format_flag == 'c')
		format_char(flag_info, va_arg(flag_arg, int), &c_i[0]);
	else if (flag_info -> format_flag == 's')
		format_string(flag_info, va_arg(flag_arg, char *), &c_i[0]);
	else if (flag_info -> format_flag == 'd' || flag_info -> format_flag == 'i')
		format_int(flag_info, va_arg(flag_arg, int), &c_i[0]);
	else if (flag_info -> format_flag == 'u')
		format_unsig(flag_info, va_arg(flag_arg, unsigned int), &c_i[0]);
	else if (flag_info -> format_flag == 'x')
		format_hex(flag_info, va_arg(flag_arg, unsigned int), &c_i[0]);
	else if (flag_info -> format_flag == 'p')
		format_address(flag_info, va_arg(flag_arg, unsigned long int), &c_i[0]);
	else if (flag_info -> format_flag == '%')
		format_percent(&c_i[0]);
}

static void	ft_caller(int *c_i, const char *s, t_attr_f *flag, va_list flag_ag)
{
	if (valid_flag(flag -> format_flag))
	{
		sp_format(c_i, flag, flag_ag);
		find(s, flag -> format_flag, &c_i[1]);
	}
	else
		format_null(flag, s, &c_i[1], &c_i[0]);
}

//i[0] = count
//i[1] = index
int	ft_printf(const char *str, ...)
{
	int			i[2];
	va_list		flag_arg;
	t_attr_f	*flag_info;

	va_start(flag_arg, str);
	init(&i[0], &i[1]);
	flag_info = flag_process(str);
	while (str[i[1]])
	{
		if (str[i[1]] == '%')
		{
			ft_caller(i, str, flag_info, flag_arg);
			free_and_next(&flag_info);
		}
		else
		{
			write(1, &str[i[1]], 1);
			i[1] += 1;
		}
	}
	va_end(flag_arg);
	return (i[1]);
}
