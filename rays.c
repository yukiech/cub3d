#include <cub3d.h>

static t_ray	*ft_cast_walls(t_vars *vars, t_point end, t_ray *res, int min_id);
static void		ft_copy_ray(t_ray **best, t_ray *copy);
static int		ray(t_wall w, t_point player, t_point r, t_ray *ray);

t_ray	*ft_cast_rays(t_vars *vars, t_point ray_end)
{
	t_ray	*res;
	t_ray	*best;
	int		i;

	i = 0;
	res = malloc(sizeof(t_ray));
	if (res == NULL)
		return (NULL);
	best = ft_cast_walls(vars, ray_end, res, 0);
	free(res);
	return (best);
}

t_ray	*ft_cast_rays_inv(t_vars *vars, t_point ray_end)
{
	t_ray	*res;
	t_ray	*best;
	int		i;

	i = 0;
	res = malloc(sizeof(t_ray));
	if (res == NULL)
		return (NULL);
	best = ft_cast_walls(vars, ray_end, res, -100);
	free(res);
	return (best);
}

static t_ray	*ft_cast_walls(t_vars *vars, t_point end, t_ray *res, int min_id)
{
	int		i;
	t_wall	w;
	t_ray	*best;

	best = NULL;
	i = 0;
	while (vars->map.walls[i].type != W_NONE)
	{
		w = vars->map.walls[i];
		if (w.type > min_id && RENDER_DIST
			> ft_pyta(w.p1.y - vars->player.pos.y, w.p1.x - vars->player.pos.x))
		{
			if (ray(w, vars->player.pos, end, res) == 1)
			{
				if (best == NULL || res->u < best->u)
				{
					res->wall = i;
					ft_copy_ray(&best, res);
				}
			}
		}
		i++;
	}
	return (best);
}

static void	ft_copy_ray(t_ray **best, t_ray *copy)
{
	if (*best == NULL)
		*best = malloc(sizeof(t_ray));
	(*best)->p = copy->p;
	(*best)->wall = copy->wall;
	(*best)->dist = copy->dist;
	(*best)->t = copy->t;
	(*best)->u = copy->u;
}

static int	ray(t_wall w, t_point player, t_point r, t_ray *ray)
{
	float	den;

	den = (w.p1.x - w.p2.x) * (player.y - r.y);
	den = den - (w.p1.y - w.p2.y) * (player.x - r.x);
	if (den == 0)
		return (0);
	ray->t = (w.p1.x - player.x) * (player.y - r.y);
	ray->t = ray->t - (w.p1.y - player.y) * (player.x - r.x);
	ray->t = ray->t / den;
	ray->u = (w.p1.x - w.p2.x) * (w.p1.y - player.y);
	ray->u = ray->u - (w.p1.y - w.p2.y) * (w.p1.x - player.x);
	ray->u = -ray->u / den;
	if (ray->t >= 0 && ray->t <= 1 && ray->u >= 0)
	{
		ray->p.x = w.p1.x + ray->t * (w.p2.x - w.p1.x);
		ray->p.y = w.p1.y + ray->t * (w.p2.y - w.p1.y);
		return (1);
	}
	return (0);
}
