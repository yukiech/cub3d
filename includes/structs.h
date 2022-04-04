#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_point {
	float	x;
	float	y;
}	t_point;

typedef struct s_ray {
	t_point	p;
	float	t;
	float	u;
}	t_ray;

typedef struct s_vect {
	float	v1;
	float	v2;
}	t_vect;

typedef struct s_imgptr {
	char	*path;
	void	*img;
	int		w;
	int		h;

	int		*pxs;
	int		bits;
	int		line;
	int		end;
}	t_imgptr;

typedef struct s_color {
	char			*raw;
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

# define W_NONE 0
# define W_WALL 1

typedef struct s_wall {
	int			type;
	int			dist;
	t_point		p1;
	t_point		p2;
	t_point		draw1;
	t_point		draw2;
}	t_wall;

typedef struct s_map {
	t_color		floor;
	t_color		ceil;

	t_imgptr	north;
	t_imgptr	west;
	t_imgptr	east;
	t_imgptr	south;

	t_wall		*walls;
	char		**raw;
}	t_map;

typedef struct s_vars {
	void		*mlx;
	void		*win;

	t_imgptr	texter;
	t_map		map;
	t_imgptr	screen;
}	t_vars;

#endif //STRUCTS_H