/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:49:16 by jjaqueme          #+#    #+#             */
/*   Updated: 2022/04/26 14:08:42 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

#define PISTOL_SPEED 6

void	ft_loop_hook_two(t_vars *vars)
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

int	ft_loop_hook(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	if (vars->game_state == 0)
		loading_screen(vars);
	else if (vars->game_state == 1)
		menu_screen(vars);
	else if (vars->game_state == 2)
	{
		ft_loop_hook_two(vars);
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
