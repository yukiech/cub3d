/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:49:16 by jjaqueme          #+#    #+#             */
/*   Updated: 2022/04/26 14:27:59 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	loading_screen(t_vars *vars);
static void	menu_screen(t_vars *vars);
static void	ft_loop_game_hook(t_vars *vars);
static void	ft_win_screen(t_vars *vars);

int	ft_loop_hook(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	if (vars->game_state == 0)
		loading_screen(vars);
	else if (vars->game_state == 1)
		menu_screen(vars);
	else if (vars->game_state == 2)
		ft_loop_game_hook(vars);
	else if (vars->game_state == 3)
		ft_win_screen(vars);
	//ft_damage(vars);
	//if (vars->game_state == 2)
	//	ft_hp_draw(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->screen.img, 0, 0);
	vars->frame = (vars->frame + 1) % 1000000000;
	return (0);
}

#define LOADING_LEN 100

static void	loading_screen(t_vars *vars)
{
	if (vars->frame % LOADING_LEN < ((LOADING_LEN / 6) * 1))
		ft_put_image_full(vars, &vars->loading.menu_1);
	else if (vars->frame % LOADING_LEN < ((LOADING_LEN / 6) * 2))
		ft_put_image_full(vars, &vars->loading.menu_2);
	else if (vars->frame % LOADING_LEN < ((LOADING_LEN / 6) * 3))
		ft_put_image_full(vars, &vars->loading.menu_3);
	else if (vars->frame % LOADING_LEN < ((LOADING_LEN / 6) * 4))
		ft_put_image_full(vars, &vars->loading.menu_4);
	else if (vars->frame % LOADING_LEN < ((LOADING_LEN / 6) * 5))
		ft_put_image_full(vars, &vars->loading.menu_3);
	else
		ft_put_image_full(vars, &vars->loading.menu_2);
}

static void	menu_screen(t_vars *vars)
{
	if (vars->loading.pos == 1)
		ft_put_image_full(vars, &vars->loading.ghost);
	else if (vars->loading.pos == 2)
		ft_put_image_full(vars, &vars->loading.ninja);
	else if (vars->loading.pos == 3)
		ft_put_image_full(vars, &vars->loading.pirate);
	else if (vars->loading.pos == 4)
		ft_put_image_full(vars, &vars->loading.franken);
	if (vars->player.has_sound == 0 && vars->game_state == 1)
		ft_put_image(vars, &vars->loading.sound_off,
			(t_point){720, 30}, (t_point){770, 80});
	else if (vars->player.has_sound == 1 && vars->game_state == 1)
		ft_put_image(vars, &vars->loading.sound_on,
			(t_point){720, 30}, (t_point){770, 80});
}

static void	ft_loop_game_hook(t_vars *vars)
{	
	char	*tmp;

	ft_draw_background(vars);
	ft_draw_walls(vars);
	minimap_draw(vars);
	pistol_fire(vars);
	ft_draw_cross(vars);
	ft_put_image(vars, &vars->score, (t_point){vars->screen.w - 140, 10},
		(t_point){vars->screen.w - 10, 50});
	ft_write_text(vars, "Niveau: ", (t_point){vars->screen.w - 125, 20},
		(t_vect){1, 0x00FF00});
	tmp = ft_itoa(vars->level);
	ft_write_text(vars, tmp, (t_point){vars->screen.w - 50, 20},
		(t_vect){1, 0x00FF00});
	free(tmp);
}

static void	ft_win_screen(t_vars *vars)
{
	if (vars->player.hp > 0)
		ft_put_image_full(vars, &vars->loading.gameover);
	else
		ft_put_image_full(vars, &vars->loading.gameover);
}