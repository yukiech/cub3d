/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:49:18 by jjaqueme          #+#    #+#             */
/*   Updated: 2022/04/29 14:16:35 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <sys/time.h>
# include <time.h>

# include <sys/types.h>
# include <signal.h>

# include <math.h>

# include <mylibft.h>
# include <mlx.h>

# define IS_SPACE " \t\n\r\v\f"
# define UCHAR unsigned char

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 1200
# endif
# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 1200
# endif

# define RENDER_DIST 16
# define MAGIC_NBR 30

# include <structs.h>
# include <headers.h>
# include <key_macos.h>

#endif
