/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 22:48:47 by ensebast          #+#    #+#             */
/*   Updated: 2021/09/02 00:52:37 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	hex_to_dec_u(unsigned int dec, int flag)
{
	char	*charset;

	charset = "0123456789ABCDEF";
	if (flag && dec == 0)
		return ;
	if (dec == 0)
		write(1, "0", 1);
	else
	{
		hex_to_dec_u(dec / 16, 1);
		write(1, &charset[dec % 16], 1);
	}
}

void	hex_to_dec_lu(long unsigned int dec, int flag)
{
	char	*charset;

	charset = "0123456789ABCDEF";
	if (flag && dec == 0)
		return ;
	if (dec == 0)
		write(1, "0", 1);
	else
	{
		hex_to_dec_lu(dec / 16, 1);
		write(1, &charset[dec % 16], 1);
	}
}
