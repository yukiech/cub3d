#include <cub3d.h>

int	ft_loop_hook(t_vars *vars)
{
	ft_draw_background(vars);

	ft_draw_walls(vars);


	char	*time = ft_itoa(ft_time());

	ft_write_text(vars, time, (t_point){.x = 50, .y = 100}, n_vect(10, ft_color(0, 255, 0, 0)));
	free(time);

	mlx_put_image_to_window(vars->mlx, vars->win, vars->screen.img, 0, 0);
	minimap(vars);

	return (0);
}

int	ft_key_hook(int keycode, t_vars *vars)
{
	float	step = 0.2;


	printf("KEY %d\n", keycode);
	if (keycode == K_ESCAPE)
		ft_free(vars);
	else if (keycode == 13) //W
    {
        vars->player.pos.x += cos(vars->player.angle) * step;
        vars->player.pos.y += sin(vars->player.angle) * step;

//		printf("move : %f %f\n", cos(vars->player.angle) * step, sin(vars->player.angle) * step);
//		printf("pos : %f %f\n\n", vars->player.pos.x, vars->player.pos.y);
    }
    else if (keycode == 1) //S
    {
        vars->player.pos.x -= cos(vars->player.angle) * step;
        vars->player.pos.y -= sin(vars->player.angle) * step;

//		printf("move : %f %f\n", cos(vars->player.angle) * step, sin(vars->player.angle) * step);
//		printf("pos : %f %f\n\n", vars->player.pos.x, vars->player.pos.y);
    }

    else if (keycode == 0) //A
    {
        vars->player.pos.x += cos(vars->player.angle - radians(90)) * step;
        vars->player.pos.y += sin(vars->player.angle - radians(90)) * step;
    }
    else if (keycode == 2) //D
    {
        vars->player.pos.x += cos(vars->player.angle + radians(90)) * step;
        vars->player.pos.y += sin(vars->player.angle + radians(90)) * step;
    }

    else if (keycode == 123) //L_ARROW
    {
        vars->player.angle -= radians(5);
		printf("angle : %f\n", degrees(vars->player.angle));
    }
    else if (keycode == 124) //R_ARROW
    {
        vars->player.angle += radians(5);
		printf("angle : %f\n", degrees(vars->player.angle));
    }


    else if (keycode == 126) //UP_ARROW
    {
        vars->player.hori -= 5;
		printf("hori : %f\n", vars->player.hori);
    }
    else if (keycode == 125) //DOWN_ARROW
    {
        vars->player.hori += 5;
		printf("hori : %f\n", vars->player.hori);
    }
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
//	if (x < 0 || y < 0 || x >= vars->screen.w || y >= vars->screen.h)
//		return (0);
//	printf("MOVE %d %d\n", x, y);
	(void)vars;
	(void)x;
	(void)y;
	return (0);
}
