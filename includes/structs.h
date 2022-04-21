#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_point {
	float	x;
	float	y;
}	t_point;

typedef struct s_ray {
	t_point	p;
	int		wall;

	float	dist;
	float	t;
	float	u;
}	t_ray;

typedef struct s_vect {
	float	v1;
	float	v2;
}	t_vect;

typedef struct s_player {
	t_point	pos;
	float	hori;
	float	angle;
	float	fov;
	int	hp;
	float	mspeed;
	int	ghost;
}	t_player;

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
	char	*raw;
	int		color;
}	t_color;

# define W_NONE 0
# define W_UPWALL 1
# define W_LEFTWALL 2
# define W_RIGHTWALL 3
# define W_DOWNWALL 4
# define W_DOOR 5
# define W_DOOR_OPEN 6

#define SEE_THROUGH "0H"
#define SEE_NOT	"1D"

typedef struct s_wall {
	int			type;
	t_point		pos;
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
	t_imgptr	door;

	t_wall		*walls;
	char		**raw;
	int			height;
}	t_map;

typedef struct s_loading {
	t_imgptr	loading;
	t_imgptr	loading2;
	t_imgptr	ghost;
	t_imgptr	ninja;
	t_imgptr	pirate;
	t_imgptr	franken;
	int			i;
	int			pos;
} t_loading;

typedef struct s_vars {
	void		*mlx;
	void		*win;

	int		game_state;
	t_loading	loading;
	t_imgptr	texter;
	t_player	player;
	t_map		map;
	t_imgptr	background;
	t_imgptr	screen;
}	t_vars;

#endif //STRUCTS_H
