#include <cub3d.h>

void	ft_clear_walls(t_vars *vars);


int	ft_loop_hook(t_vars *vars)
{
//	static int i = 0;



//	printf("%d  Start all \t\t", i); ft_time();


	mlx_clear_window(vars->mlx, vars->win);


//	printf("%d  After clear  \t", i); ft_time();


	ft_draw_background(vars);

//	printf("%d  After background \t", i); ft_time();



//	ft_clear_walls(vars);


//	printf("%d  After clear wall \t", i); ft_time();


	ft_draw_walls(vars);


//	printf("%d  After wall \t\t", i); ft_time();


//	char	*time = ft_itoa(ft_time());

//	ft_write_text(vars, time, (t_point){.x = 50, .y = 100}, (t_vect){.v1 = 10, .v2 = ft_color(0, 255, 0, 0)});
//	free(time);






	mlx_put_image_to_window(vars->mlx, vars->win, vars->screen.img, 0, 0);

//	printf("%d  Display win \t\t", i); ft_time();


	minimap(vars);

//	printf("%d  End minimap \t\t", i); ft_time();


//	i++;
//	if (i > 6)
//		exit(1);

	return (0);
}

int	ft_key_hook(int keycode, t_vars *vars)
{
	float	step = 0.05;


	printf("KEY %d\n", keycode);
	if (keycode == K_ESCAPE)
		ft_free(vars);
	else
		ft_move(vars, keycode, step);
	return (0);
}

int	ft_click_hook(int button, int x, int y, t_vars *vars)
{
	printf("CLICK %d %d %d\n", x, y, button);
	(void)vars;
	return (0);
}

int	ft_mouse_hook(int x, int y, t_vars *vars)
{
	vars->player.angle += radians(x - vars->screen.w / 2) / 2;
	vars->player.hori += (vars->screen.h / 2 - y) / 2;
	vars->player.hori = fmax(0, fmin(vars->screen.h, vars->player.hori));
	mlx_mouse_move(vars->win, vars->screen.w / 2, vars->screen.h / 2);
	return (0);
}
