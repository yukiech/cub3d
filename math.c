#include <cub3d.h>

/*
int	ft_time(void)
{
	struct timeval	time;
	static int		last;
	size_t			micro;
	size_t			res;

	gettimeofday(&time, NULL);
	micro = time.tv_usec;
//	printf("t %zu\n", micro);
//	printf("tu %zu %d\n", time.tv_sec, time.tv_usec);



//	printf("tu %d\n", time.tv_usec);
	res = micro - last;
	last = micro;

	printf("tu %zu %d     %zu\n", time.tv_sec % 1000, time.tv_usec, res);
	return (res);
}
*/

int	bsp(t_point p, t_point l1, t_point l2)
{
	float	res;

	res = (p.x - l2.x) * (l1.y - l2.y) - (p.y - l2.y) * (l1.x - l2.x);
	if (res < 0)
		return (-1);
	else if (res > 0)
		return (1);
	return (0);
}

float	map(float x, t_vect in, t_vect out)
{
	float	res;

	res = ((x - in.v1) * (out.v2 - out.v1) / (in.v2 - in.v1) + out.v1);
	return (res);
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
