/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:49:16 by jjaqueme          #+#    #+#             */
/*   Updated: 2022/04/26 13:49:16 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	load_pistol(t_vars *vars);
void	menu_load_image(t_vars *vars);

void	set_char_stats(t_vars *vars);
void	menu_screen(t_vars *vars);
void	loading_screen(t_vars *vars);
void	load_music_title(t_vars *vars, char *map);

void	ft_draw_cross(t_vars *vars);

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
		if (vars->pistol.frame < PISTOL_SPEED * 1)
			ft_put_image(vars, &vars->pistol.pistol1,
				(t_point){240, 450}, (t_point){600, 800});
		else if (vars->pistol.frame < PISTOL_SPEED * 2)
			ft_put_image(vars, &vars->pistol.pistol2,
				(t_point){240, 450}, (t_point){600, 800});
		else if (vars->pistol.frame < PISTOL_SPEED * 3)
			ft_put_image(vars, &vars->pistol.pistol3,
				(t_point){240, 450}, (t_point){600, 800});
		else if (vars->pistol.frame < PISTOL_SPEED * 4)
			ft_put_image(vars, &vars->pistol.pistol4,
				(t_point){240, 450}, (t_point){600, 800});
		else
			ft_put_image(vars, &vars->pistol.pistol1,
				(t_point){240, 450}, (t_point){600, 800});
		vars->pistol.frame++;
		ft_draw_cross(vars);
		ft_damage(vars);
		ft_hp_draw(vars);
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
	if (keycode == K_AR_L || keycode == K_AR_R
		|| keycode == K_AR_U || keycode == K_AR_D)
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

void	ft_next_level(t_vars *vars)
{
	char	*filename;

	ft_free_map(vars);
	vars->player.pos.x = 0;
	vars->level++;
	if (vars->map.next != NULL)
		filename = vars->map.next;
	else
		filename = ft_itoa(rand());
	ft_open_map(vars, &filename);
	ft_process_map(vars);
	ft_register_walls(vars);
}

void	ft_click_interact(t_vars *vars, t_ray *cast)
{
	t_wall	w;

	w = vars->map.walls[cast->wall];
	if (w.type == W_DOOR)
	{
		vars->map.walls[cast->wall].type = W_DOOR_OPEN;
		vars->map.raw[(int)w.pos.y][(int)w.pos.x] = '0';
	}
	else if (w.type == W_DOOR_OPEN && ((int)vars->player.pos.x != (int)w.pos.x
			|| (int)vars->player.pos.y != (int)w.pos.y))
	{
		vars->map.walls[cast->wall].type = W_DOOR;
		vars->map.raw[(int)w.pos.y][(int)w.pos.x] = 'D';
	}
	else if (w.type == W_FINISH)
	{
		ft_next_level(vars);
	}
	else
		vars->pistol.frame = 0;
}

int	ft_click_hook(int button, int x, int y, t_vars *vars)
{
	t_ray		*cast;
	t_wall		w;

	if (vars->game_state == 1 && button == M_CLK_L)
	{
		if (x >= 720 && x <= 770 && y >= 30 && y <= 80)
			vars->player.has_sound = !vars->player.has_sound;
	}
	else if (vars->game_state == 2 && button == M_CLK_L)
	{
		cast = ft_cast_rays_inv(vars, (t_point){.x = vars->player.pos.x
				+ cos(vars->player.angle), .y = vars->player.pos.y
				+ sin(vars->player.angle)});
		if (cast != NULL)
		{
			w = vars->map.walls[cast->wall];
			if (ft_pyta(w.pos.y - vars->player.pos.y,
					w.pos.x - vars->player.pos.x) < 2.2)
				ft_click_interact(vars, cast);
			else
				vars->pistol.frame = 0;
			free(cast);
		}
	}
	return (0);
}

int	ft_mouse_hook(int x, int y, t_vars *vars)
{
	if (vars->game_state == 2)
	{
		vars->player.angle += radians(x - vars->screen.w / 2) / 10;
		if (vars->player.angle > M_PI)
			vars->player.angle -= 2 * M_PI;
		if (vars->player.angle < -M_PI)
			vars->player.angle += 2 * M_PI;
		vars->player.hori += (vars->screen.h / 2 - y) / 1;
		vars->player.hori = fmax(0, fmin(vars->screen.h, vars->player.hori));
		mlx_mouse_move(vars->win, vars->screen.w / 2, vars->screen.h / 2);
	}
	return (0);
}
