#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_vect {
	float	v1;
	float	v2;
}	t_vect;

typedef struct s_point {
	float	x;
	float	y;
}	t_point;

typedef struct s_color {
	char	*raw;
	int		color;
}	t_color;

typedef struct s_ray {
	t_point	p;
	int		wall;

	float	dist;
	float	t;
	float	u;
}	t_ray;

typedef struct s_player {
	t_point	pos;
	float	hori;
	float	angle;
	float	fov;
	float		hp;
	float		hp_start;
	float	speed;
	int		speed_mod;
	int		has_collisions;
	int		has_sound;
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

# define W_FIRE -2
# define W_DOOR_OPEN -1
# define W_NONE 0
# define W_UPWALL 1
# define W_LEFTWALL 2
# define W_RIGHTWALL 3
# define W_DOWNWALL 4
# define W_DOOR 5
# define W_FINISH 6

typedef struct s_wall {
	int			type;
	t_point		pos;
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

	char		*music;
	char		*next;

	int			n_walls;
	t_wall		*walls;
	char		**raw;
	int			height;
}	t_map;

typedef struct s_pistol {
	t_imgptr	pistol1;
	t_imgptr	pistol2;
	t_imgptr	pistol3;
	t_imgptr	pistol4;
	t_imgptr	pistol5;
	int			frame;
}	t_pistol;

typedef struct s_fire {
	t_imgptr	fire0;
	t_imgptr	fire1;
	t_imgptr	fire2;
	t_imgptr	fire3;
	t_imgptr	fire4;
	t_imgptr	fire5;
	t_imgptr	fire6;
	t_imgptr	fire7;
	t_imgptr	fire8;
	t_imgptr	fire9;
	int			frame;
}	t_fire;

typedef struct s_loading { 
	t_imgptr	menu_1;
	t_imgptr	menu_2;
	t_imgptr	menu_3;
	t_imgptr	menu_4;
	t_imgptr	ghost;
	t_imgptr	ninja;
	t_imgptr	pirate;
	t_imgptr	franken;
	t_imgptr	sound_on;
	t_imgptr	sound_off;
	t_imgptr	heart;
	t_imgptr	heart_half;
	t_imgptr	damage;
	int			pos;
	char		*music_title;
}	t_loading;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	int			game_state;
	int			frame;
	int			level;

	t_loading	loading;
	t_map		map;

	t_player	player;
	t_pistol	pistol;
	t_imgptr	door;
	t_imgptr	portal;
	t_imgptr	fire[10];

	t_imgptr	screen;
	t_imgptr	texter;
}	t_vars;

#endif //STRUCTS_H
