/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:54:06 by ensebast          #+#    #+#             */
/*   Updated: 2021/09/11 23:19:46 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_flag_attr
{
	char				format_flag;
	int					width_size;
	int					minus_flag;
	int					plus_flag;
	int					zero_quant;
	int					dot_flag;
	int					octo_flag;
	int					space_flag;
	struct s_flag_attr	*next;
}	t_attr_f;

//init function
t_attr_f	*init(t_attr_f *node);
void		init_counter(int *count, int *index);

//Format function
void		format_percent(int *count);
void		format_int(t_attr_f *info, int d, int *count);
void		format_char(t_attr_f *info, char c, int *count);
void		format_string(t_attr_f *info, char *str, int *count);
void		format_hex(t_attr_f *info, unsigned int d, int *count);
void		format_unsig(t_attr_f *info, unsigned int d, int *count);
void		format_null(t_attr_f *info, const char *str, int *d, int *count);
void		format_address(t_attr_f *info, long unsigned int ptr, int *count);

//Extra flags
void		dot_flag(int precision);
void		zero_flag(int width, int *i);
void		minus_flag(int space_w, int *i);
void		plus_flag(int flag, int sign, int *i);
void		octo_flag(char form, int flag, int *i);
void		space_flag(int flag, int sign, int *i);
void		width(int space, int *i);

//Misc utils
int			check_diff(int diff, int i);
void		free_and_next(t_attr_f **f);
void		int_print_s(int d, int flag);
t_attr_f	*flag_process(const char *str);
void		int_print_u(unsigned int d, int flag);
void		hex_to_dec_lower_lu(long unsigned int dec, int flag);
void		hex_to_dec(unsigned int dec, int flag, char *charset);
void		find(const char *str, char target, int *i, int control);

//Count digit
int			count_num_s(int d, int *i);
int			count_num_u(unsigned int d, int *i);
int			count_hex(unsigned int d, int *i);
int			hex_count_lu(long unsigned int hex, int *i);

//Main
int			ft_printf(const char *str, ...);

#endif
