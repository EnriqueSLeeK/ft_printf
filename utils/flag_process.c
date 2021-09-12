/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 22:49:57 by ensebast          #+#    #+#             */
/*   Updated: 2021/09/12 15:40:33 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	get_quant(const char *str, int *i, int offset)
{
	int		result;
	char	*number;
	int		k;

	k = 0;
	*i += offset;
	while (str[k])
	{
		if (!(ft_isdigit(str[k])))
			break ;
		k += 1;
	}
	number = ft_substr(str, 0, k);
	*i += k - 1;
	if (number == 0)
		return (-1);
	result = ft_atoi(number);
	free(number);
	return (result);
}

static int	treat_flag(t_attr_f *node, const char *str, int *i)
{
	if (str[*i] == '-' && node -> minus_flag == 0)
		node -> minus_flag = get_quant(&str[*i + 1], i, 1);
	else if (str[*i] == '0' && node -> zero_quant == 0)
		node -> zero_quant = get_quant(&str[*i + 1], i, 1);
	else if (str[*i] == '.' && node -> dot_flag == -1)
		node -> dot_flag = get_quant(&str[*i + 1], i, 1);
	else if (ft_isdigit(str[*i]))
		node -> width_size = get_quant(&str[*i], i, 0);
	else if (str[*i] == '#')
		node -> octo_flag = 1;
	else if (str[*i] == ' ')
		node -> space_flag = 1;
	else if (str[*i] == '+')
		node -> plus_flag = 1;
	else
	{
		node -> format_flag = str[*i];
		return (1);
	}
	return (0);
}

static int	parse_extra_flags(t_attr_f *node, const char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (treat_flag(node, str, &i))
			break ;
		else
			i += 1;
	}
	return (i + 1);
}

static void	process(t_attr_f *node, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		find(str, '%', &i, 0);
		if (str[i])
		{
			i += parse_extra_flags(node, &str[i]);
			find(str, '%', &i, 0);
			if (str[i])
			{
				node -> next = init(malloc(sizeof(t_attr_f)));
				node = node -> next;
			}
		}
	}
}

t_attr_f	*flag_process(const char *str)
{
	t_attr_f	*head;
	int			i;

	i = 0;
	head = 0;
	find(str, '%', &i, 0);
	if (str[i])
	{
		head = init(malloc(sizeof(t_attr_f)));
		if (head == 0)
			return (0);
		process(head, str);
	}
	return (head);
}
