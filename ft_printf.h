/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-g <rgomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:37:29 by rgomes-g          #+#    #+#             */
/*   Updated: 2025/08/15 21:44:08 by rgomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		parse_format(const char *format, va_list args);
int		handle_specifier(char specifier, va_list args);
int		print_percent(void);
int		print_char(va_list args);
int		print_str(va_list args);
int		convert_int(va_list args);
int		convert_ptr(va_list args);
int		convert_unsigned(va_list args);
int		convert_hex(va_list args, char specifier);

size_t	ft_strlen(const char *s);

#endif 