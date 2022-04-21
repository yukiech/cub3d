#include <cub3d.h>

void	ft_clear_walls(t_vars *vars);
void	ft_draw_items(t_vars *vars);
t_ray	*ft_cast_rays(t_vars *vars, t_point ray_end);

int	ft_loop_hook(t_vars *vars)
{

	if (vars->game_state == 0)
		loading_screen(vars, 0);
	else if (vars->game_state == 1)
		loading_screen(vars, vars->loading.pos);
	else if (vars->game_state == 2)
	{

		mlx_clear_window(vars->mlx, vars->win);
		ft_draw_background(vars);
		ft_draw_walls(vars);
//		ft_draw_items(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->screen.img, 0, 0);

		minimap(vars);
		ft_hp_draw(vars);
	}
	return (0);
}

void	menu_hook(t_vars *vars, int keycode)
{
	if (keycode == K_AR_L || keycode == K_AR_R || keycode == K_AR_U || keycode == K_AR_D)
		sound_choice();
	if (keycode == K_AR_L && vars->loading.pos % 2 == 0)
		vars->loading.pos -= 1;
	else if (keycode == K_AR_R && vars->loading.pos % 2 == 1)
		vars->loading.pos += 1;
	else if (keycode == K_AR_U && vars->loading.pos > 2)
		vars->loading.pos -= 2;
	else if (keycode == K_AR_D && vars->loading.pos < 3)
		vars->loading.pos += 2;
	else if (keycode == K_ENTER)
	{
		set_char_stats(vars);
		vars->game_state = 2;
		if (vars->loading.sound == 1)
			sound_music(vars->loading.music_title);
		sound_choice();
		mlx_mouse_hide();
		mlx_mouse_move(vars->win, vars->screen.w / 2, vars->screen.h / 2);
}
	else if (keycode == K_ESCAPE)
		ft_free(vars);
}

int	ft_key_hook(int keycode, t_vars *vars)
{
	if (keycode == K_ESCAPE)
		ft_free(vars);

	if (vars->player.mspeed == 0)
		vars->player.mspeed = 0.05;

	if (vars->game_state == 0)
		vars->game_state = 1;
	else if (vars->game_state == 1)
	{
		menu_hook(vars, keycode);
	}
	if (vars->game_state == 2)
	{
		if (keycode == K_ESCAPE)
			ft_free(vars);
		else
			ft_move(vars, keycode, vars->player.mspeed);
	}
	return (0);
}

int	ft_click_hook(int button, int x, int y, t_vars *vars)
{
//	printf("CLICK %d %d %d\n", x, y, button);


	if (vars->game_state == 1 && button == M_CLK_L)
	{
		if (x >= 720 && x <= 770 && y >= 30 && y <= 80)
		{
			if (vars->loading.sound == 0)
				vars->loading.sound = 1;
			else if (vars->loading.sound == 1)
				vars->loading.sound = 0;
		}
	}
	else if (vars->game_state == 2 && button == M_CLK_L)
	{
	    t_ray *cast = ft_cast_rays(vars, (t_point){.x = vars->player.pos.x + cos(vars->player.angle), .y = vars->player.pos.y + sin(vars->player.angle)});


		printf("%p\n", cast);

		if (cast != NULL)
		{
			t_wall w = vars->map.walls[cast->wall];

			if (ft_pyta(0.5 + w.pos.y - vars->player.pos.y, 0.5 + w.pos.x - vars->player.pos.x) < 2.5)
			{

				printf("%f   %f\n", w.pos.y, w.pos.x);

				if (w.type == W_DOOR)
				{
					vars->map.walls[cast->wall].type = -1;
					vars->map.raw[(int)w.pos.y][(int)w.pos.x] = '0';
				}
			}
			free(cast);
		}
	}
	return (0);
}

int	ft_mouse_hook(int x, int y, t_vars *vars)
{
	if (vars->game_state == 2)
	{
		vars->player.angle += radians(x - vars->screen.w / 2) / 8;
		if (vars->player.angle > M_PI)
			vars->player.angle -= 2*M_PI;
		if (vars->player.angle < -M_PI)
			vars->player.angle += 2*M_PI;


		vars->player.hori += (vars->screen.h / 2 - y) / 1;
		vars->player.hori = fmax(0, fmin(vars->screen.h, vars->player.hori));
		mlx_mouse_move(vars->win, vars->screen.w / 2, vars->screen.h / 2);
	}
	return (0);
}
