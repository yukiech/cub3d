#include <cub3d.h>

//int is in fov

t_ray	*ray(t_wall w, t_point player, t_point r)
{
	t_ray	*ray;
	float	den;

	den = (w.p1.x - w.p2.x) * (player.y - r.y) - (w.p1.y - w.p2.y) * (player.x - r.x);
	if (den == 0)
		return (NULL);
	ray = malloc(sizeof(t_ray));
	if (ray == NULL)
		return (NULL);
	ray->t = ((w.p1.x - player.x) * (player.y - r.y) - (w.p1.y - player.y) * (player.x - r.x)) / den;
	ray->u = -((w.p1.x - w.p2.x) * (w.p1.y - player.y) - (w.p1.y - w.p2.y) * (w.p1.x - player.x)) / den;
	if (ray->t >= 0 && ray->t <= 1 && ray->u >= 0)
	{
		ray->p.x = w.p1.x + ray->t * (w.p2.x - w.p1.x);
		ray->p.y = w.p1.y + ray->t * (w.p2.y - w.p1.y);
		return (ray);
	}
	free(ray);
	return (NULL);
}

/*
int	ft_in_fov(float angle, float playerangle, float fov)
{
	if (fabsf(playerangle - angle) < fov / 2)
	{
		return (1);
	}
	else if (angle < playerangle)
	{
		return (360 + angle > playerangle - fov / 2 && 360 + angle < playerangle + fov / 2);
	}
	else if (angle > playerangle)
	{
		return (angle > playerangle - fov / 2 + 360 && angle < playerangle + fov / 2 + 360);
	}
	else
	{
		return (0);
	}

}

int	ft_fov_dist(float angle, float playerangle, float fov)
{
	if (fabsf(playerangle - angle) < fov / 2)
	{
		return (angle - playerangle);
	}
	else if (angle < playerangle)
	{
		return (360 + angle - playerangle);
		return (360 + angle > playerangle - fov / 2 && 360 + angle < playerangle + fov / 2);
	}
	else if (angle > playerangle)
	{
		return (angle - playerangle + 360);
		return (angle > playerangle - fov / 2 + 360 && angle < playerangle + fov / 2 + 360);
	}
	else
	{
		return (0);
	}

}


*/