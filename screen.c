#include <cub3d.h>

static t_ray	*ft_cast_rays(t_vars *vars, t_point ray_end);
static void	ft_draw_column(t_vars *vars, t_ray *cast, int col);

void	ft_draw_background(t_vars *vars)
{
	int	i;

	i = 0;
	while(i < vars->player.hori)
	{
		ft_draw_hline(vars, (t_point){.x = 0, .y = i}, vars->screen.w, ft_color(0, 0, 255, 0));
		i++;
	}
	while(i < vars->screen.h)
	{
		ft_draw_hline(vars, (t_point){.x = 0, .y = i}, vars->screen.w, ft_color(0, 0, 0, 255));
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
		ray_angle = map(col, n_vect(0, vars->screen.w), n_vect(vars->player.fov / -2, vars->player.fov / 2));
		ray_end.x = vars->player.pos.x + cos(vars->player.angle + ray_angle) * 10;
		ray_end.y = vars->player.pos.y + sin(vars->player.angle + ray_angle) * 10;
		cast = ft_cast_rays(vars, ray_end);
		if (cast != NULL)
			ft_draw_column(vars, cast, col);
		col++;
	}
}

static t_ray	*ft_cast_rays(t_vars *vars, t_point ray_end)
{
	t_ray	*best;
	t_ray	*res;
	int		i;

	i = 0;
	best = NULL;
	while (vars->map.walls[i].type != W_NONE)
	{
		res = ray(vars->map.walls[i], vars->player.pos, ray_end);
		if (res != NULL)
		{
			res->dist = ft_pyta(res->p.y - vars->player.pos.y, res->p.x - vars->player.pos.x);
			if (best == NULL || res->dist < best->dist)
			{
				res->wall = i;
				ft_tfree(best);
				best = res;
			}
		}
		i++;		
	}
	return (best);
}

static void	ft_draw_column(t_vars *vars, t_ray *cast, int col)
{
	t_imgptr	*side;
	float		h;

//	cast->dist = ft_pyta(best_ray->p.x - playerx, best_ray->p.y - playery);

	if (vars->map.walls[cast->wall].p1.x == vars->map.walls[cast->wall].p2.x)
		cast->dist *= cos(atan2(cast->p.y - vars->player.pos.y, cast->p.x - vars->player.pos.x) - vars->player.angle);
	else
		cast->dist *= cos(atan2(cast->p.y - vars->player.pos.y, cast->p.x - vars->player.pos.x) - vars->player.angle);

	h = map(cast->dist, n_vect(0, 8), n_vect(-50, 400));
//	h = (cast->dist - 0.4) * 50;
	if (vars->map.walls[cast->wall].type == W_UPWALL)
		side = &vars->map.north;
	else if (vars->map.walls[cast->wall].type == W_LEFTWALL)
		side = &vars->map.west;
	else if (vars->map.walls[cast->wall].type == W_RIGHTWALL)
		side = &vars->map.east;
	else
		side = &vars->map.south;
	ft_put_col(vars, side, (t_point){.x = col, .y = h}, cast->t);
	ft_tfree(cast);
}

