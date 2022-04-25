#include <cub3d.h>

void	load_pistol(t_vars *vars);
void	menu_load_image(t_vars *vars);

void	set_char_stats(t_vars *vars);
void	menu_screen(t_vars *vars);
void	loading_screen(t_vars *vars);
void	load_music_title(t_vars *vars, char *map);

#define CROSS_LEN 20
#define CROSS_WIDTH 3

void	ft_draw_cross(t_vars *vars)
{
	int	i;
	int	mid_h;
	int	mid_w;

	mid_h = vars->screen.h / 2;
	mid_w = vars->screen.w / 2;
	i = mid_h - (CROSS_WIDTH / 2);
	while (i < mid_h + (CROSS_WIDTH / 2))
	{
		ft_draw_hline(&vars->screen, (t_point){mid_w - (CROSS_LEN / 2), i},
			CROSS_LEN, 0xFFFFFF);
		i++;
	}
	i = mid_w - (CROSS_WIDTH / 2);
	while (i < mid_w + (CROSS_WIDTH / 2))
	{
		ft_draw_vline(&vars->screen, (t_point){i, mid_h - (CROSS_LEN / 2)},
			CROSS_LEN, 0xFFFFFF);
		i++;
	}
}

#define PISTOL_SPEED 6
int	ft_loop_hook(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);

	if (vars->game_state == 0)
		loading_screen(vars);
	else if (vars->game_state == 1)
		menu_screen(vars);
	else if (vars->game_state == 2)
	{
		
		ft_draw_background(vars);

		ft_draw_walls(vars);

		minimap_draw(vars);

		//ft_hp_draw(vars);

		if (vars->pistol.frame < PISTOL_SPEED * 1)
			ft_put_image(vars, &vars->pistol.pistol1,
			(t_point){300, 300}, (t_point){800, 800});
		else if (vars->pistol.frame < PISTOL_SPEED * 2)
			ft_put_image(vars, &vars->pistol.pistol2,
			(t_point){300, 300}, (t_point){800, 800});
		else if (vars->pistol.frame < PISTOL_SPEED * 3)
			ft_put_image(vars, &vars->pistol.pistol3,
			(t_point){300, 300}, (t_point){800, 800});
		else if (vars->pistol.frame < PISTOL_SPEED * 4)
			ft_put_image(vars, &vars->pistol.pistol4,
			(t_point){300, 300}, (t_point){800, 800});
		else
			ft_put_image(vars, &vars->pistol.pistol1,
			(t_point){300, 300}, (t_point){800, 800});
		vars->pistol.frame++;

		ft_draw_cross(vars);


//		ft_write_text(vars, "+", (t_point){vars->screen.w / 2, vars->screen.h / 2}, (t_vect){3, 0xFFFFFF});



		mlx_put_image_to_window(vars->mlx, vars->win, vars->screen.img, 0, 0);

	}

	mlx_put_image_to_window(vars->mlx, vars->win, vars->screen.img, 0, 0);
	vars->frame = (vars->frame + 1) % 1000000000;
	return (0);
}

void	move_menu(t_vars *vars, int keycode)
{
	sound_music(vars, "choice");
	if (keycode == K_AR_L && vars->loading.pos % 2 == 0)
		vars->loading.pos -= 1;
	else if (keycode == K_AR_R && vars->loading.pos % 2 == 1)
		vars->loading.pos += 1;
	else if (keycode == K_AR_U && vars->loading.pos > 2)
		vars->loading.pos -= 2;
	else if (keycode == K_AR_D && vars->loading.pos < 3)
		vars->loading.pos += 2;
}

void	menu_hook(t_vars *vars, int keycode)
{
	if (keycode == K_AR_L || keycode == K_AR_R || keycode == K_AR_U || keycode == K_AR_D)
		move_menu(vars, keycode);
	else if (keycode == K_ENTER)
	{
		set_char_stats(vars);
		if (vars->map.music == NULL)
			vars->map.music = ft_strdup("./sound/nyancat.mp3");
		play_sound(vars, vars->map.music);
		sound_music(vars, "choice");
		mlx_mouse_hide();
		mlx_mouse_move(vars->win, vars->screen.w / 2, vars->screen.h / 2);
		vars->game_state = 2;
	}
}

int	ft_key_hook(int keycode, t_vars *vars)
{
	if (keycode == K_ESCAPE)
		ft_free_all(vars);

	if (vars->game_state > 0 && keycode == K_M)
	{
		vars->player.has_sound = !vars->player.has_sound;
		if (vars->player.has_sound == 1 && vars->game_state == 2)
			play_sound(vars, vars->map.music);
		else
			sound_kill();
	}
	if (vars->game_state == 0)
	{
		vars->game_state = 1;
		sound_music(vars, "choice");
	}
	else if (vars->game_state == 1)
	{
		menu_hook(vars, keycode);
	}
	else if (vars->game_state == 2)
	{
		ft_move(vars, keycode);
	}
	return (0);
}

int	ft_release_hook(int keycode, t_vars *vars)
{
	if (vars->game_state == 2)
	{
		ft_move(vars, -keycode);
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
			vars->player.has_sound = !vars->player.has_sound ;
		}
	}
	else if (vars->game_state == 2 && button == M_CLK_L)
	{
	    t_ray *cast = ft_cast_rays_inv(vars, (t_point){.x = vars->player.pos.x + cos(vars->player.angle), .y = vars->player.pos.y + sin(vars->player.angle)});


		if (cast != NULL)
		{
			t_wall w = vars->map.walls[cast->wall];

			if (ft_pyta(0.5 + w.pos.y - vars->player.pos.y, 0.5 + w.pos.x - vars->player.pos.x) < 2.5)
			{
				if (w.type == W_DOOR)
				{
					vars->map.walls[cast->wall].type = W_DOOR_OPEN;
					vars->map.raw[(int)w.pos.y][(int)w.pos.x] = '0';
				}
				else if (w.type == W_DOOR_OPEN && ((int)vars->player.pos.x != (int)w.pos.x || (int)vars->player.pos.y != (int)w.pos.y))
				{
					vars->map.walls[cast->wall].type = W_DOOR;
					vars->map.raw[(int)w.pos.y][(int)w.pos.x] = 'D';
				}
			}
			free(cast);
		}
		vars->pistol.frame = 0;
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
