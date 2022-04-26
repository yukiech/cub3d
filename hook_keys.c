/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:49:16 by jjaqueme          #+#    #+#             */
/*   Updated: 2022/04/26 17:14:31 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	menu_hook(t_vars *vars, int keycode);
static void	move_menu(t_vars *vars, int keycode);
static void	set_char_stats(t_vars *vars);

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

static void	menu_hook(t_vars *vars, int keycode)
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

static void	move_menu(t_vars *vars, int keycode)
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

static void	set_char_stats(t_vars *vars)
{
	if (vars->loading.pos == 1)
		vars->player.has_collisions = 0;
	else if (vars->loading.pos == 2)
		vars->player.speed *= 2;
	else if (vars->loading.pos == 3)
		vars->player.fov = radians(170);
	else if (vars->loading.pos == 4)
		vars->player.hp *= 2;
	vars->player.hp_start = vars->player.hp;
}

int	ft_release_hook(int keycode, t_vars *vars)
{
	if (vars->game_state == 2)
	{
		ft_move(vars, -keycode);
	}
	return (0);
}
