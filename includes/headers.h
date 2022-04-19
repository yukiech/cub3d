#ifndef HEADERS_H
# define HEADERS_H

//-----------------
//check_map.c
int		ft_count_walls(t_vars *vars);
//void	ft_check_case(t_vars *vars, int x, int y, int *n_walls);
//void	ft_check_case_sides(t_vars *vars, int x, int y);

//-----------------
//draw.c
void	ft_draw_hline(t_imgptr *ptr, t_point o, int len, int color);
void	ft_draw_vline(t_imgptr *ptr, t_point o, int len, int color);

//-----------------
//end.c
void	ft_exit(t_vars *vars, char *error);
void	ft_tfree(void **ptr);
int		ft_free(t_vars *vars);

//-----------------
//genmap.c
void	ft_generate_map(t_vars *vars, unsigned int seed);
void	ft_gen_start(t_vars *vars);
void	ft_gen_add_spaces(t_vars *vars);

//-----------------
//genmap_utils.c
int		ft_gen_count(t_vars *vars);
void	ft_gen_expend(t_vars *vars, int x, int y, int dir);
int		ft_gen_check2(t_vars *vars);
int		ft_gen_check(t_vars *vars);

//-----------------
//hook.c
int		ft_loop_hook(t_vars *vars);
int		ft_key_hook(int keycode, t_vars *vars);
int		ft_click_hook(int button, int x, int y, t_vars *vars);
int		ft_mouse_hook(int x, int y, t_vars *vars);

//-----------------
//images.c
void	ft_load_image(t_vars *vars, char *filename, t_imgptr *ptr);
void	ft_set_px(t_imgptr *img, int x, int y, int color);
int		ft_get_px(t_imgptr *img, int x, int y);
int		ft_put_image(t_vars *vars, t_imgptr *img, t_point o1, t_point o2, int hori);
int		ft_put_col(t_vars *vars, t_imgptr *img, t_point o1, float ratio);

//-----------------
//items.c
void	ft_register_items(t_vars *vars);

//-----------------
//math.c
int		ft_time(void);
t_vect	*n_vect(float v1, float v2);
float	map(float x, t_vect *in, t_vect *out);
int		ft_color(UCHAR a, UCHAR r, UCHAR g, UCHAR b);
char	ft_get_case(t_vars *vars, int x, int y);
float	ft_pyta(float a, float b);
float	radians(float deg);
float	degrees(float rad);

//-----------------
//rays.c
t_ray	*ray(t_wall w, t_point player, t_point r);

//-----------------
//read_file.c
void	ft_load_map(t_vars *vars, char *filename);
//int	ft_select_arg(t_vars *vars, cahr **sp);
//void	ft_read_args(t_vars *vars, int fd);
//void	ft_read_map(t_vars *vars, int fd);


//-----------------
//screen.c
void	ft_draw_background(t_vars *vars);
void	ft_draw_walls(t_vars *vars);
t_ray	*ft_cast_rays(t_vars *vars, t_point ray_end);
//void	ft_draw_column(t_vars *vars, t_ray *cast, int col);


//-----------------
//tabs.c
int		ft_concat_tab(char ***ptr, char *new);
size_t	ft_tab_len(char **tab);
void	ft_free_2d(char **tab);

//-----------------
//text.c
void	ft_load_texter(t_vars *vars);
void	ft_write_text(t_vars *vars, char *str, t_point pos, t_vect *si_col);

//-----------------
//walls.c
int		ft_register_walls(t_vars *vars);
//void	ft_to_register(t_vars *vars, int x, int y);
//void	ft_add_wall(t_wall *walls, int x, int y, int side);

//-----------------
//minimap.c
void	minimap(t_vars *vars);

//-----------------
//dont_move.c
int		dont_move(t_vars *vars);

//-----------------
//sound.c
void	sound_music(char *title);
void	sound_kill(void);

//-----------------
//wall_block_player.c
void	ft_move(t_vars *vars, int keycode, float step);

#endif //CUB3D_H
