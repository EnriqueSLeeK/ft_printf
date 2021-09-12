/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:57:00 by ensebast          #+#    #+#             */
/*   Updated: 2021/09/11 23:17:16 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	count_num_s(int d, int *i)
{
	int	k;

	if (d == 0)
	{
		*i += 1;
		return (1);
	}
	else
	{
		k = 0;
		while (d != 0)
		{
			*i += 1;
			d /= 10;
			k += 1;
		}
		return (k);
	}
}

int	count_num_u(unsigned int d, int *i)
{
	int	k;

	if (d == 0)
	{
		*i += 1;
		return (1);
	}
	else
	{
		k = 0;
		while (d != 0)
		{
			k += 1;
			*i += 1;
			d /= 10;
		}
		return (k);
	}
}

int	count_hex(unsigned int d, int *i)
{
	int	k;

	k = 0;
	if (d == 0)
	{
		*i += 1;
		return (1);
	}
	else
	{
		while (d != 0)
		{
			d /= 16;
			*i += 1;
			k += 1;
		}
		return (k);
	}
}

int	hex_count_lu(long unsigned int hex, int *i)
{
	int	k;

	if (hex == 0)
	{
		*i += 1;
		return (1);
	}
	else
	{
		k = 0;
		while (hex != 0)
		{
			hex /= 16;
			*i += 1;
			k += 1;
		}
		return (k);
	}
}
