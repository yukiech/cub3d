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

# include <structs.h>

# define IS_SPACE " \t\n\r\v\f"

# define UCHAR unsigned char

# define K_ESCAPE 53

//-----------------
//check_map.c

int		ft_count_walls(t_vars *vars);
//void	ft_check_case(t_vars *vars, int x, int y, int *n_walls);
//void	ft_check_case_sides(t_vars *vars, int x, int y);

//-----------------
//draw.c

void	ft_draw_hline(t_vars *vars, t_point o, int len);
void	ft_draw_vline(t_vars *vars, t_point o, int len);

//-----------------
//end.c
void	ft_exit(t_vars *vars, char *error);
int		ft_free(t_vars *vars);

//-----------------
//images.c

void	ft_load_image(t_vars *vars, char *filename, t_imgptr *ptr);
void	ft_set_px(t_imgptr *img, int x, int y, int color);
int		ft_get_px(t_imgptr *img, int x, int y);
int		ft_put_image(t_vars *vars, t_imgptr *img, t_point o1, t_point o2);

//-----------------
//hook.c
int		ft_hook(int keycode, t_vars *vars);

//-----------------
//math.c

void	ft_time(void);
long	map(long x, long in_min, long in_max, long out_min, long out_max);
int		ft_color(UCHAR a, UCHAR r, UCHAR g, UCHAR b);
char	ft_get_case(t_vars *vars, int x, int y);

//-----------------
//read_file.c

void	ft_load_map(t_vars *vars, char *filename);
//int	ft_select_arg(t_vars *vars, cahr **sp);
//void	ft_read_args(t_vars *vars, int fd);
//void	ft_read_map(t_vars *vars, int fd);

//-----------------
//tabs.c

int		ft_concat_tab(char ***ptr, char *new);
size_t	ft_tab_len(char **tab);
void	ft_free_2d(char **tab);

//-----------------
//walls.c

int		ft_register_walls(t_vars *vars);
//void	ft_to_register(t_vars *vars, int x, int y);
//void	ft_add_wall(t_wall *walls, int x, int y, int side);

#endif //CUB3D_H
