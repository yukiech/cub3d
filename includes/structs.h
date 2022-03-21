#ifndef STRUCTS_H
# define STRUCTS_H

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

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

# define W_NONE 0
# define W_WALL 1

typedef struct s_wall {
	int			type;
	t_point		p1;
	t_point		p2;
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

	t_map		map;
	t_imgptr	screen;
}	t_vars;

#endif //STRUCTS_H