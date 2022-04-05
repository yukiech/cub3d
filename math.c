#include <cub3d.h>

int	ft_time(void)
{
	struct timeval	time;
	static int		last;
	size_t			micro;
	size_t			res;

	gettimeofday(&time, NULL);
	micro = time.tv_sec * 10000000 + time.tv_usec;
//	printf("t %zu\n", micro);
//	printf("tu %zu %d\n", time.tv_sec, time.tv_usec);
	res = micro - last;
	last = micro;
	return (res);
}

t_vect	*n_vect(float v1, float v2)
{
	t_vect	*vect;

	vect = malloc(sizeof(vect));
	vect->v1 = v1;
	vect->v2 = v2;
	return (vect);
}

float	map(float x, t_vect *in, t_vect *out)
{
	float	res;

	res = ((x - in->v1) * (out->v2 - out->v1) / (in->v2 - in->v1) + out->v1);
	free(in);
	free(out);
	return (res);
}

int	ft_color(unsigned char a, unsigned char r, unsigned char g, unsigned char b)
{
	int	res;

	res = a;
	res = (res << 8) + r;
	res = (res << 8) + g;
	res = (res << 8) + b;
	return (res);
}

char	ft_get_case(t_vars *vars, int x, int y)
{
	if (y < 0)
		return (0);
	if (vars->map.raw[y] == NULL)
		return (0);
	if (x < 0)
		return (0);
	if (x > (int)ft_strlen(vars->map.raw[y]))
		return (0);
	return (vars->map.raw[y][x]);
}

float	ft_pyta(float a, float b)
{
	return (sqrtf(powf(a, 2) + powf(b, 2)));
}

float	radians(float deg)
{
	return (deg * M_PI / 180);
}

float	degrees(float rad)
{
	return (rad / (M_PI / 180));
}
