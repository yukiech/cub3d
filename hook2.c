/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:49:16 by jjaqueme          #+#    #+#             */
/*   Updated: 2022/04/26 14:27:58 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
