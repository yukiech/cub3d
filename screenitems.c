#include <cub3d.h>

void	ft_draw_items(t_vars *vars)
{
	int		i;
	t_ray	*cast;

	i = 0;
	while (vars->map.items[i].type != 0)
	{
//		float angle = floor(vars->player.angle / M_PI) * M_PI;


		float aaa = atan2(vars->map.items[i].p.y - vars->player.pos.y, vars->map.items[i].p.x - vars->player.pos.x);

		float	view = -1;


		float low = vars->player.angle - vars->player.fov/2;
		float up = vars->player.angle + vars->player.fov/2;

		if (up > M_PI)
			up -= 2*M_PI;
		if (low < -M_PI)
			up += 2*M_PI;


		if (low < up && aaa > low && aaa < up)
		{
			printf("aaaaaaa\n ");
		}
		if (low > up && (aaa > low || aaa < up))
		{
			printf("bbbbbbbb\n ");
		}
		



		printf ("%f  \n", vars->player.angle);
//		printf ("%f   %f  %f\n", aaa, vars->player.angle - vars->player.fov/2, vars->player.angle + vars->player.fov/2);

		if (aaa > vars->player.angle - vars->player.fov/2 && aaa < vars->player.angle + vars->player.fov/2)
		{
			view = map(aaa, (t_vect){vars->player.angle - vars->player.fov/2, vars->player.angle + vars->player.fov/2}, (t_vect){0, 800});
		}
		else if (aaa > vars->player.angle + M_PI - vars->player.fov/2 && aaa < vars->player.angle + M_PI + vars->player.fov/2)
		{
			view = map(aaa, (t_vect){vars->player.angle + M_PI - vars->player.fov/2, vars->player.angle + M_PI + vars->player.fov/2}, (t_vect){0, 800});
		}
/*		else if (aaa > vars->player.angle - M_PI - vars->player.fov/2 && aaa < vars->player.angle - M_PI + vars->player.fov/2)
		{
			view = map(aaa, (t_vect){vars->player.angle - M_PI - vars->player.fov/2, vars->player.angle - M_PI + vars->player.fov/2}, (t_vect){0, 800});
		}*/

		
//		if (view != -1)
//			printf("aaaaaa %f   %f  %f                %f %f\n", view, vars->player.angle, angle, aaa, aaa + angle);
		cast = ft_cast_rays(vars, vars->map.items[i].p);
		if (cast != NULL && cast->u)
		{
			ft_put_image(vars, vars->map.door, (t_point){.x = 100, .y = 100}, (t_point){.x = , .y = 100}, vars->player.hori);
//			ft_draw_item(vars, cast, col, 1);
		}
		i++;
	}
}

