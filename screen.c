#include <cub3d.h>

t_ray			*ft_cast_rays(t_vars *vars, t_point ray_end);
static void		ft_draw_column(t_vars *vars, t_ray *cast, int col, int mult);

void	ft_draw_background(t_vars *vars)
{
	int	i;
/*
	printf("   In back 1 \t\t"); ft_time();

	i = 0;
	while(i < vars->player.hori)
	{
		ft_set_px(&vars->imgbuff, 0, i, vars->map.ceil.color);
		i++;
	}
	while(i < vars->screen.h)
	{
		ft_set_px(&vars->imgbuff, 0, i, vars->map.floor.color);
		i++;
	}

	printf("   In back 2 \t\t"); ft_time();


	i = 0;
	while (i < vars->screen.w)
	{
	//	mlx_put_image_to_window(vars->mlx, vars->win, vars->background.img, 0, vars->player.hori - vars->screen.h);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgbuff.img, i, 0);
		i++;
	}

	printf("   In back 3 \t\t"); ft_time();
*/

/*
	i = 0;
	while(i < vars->screen.h)
	{
		ft_draw_hline(&vars->background, (t_point){.x = 0, .y = i}, vars->background.w, vars->map.ceil.color);
		i++;
	}
	while(i < vars->screen.h * 2)
	{
		ft_draw_hline(&vars->background, (t_point){.x = 0, .y = i}, vars->background.w, vars->map.floor.color);
		i++;
	}
*/



	i = 0;
	while(i < vars->player.hori)
	{
		ft_draw_hline(&vars->screen, (t_point){.x = 0, .y = i}, vars->screen.w, vars->map.ceil.color);
		i++;
	}
	while(i < vars->screen.h)
	{
		ft_draw_hline(&vars->screen, (t_point){.x = 0, .y = i}, vars->screen.w, vars->map.floor.color);
		i++;
	}

}

void	ft_clear_walls(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->screen.h)
	{
		j = 0;
		while (j < vars->screen.w)
		{
			ft_set_px(&vars->screen, j, i, ft_color(255, 0, 0, 0));
			j++;
		}
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
		ray_angle = map(col, (t_vect){0, vars->screen.w}, (t_vect){.v1 = vars->player.fov / -2, .v2 = vars->player.fov / 2});
		ray_end.x = vars->player.pos.x + cos(vars->player.angle + ray_angle) * 10;
		ray_end.y = vars->player.pos.y + sin(vars->player.angle + ray_angle) * 10;
		cast = ft_cast_rays(vars, ray_end);
		if (cast != NULL)
			ft_draw_column(vars, cast, col, 1);
		col+=1;
	}
}

t_ray	*ft_cast_rays(t_vars *vars, t_point ray_end)
{
	t_ray	*best;
	t_ray	*res;
	int		i;

	i = 0;
	best = NULL;
	while (vars->map.walls[i].type != W_NONE)
	{
		if (ft_pyta(vars->map.walls[i].p1.y - vars->player.pos.y, vars->map.walls[i].p1.x - vars->player.pos.x) < RENDER_DIST)
		{
			res = ray(vars->map.walls[i], vars->player.pos, ray_end);

			if (res != NULL)
			{
	//			res->dist = ft_pyta(res->p.y - vars->player.pos.y, res->p.x - vars->player.pos.x);
				if (best == NULL || res->u < best->u)
				{
					res->wall = i;
					ft_tfree(best);
					best = res;
				}
			}
		}
		i++;		
	}
	return (best);
}

static void	ft_draw_column(t_vars *vars, t_ray *cast, int col, int mult)
{
	t_imgptr	*side;
	float		h;

	cast->dist = ft_pyta(cast->p.y - vars->player.pos.y, cast->p.x - vars->player.pos.x);
	cast->dist *= cos(atan2(cast->p.y - vars->player.pos.y, cast->p.x - vars->player.pos.x) - vars->player.angle);

	float disto = MAGIC_NBR / 2.0 / tan(vars->player.fov / 2.0);
	h = (MAGIC_NBR / cast->dist) * disto;

	if (vars->map.walls[cast->wall].type == W_UPWALL)
		side = &vars->map.north;
	else if (vars->map.walls[cast->wall].type == W_LEFTWALL)
		side = &vars->map.west;
	else if (vars->map.walls[cast->wall].type == W_RIGHTWALL)
		side = &vars->map.east;
	else if (vars->map.walls[cast->wall].type == W_RIGHTWALL)
		side = &vars->map.south;
	else if (vars->map.walls[cast->wall].type == W_DOOR)
		side = &vars->map.door;		
	else
		side = &vars->map.north;
	while (mult-- > 0)
		ft_put_col(vars, side, (t_point){.x = col - mult, .y = h}, cast->t);
	ft_tfree(cast);
}

