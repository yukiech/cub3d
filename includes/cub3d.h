#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <sys/time.h>

# include <mylibft.h>
# include <mlx.h>

# define IS_SPACE " \t\n\r\v\f"
# define UCHAR unsigned char

# define GEN_WIDTH 80
# define GEN_HEIGHT 60

# define GEN_PROPAG 25
# define GEN_CONTINUE 70
# define GEN_TRESH 0.08
# define GEN_BORDERS 0.2

# define GEN_NORTH "./assets/normal_north.xpm"
# define GEN_SOUTH "./assets/normal_south.xpm"
# define GEN_WEST "./assets/normal_west.xpm"
# define GEN_EAST "./assets/normal_east.xpm"
# define GEN_CEIL "220,100,0"
# define GEN_FLOOR "225,30,0"

# define K_ESCAPE 53

# include <structs.h>
# include <headers.h>

#endif