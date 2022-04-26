/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:49:17 by jjaqueme          #+#    #+#             */
/*   Updated: 2022/04/26 13:49:17 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	ft_draw_column(t_vars *vars, t_ray *cast, int col);
static void	ft_draw_column_inv(t_vars *vars, t_ray *cast, int col);

void	ft_draw_background(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->player.hori)
	{
		ft_draw_hline(&vars->screen, (t_point){.x = 0, .y = i},
			vars->screen.w, vars->map.ceil.color);
		i++;
	}
	while (i < vars->screen.h)
	{
		ft_draw_hline(&vars->screen, (t_point){.x = 0, .y = i},
			vars->screen.w, vars->map.floor.color);
		i++;
	}
}

void	ft_draw_walls(t_vars *vars)
{
	int		col;
	float	ray_angle;
	t_point	ray_end;
	t_ray	*cast;

	col = 0;
	while (col < vars->screen.w)
	{
		ray_angle = map(col, (t_vect){0, vars->screen.w},
				(t_vect){vars->player.fov / -2, vars->player.fov / 2});
		ray_end.x = vars->player.pos.x;
		ray_end.x += cos(vars->player.angle + ray_angle) * 10;
		ray_end.y = vars->player.pos.y;
		ray_end.y += sin(vars->player.angle + ray_angle) * 10;
		cast = ft_cast_rays(vars, ray_end);
		if (cast != NULL)
			ft_draw_column(vars, cast, col);
		cast = NULL;
		cast = ft_cast_rays_inv(vars, ray_end);
		if (cast != NULL)
			ft_draw_column_inv(vars, cast, col);
		col += 1;
	}
}

static t_imgptr	*ft_switch_texture(t_vars *vars, int wall)
{
	if (vars->map.walls[wall].type == W_UPWALL)
		return (&vars->map.north);
	else if (vars->map.walls[wall].type == W_LEFTWALL)
		return (&vars->map.west);
	else if (vars->map.walls[wall].type == W_RIGHTWALL)
		return (&vars->map.east);
	else if (vars->map.walls[wall].type == W_DOWNWALL)
		return (&vars->map.south);
	else if (vars->map.walls[wall].type == W_DOOR)
		return (&vars->door);
	else if (vars->map.walls[wall].type == W_FINISH)
		return (&vars->portal);
	else if (vars->map.walls[wall].type == W_FIRE)
		return (&vars->fire[(int)(vars->frame / 6) % 10]);
	else
		return (NULL);
}

static void	ft_draw_column(t_vars *vars, t_ray *cast, int col)
{
	t_imgptr	*side;
	float		h;
	float		disto;
	t_player	play;

	play = vars->player;
	cast->dist = ft_pyta(cast->p.y - play.pos.y, cast->p.x - play.pos.x);
	cast->dist *= cos(atan2(cast->p.y - play.pos.y, cast->p.x - play.pos.x)
			- play.angle);
	disto = MAGIC_NBR / 2.0 / tan(play.fov / 2.0);
	h = (MAGIC_NBR / cast->dist) * disto;
	side = ft_switch_texture(vars, cast->wall);
	if (side != NULL)
		ft_put_col(vars, side, (t_point){.x = col, .y = h}, cast->t);
	ft_tfree((void **)&cast);
}

static void	ft_draw_column_inv(t_vars *vars, t_ray *cast, int col)
{
	t_imgptr	*side;
	float		h;
	float		disto;
	t_player	play;

	play = vars->player;
	cast->dist = ft_pyta(cast->p.y - play.pos.y, cast->p.x - play.pos.x);
	cast->dist *= cos(atan2(cast->p.y - play.pos.y, cast->p.x - play.pos.x)
			- play.angle);
	disto = MAGIC_NBR / 2.0 / tan(play.fov / 2.0);
	h = (MAGIC_NBR / cast->dist) * disto;
	side = ft_switch_texture(vars, cast->wall);
	if (side != NULL)
		ft_put_col(vars, side, (t_point){.x = col, .y = h}, cast->t);
	ft_tfree((void **)&cast);
}
