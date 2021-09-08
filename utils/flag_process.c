/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 22:49:57 by ensebast          #+#    #+#             */
/*   Updated: 2021/09/08 10:53:08 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static t_attr_f	*init(t_attr_f *node)
{
	node -> format_flag = 0;
	node -> minus_flag = 0;
	node -> plus_flag = 0;
	node -> zero_quant = 0;
	node -> dot_flag = -1;
	node -> octo_flag = 0;
	node -> space_flag = 0;
	node -> next = 0;
	return (node);
}

static int	get_quant(const char *str, int *i)
{
	int		result;
	char	*number;

	*i += 1;
	while (str[*i])
	{
		if (!(ft_isdigit(str[*i])))
			break ;
		*i += 1;
	}
	number = ft_substr(str, 0, *i);
	if (number == 0)
		return (-1);
	result = ft_atoi(number);
	free(number);
	return (result);
}

static int	parse_extra_flags(t_attr_f *node, const char *str)
{
	int	i;

	i = 1;
	while (str[i] && str[i] != '%')
	{
		if (str[i] == '-' && node -> minus_flag == 0)
			node -> minus_flag = get_quant(str, &i);
		else if (str[i] == '0' && node -> zero_quant == 0)
			node -> zero_quant = get_quant(str, &i);
		else if (str[i] == '.' && node -> dot_flag == -1)
			node -> dot_flag = get_quant(str, &i);
		else if (str[i] == '#')
			node -> octo_flag = 1;
		else if (str[i] == ' ')
			node -> space_flag = 1;
		else if (str[i] == '+')
			node -> plus_flag = 1;
		else
		{
			node -> format_flag = str[i];
			break ;
		}
		i += 1;
	}
	return (i);
}

static void	process(t_attr_f *node, const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '%')
		i += 1;
	while (str[i])
	{
		i += parse_extra_flags(node, &str[i]);
		if (str[i] && node -> format_flag == 0)
		{
			node -> format_flag = '%';
			while (str[i] && str[i] != '%')
				i += 1;
		}
		else if (str[i] && str[i] == '%')
		{
			node -> next = init(malloc(sizeof(t_attr_f)));
			node = node -> next;
		}
	}
}

t_attr_f	*flag_process(const char *str)
{
	t_attr_f	*head;
	int			i;

	i = 0;
	head = 0;
	while (str[i] && str[i] != '%')
		i += 1;
	if (str[i])
	{
		head = init(malloc(sizeof(t_attr_f)));
		if (head == 0)
			return (0);
		process(head, str);
	}
	return (head);
}
