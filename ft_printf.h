/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybichri <ybichri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 09:23:57 by ybichri           #+#    #+#             */
/*   Updated: 2020/03/03 01:43:06 by ybichri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int				ft_printf(const char *format, ...);
/*
** GLOBAL VARIABLES
*/
size_t			g_pos;
va_list			g_params;
/*
** CONVERSION HANDLING STRUCT
*/
typedef struct	s_arg
{
	int		just;
	int		fill_char;
	int		min_width;
	int		precision;
	int		point;
}				t_arg;
/*
** HANDLERS
*/
int				ft_arg_handler(const char *format);
int				ft_conversion_dispatcher(const char char_conv, t_arg *curr_arg);
/*
** PRINTERS
*/
int				ft_print_char(unsigned char c, int flag, t_arg *curr_arg);
int				ft_print_str(t_arg *curr_arg);
int				ft_print_pointer(t_arg *curr_arg);
int				ft_print_decimal(t_arg *curr_arg);
int				ft_print_unsigned(int base, int maj, t_arg *curr_arg);
/*
** HELPERS
*/
void			*ft_memset(void *dest, int val, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t len);
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *str);
int				is_conversion(char c);
int				ft_isdigit(int val);
int				ft_toupper(int val);
char			*ft_strdup(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin_free(char *s1, char *s2);
char			*ft_strinsert(char *s1, size_t pos, char *s2);
char			*ft_strgen(char c, size_t len);
char			*ft_itoa(int n);
char			*ft_ltoa_base(long long n, int base);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
#endif
