#include <cub3d.h>


//segment angle

//int is in fov

t_ray	*ray(t_vars *vars, t_point p, t_wall other, float playerx, float playery)
{
	t_ray	*ray;
	float den;

	(void)vars;

	den = (playerx - p.x) * (other.p1.y - other.p2.y) - (playery - p.y) * (other.p1.x - other.p2.x);
	if (den == 0)
		return (NULL);

	ray = malloc(sizeof(t_ray));
	if (ray == NULL)
		return (NULL);

	ray->u = ((playerx - other.p1.x) * (other.p1.y - other.p2.y) - (playery - other.p1.y) * (other.p1.x - other.p2.x)) / den * 100;
	ray->t = -((playerx - p.x) * (playery - other.p1.y) - (playery - p.y) * (playerx - other.p1.x)) / den;


	if (ray->t >= 0 && ray->t <= 1 && ray->u >= 0)
	{
		ray->p.x = playerx + ray->t * (p.x - playerx);
		ray->p.y = playery + ray->t * (p.y - playery);
		return (ray);
	}

	free(ray);
	return (NULL);
}


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


