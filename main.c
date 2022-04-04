#include <cub3d.h>


float	ft_moy(float a, float b)
{
	return ((a + b) / 2);
}

float	ft_pyta(float a, float b)
{
	return (sqrtf(powf(a, 2) + powf(b, 2)));
}

t_ray	*ray(t_vars *vars, t_point p, t_wall other, float playerx, float playery);
int		ft_in_fov(float angle, float playerangle, float fov);
int	ft_fov_dist(float angle, float playerangle, float fov);

int	ft_put_col(t_vars *vars, t_imgptr *img, t_point o1, float ratio, int hori);


float	ft_to_rad(float deg)
{
	return ((fmod(deg + 360, 360) - 180) * M_PI / 180);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		i;

	ft_bzero(&vars, sizeof(t_vars));

	vars.mlx = mlx_init();
    
	vars.screen.w = 800;
	vars.screen.h = 800;
	vars.win = mlx_new_window(vars.mlx, vars.screen.w, vars.screen.h, "mlx 42");

	ft_load_image(&vars, NULL, &vars.screen);

	if (argc == 2)
		ft_load_map(&vars, argv[1]);
	else
		ft_load_map(&vars, "maps/little.cub");


	printf("\nSTART MAP\n\n");

	vars.map.walls = ft_calloc(ft_count_walls(&vars) + 1, sizeof(t_wall));

	printf("\nEND MAP %d\n\n", ft_count_walls(&vars) + 1);

	ft_register_walls(&vars);
	

	printf("bits %d\n", vars.screen.bits);
	printf("line %d\n", vars.screen.line);
	printf("end %d\n", vars.screen.end);

//	ft_load_image(&vars, "wall.xpm", &vars.wall);



	ft_time();

	for(int h = 0; h < 400; h++)
		ft_draw_hline(&vars, (t_point){.x = 0, .y = h}, 800, ft_color(0, 0, 255, 0));

	for(int h = 400; h < 800; h++)
		ft_draw_hline(&vars, (t_point){.x = 0, .y = h}, 800, ft_color(0, 0, 0, 255));

//	ft_draw_vline(&vars, 400, 500, 100);

//	ft_put_image(&vars, &vars.map.north, (t_point){.x = -10, .y = -70}, (t_point){.x = 550, .y = 190}, 200);
//	ft_put_image(&vars, &vars.map.north, (t_point){.x = 810, .y = -70}, (t_point){.x = 550, .y = 190}, 200);


	float playerx = 24.5;
	float playery = 20.5;
	(void)playerx;
	(void)playery;

	float angle = 90;
	(void)angle;
	float fov = 90;
	(void)fov;

	t_wall w;
	(void)w;

	int	j;
	(void)j;


	int	px;


	px = 0;
	while (px < 800)
	{
		float rayan;

		rayan = map(px, n_vect(0, 800), n_vect(fov/-2, fov/2));

		float	best_dist = 1000000000;
		t_ray	*best_ray;
		int		best_wall;
	
		best_wall = 0;
		t_point	raypoint;

//		printf("%d %f\n", px, fmod(rayan + angle + 360, 360));
		raypoint.x = playerx + cos((fmod(rayan + angle + 360, 360) - 180) * M_PI / 180) * 50;
		raypoint.y = playerx + sin((fmod(rayan + angle + 360, 360) - 180) * M_PI / 180) * 50;


		best_ray = NULL;

		i = 0;
		while (vars.map.walls[i].type != W_NONE)
		{
			t_wall w;
		
			w = vars.map.walls[i];

			t_ray *r = ray(&vars, raypoint, w, playerx, playery);

			
			if (r == NULL)
			{
				i++;
				continue;
			}

			if (r->u < best_dist)
			{
				best_dist = r->u;
				best_wall = i;
				ft_tfree(best_ray);
				best_ray = r;
			}
			i++;
		}


		if (best_ray != NULL)
		{
//			printf("aa px %d %d, dist %f,\t tap %f            %f   %f\n", px, best_wall, best_dist, best_ray->t,   best_dist * sin(ft_to_rad(rayan + angle)), best_dist * cos(ft_to_rad(rayan + angle)));

			if (vars.map.walls[best_wall].p1.x == vars.map.walls[best_wall].p2.x)
			{
				ft_put_col(&vars, &vars.map.west, (t_point){.x = px, .y = map(fabs(best_dist * cos(ft_to_rad(rayan + angle))), n_vect(0, 30), n_vect(100, 400))}, best_ray->t, 400);
			}
			else
			{
				ft_put_col(&vars, &vars.map.north, (t_point){.x = px, .y = map(fabs(cos(ft_to_rad(rayan + angle)) * best_dist), n_vect(0, 30), n_vect(100, 400))}, best_ray->t, 400);
			}



		}

		ft_tfree(best_ray);		

		px++;
	}


	ft_load_texter(&vars);
//	ft_write_text(&vars, "Canard$", (t_point){.x = 50, .y = 100}, n_vect(10, ft_color(0, 255, 255, 0)));


//	ft_line(&vars, (t_point){.x = 50, .y = 100}, (t_point){.x = 100, .y = 500});


	mlx_put_image_to_window(vars.mlx, vars.win, vars.screen.img, 0, 0);

	ft_time();

	printf("color %d\n", ft_color(0, 0, 0, 255));
	printf("color %d\n", ft_color(0, 255, 255, 0));

//	mlx_hook(vars.win, 2, 0L, ft_hook, &vars);
	
//	mlx_mouse_hide();
	mlx_hook(vars.win, 2, 1L << 1, ft_key_hook, &vars);
	mlx_hook(vars.win, 4, 0, ft_click_hook, &vars);
	mlx_hook(vars.win, 6, 1L << 4, ft_mouse_hook, &vars);

	mlx_hook(vars.win, 17, 0L, ft_free, &vars);
	mlx_loop(vars.mlx);
	ft_free(&vars);
}
