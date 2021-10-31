/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 19:28:04 by tribeiro          #+#    #+#             */
/*   Updated: 2021/10/31 20:00:49 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int ft_putnbr_base(unsigned int n, int base)
{
    char *hex = "0123456789abcdef";
    char *dec = "0123456789";
    int i;
    int count = 0;

    if (n/base != 0)
        count += ft_putnbr_base(n/base, base);
    i = n % base;
    if (base == 16)
        count += write(1, &hex[i], 1);
    if (base == 10)
        count += write(1, &dec[i], 1);
    return (count);
}

int ft_check_if_negative(int n, int base)
{
    int count = 0;
    if(n < 0)
    {
        n *= -1;
        count += write(1, "-", 1);
    }
    count += ft_putnbr_base(n, base);
    return(count);
}

int ft_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
    return(i);
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    int i = 0;
    int count = 0;

    va_start(ap, format);
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 's')
                count += ft_putstr(va_arg(ap, char *));
            if (format[i] == 'd')
                count += ft_check_if_negative(va_arg(ap, int), 10);
            if (format[i] == 'x')
                count += ft_putnbr_base(va_arg(ap, unsigned int), 16);
        }
        else
            count += write(1, &format[i], 1);
        i++;
    }
    va_end(ap);
    return (count);
}

#include <stdio.h>

int main (void)
{
    int ret;
    int rett;

    printf("============= s ==============\n");
    
    printf("Printf prints:\n");
    ret = printf("Print this string: %s \n", "printed");
    printf("ret = %d \n", ret);
    
    printf("Printf prints:\n");
    rett = ft_printf("Print this string: %s \n", "printed");
    printf("ret = %d \n", rett);
    
    printf("============= d ==============\n");
    
    printf("Printf prints:\n");
    ret = printf("Print this int: %d \n", 79);
    printf("ret = %d \n", ret);
    
    printf("Printf prints:\n");
    rett = ft_printf("Print this int: %d \n", 79);
    printf("ret = %d \n", rett);
    
    printf("Printf prints:\n");
    ret = printf("Print this int: %d \n", -79);
    printf("ret = %d \n", ret);
    
    printf("Printf prints:\n");
    rett = ft_printf("Print this int: %d \n", -79);
    printf("ret = %d \n", rett);
    
    printf("============= x ==============\n");
    
    printf("Printf prints:\n");
    ret = printf("Print this hex: %x \n", 79);
    printf("ret = %d \n", ret);
    
    printf("Printf prints:\n");
    rett = ft_printf("Print this hex: %x \n", 79);
    printf("ret = %d \n", rett);
    
    printf("Printf prints:\n");
    ret = printf("Print this hex: %x \n", -79);
    printf("ret = %d \n", ret);
    
    printf("Printf prints:\n");
    rett = ft_printf("Print this hex: %x \n", -79);
    printf("ret = %d \n", rett);
}
