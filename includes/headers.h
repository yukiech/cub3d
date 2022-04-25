#ifndef HEADERS_H
# define HEADERS_H




//-----------------
//draw.c
void	ft_draw_hline(t_imgptr *ptr, t_point o, int len, int color);
void	ft_draw_vline(t_imgptr *ptr, t_point o, int len, int color);

//-----------------
//free.c
void	ft_tfree(void **ptr);
int	    ft_free_all(t_vars *vars);
void	ft_free_map(t_vars *vars);
void	ft_exit(t_vars *vars, char *error);


//-----------------
//generate.c
void	ft_generate_map(t_vars *vars, unsigned int seed);

//-----------------
//hook.c
int		ft_loop_hook(t_vars *vars);
void	menu_hook(t_vars *vars, int keycode);
int		ft_key_hook(int keycode, t_vars *vars);
int		ft_release_hook(int keycode, t_vars *vars);
int		ft_click_hook(int button, int x, int y, t_vars *vars);
int		ft_mouse_hook(int x, int y, t_vars *vars);

//-----------------
//hp.c
void	ft_damage(t_vars *vars);
void	ft_hp_draw(t_vars *vars);


//-----------------
//images.c
void	ft_load_image(t_vars *vars, char *filename, t_imgptr *ptr);
void	ft_put_image_full(t_vars *vars, t_imgptr *img);
void	ft_put_image(t_vars *vars, t_imgptr *img, t_point o1, t_point o2);
void	ft_put_col(t_vars *vars, t_imgptr *img, t_point o1, float ratio);

//-----------------
//loading_menu.c

//-----------------
//math_game.c
void	ft_set_px(t_imgptr *img, int x, int y, int color);
int	    ft_get_px(t_imgptr *img, int x, int y);
int	    ft_color(UCHAR a, UCHAR r, UCHAR g, UCHAR b);
char	ft_get_case(t_vars *vars, int x, int y);

//-----------------
//math.c
int	    bsp(t_point p, t_point l1, t_point l2);
float	map(float x, t_vect in, t_vect out);
float	ft_pyta(float a, float b);
float	radians(float deg);
float	degrees(float rad);

//-----------------
//minimap.c
void	minimap_draw(t_vars *vars);

//-----------------
//movements.c
void	ft_move(t_vars *vars, int keycode);

//-----------------
//open_map.c
void	ft_open_map(t_vars *vars, char *filename);


//-----------------
//pistol.c


//-----------------
//process_map.c
void	ft_process_map(t_vars *vars);

//-----------------
//rays.c
t_ray	*ft_cast_rays(t_vars *vars, t_point ray_end);
t_ray	*ft_cast_rays_inv(t_vars *vars, t_point ray_end);

//-----------------
//read_args.c
void	ft_read_args(t_vars *vars, int fd);

//-----------------
//screen.c
void	ft_draw_background(t_vars *vars);
void	ft_draw_walls(t_vars *vars);

//-----------------
//sound.c
void	sound_music(t_vars *vars, char *title);
void	play_sound(t_vars *vars, char *path);
void	sound_kill(void);

//-----------------
//tabs.c
int		ft_concat_tab(char ***ptr, char *new);
size_t	ft_tab_len(char **tab);
void	ft_free_2d(char **tab);

//-----------------
//text.c
void	ft_load_texter(t_vars *vars);
void	ft_write_text(t_vars *vars, char *str, t_point pos, t_vect si_col);

//-----------------
//walls_create.c
void	ft_create_wall(t_wall *walls, t_point p, int side, int type);

//-----------------
//walls_register.c
void	ft_register_walls(t_vars *vars);

#endif //CUB3D_H
