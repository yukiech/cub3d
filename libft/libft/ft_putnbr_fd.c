/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:39:51 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/10/14 12:39:51 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_fd(int n, int fd)
{
    size_t  res;

    res = 0;
    if (n < 0)
    {
        res++;
        res += ft_putchar_fd('-', fd);
        if (n <= -10)
            res += ft_putnbr_fd((n / 10) * -1, fd);
    }
    else if (n >= 10)
        res += ft_putnbr_fd(n / 10, fd);

    if (n >= 0)
        res += ft_putchar_fd(n % 10 + '0', fd);
    else
        res += ft_putchar_fd((n % 10) * -1 + '0', fd);
    
    return (res);
    
    
    /*
    size_t  res;
    
    res = 0;
	if (n < 0)
	{
		res += ft_putchar_fd('-', fd);
        if (n <= -10)
            res += ft_putnbr_fd((n / 10) * -1, fd);
	}
    else
    {
        if (n >= 10)
            res += ft_putnbr_fd(n, fd);
    }
    if (n >= 0)
        res += ft_putchar_fd(n % 10 + '0', fd);
    else
        res += ft_putchar_fd((n * -1) % 10 + '0', fd);
    return (res);*/
}
