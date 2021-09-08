/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:54:06 by ensebast          #+#    #+#             */
/*   Updated: 2021/09/06 18:29:28 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flag_attr
{
	char				format_flag;
	int					minus_flag;
	int					plus_flag;
	int					zero_quant;
	int					dot_flag;
	int					octo_flag;
	int					space_flag;
	struct s_flag_attr	*next;
}	t_attr_f;

//Format function
void		format_char(t_attr_f *info, char c, int *count);
void		format_string(t_attr_f *info, char *str, int *count);
void		format_address(t_attr_f *info, long unsigned int ptr, int *count);
void		format_int(t_attr_f *info, int d, int *count);
void		format_unsig(t_attr_f *info, unsigned int d, int *count);
void		format_hex(t_attr_f *info, unsigned int d, int *count);
void		format_null(t_attr_f *info, const char *str, int *d, int *count);
void		format_percent(int *count);

//Extra flags
void		minus_flag(int space_w, int *i);
void		dot_flag(int precision, int *i);
void		octo_flag(int flag, int *i);
void		zero_flag(int width, int *i);
void		space_flag(int flag, int sign, int *i);
void		plus_flag(int flag, int sign, int *i);

//Misc utils
t_attr_f	*flag_process(const char *str);
void		find(const char *str, char target, int *i);
void		hex_to_dec_u(unsigned int dec, int flag);
void		hex_to_dec_lu(long unsigned int dec, int flag);
void		free_and_next(t_attr_f **f);

//Main
int			ft_printf(const char *str, ...);
#endif
