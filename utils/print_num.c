/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 22:48:47 by ensebast          #+#    #+#             */
/*   Updated: 2021/09/12 15:39:13 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_abs(int d)
{
	if (d < 0)
		return (-d);
	else
		return (d);
}

void	int_print_s(int d, int flag)
{
	char	*charset;

	charset = "0123456789";
	if (flag && d == 0)
		return ;
	if (d == 0)
		write(1, "0", 1);
	else
	{
		int_print_s(d / 10, 1);
		write(1, &charset[ft_abs(d % 10)], 1);
	}
}

void	int_print_u(unsigned int d, int flag)
{
	char	*charset;

	charset = "0123456789";
	if (flag && d == 0)
		return ;
	if (d == 0)
		write(1, "0", 1);
	else
	{
		int_print_u(d / 10, 1);
		write(1, &charset[d % 10], 1);
	}
}

void	hex_to_dec(unsigned int dec, int flag, char *charset)
{
	if (flag && dec == 0)
		return ;
	if (dec == 0)
		write(1, "0", 1);
	else
	{
		hex_to_dec(dec / 16, 1, charset);
		write(1, &charset[dec % 16], 1);
	}
}

void	hex_to_dec_lower_lu(long unsigned int dec, int flag)
{
	char	*charset;

	charset = "0123456789abcdef";
	if (flag && dec == 0)
		return ;
	if (dec == 0)
		write(1, "0", 1);
	else
	{
		hex_to_dec_lower_lu(dec / 16, 1);
		write(1, &charset[dec % 16], 1);
	}
}
