#include <cub3d.h>





int	main(int argc, char **argv)
{
	t_vars	vars;
	int	i;

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




//	vars.screen.img = mlx_new_image(vars.mlx, vars.screen.w, vars.screen.h);
//	ft_get_im_data(&vars.screen);


	printf("bits %d\n", vars.screen.bits);
	printf("line %d\n", vars.screen.line);
	printf("end %d\n", vars.screen.end);

//	ft_load_image(&vars, "wall.xpm", &vars.wall);


//	vars.wall.img = mlx_xpm_file_to_image(vars.mlx, "wall.xpm", &vars.wall.w, &vars.wall.h);
//	ft_get_im_data(&vars.wall);

	ft_time();

//	ft_draw_hline(&vars, 400, 400, 100);
//	ft_draw_vline(&vars, 400, 500, 100);

//	ft_put_image(&vars, &vars.wall, (t_point){.x = -10, .y = -70}, (t_point){.x = 250,.y=200});
	ft_put_image(&vars, &vars.map.north, (t_point){.x = 810, .y = -70}, (t_point){.x = 550, .y = 200});


	i = 0;
	while (vars.map.walls[i].type != W_NONE)
	{
		t_wall w;
	
		w = vars.map.walls[i];
		if (vars.map.walls[i].p1.x == vars.map.walls[i].p2.x)
		{
			ft_draw_vline(&vars, (t_point){.x = w.p1.x * 4 + 100, .y = w.p1.y * 4 + 200}, (w.p2.y - w.p1.y) * 4);
		}
		else
		{
			ft_draw_hline(&vars, (t_point){.x = w.p1.x * 4 + 100, .y = w.p1.y * 4 + 200}, (w.p2.x - w.p1.x) * 4);
		}
		i++;
	}



	mlx_put_image_to_window(vars.mlx, vars.win, vars.screen.img, 0, 0);

	ft_time();

	mlx_key_hook(vars.win, ft_hook, &vars);
	mlx_hook(vars.win, 17, 0L, ft_free, &vars);
	mlx_loop(vars.mlx);
	ft_free(&vars);
}
