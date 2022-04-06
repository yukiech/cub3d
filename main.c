#include <cub3d.h>

int	main(int argc, char **argv)
{
	t_vars	vars;

	ft_bzero(&vars, sizeof(t_vars));
	vars.mlx = mlx_init();
    

	vars.screen.w = 800;
	vars.screen.h = 800;
//	vars.win = mlx_new_window(vars.mlx, 600, 400, vars.screen.w, vars.screen.h, "mlx 42");
	vars.win = mlx_new_window(vars.mlx, vars.screen.w, vars.screen.h, "mlx 42");

	ft_load_image(&vars, NULL, &vars.screen);

	vars.background.w = vars.screen.w;
	vars.background.h = vars.screen.h * 2;
	ft_load_image(&vars, NULL, &vars.background);
	ft_draw_background(&vars);


	if (argc == 2)
		ft_load_map(&vars, argv[1]);
	else
		ft_load_map(&vars, "maps/small.cub");

	vars.map.walls = ft_calloc(ft_count_walls(&vars) + 1, sizeof(t_wall));
	ft_register_walls(&vars);

	vars.player.pos.x = 3.2;
	vars.player.pos.y = 2.3;

	vars.player.angle = radians(-120);
	vars.player.fov = radians(90);
	vars.player.hori = 400;

	ft_load_texter(&vars);


	int	i;
	i = 0;
	while (vars.map.raw[i] != NULL)
	{
		printf("%s\n", vars.map.raw[i]);
		i++;
	}


//	printf("color %d\n", ft_color(0, 0, 0, 255));

//	mlx_mouse_hide();

	ft_time();

	mlx_loop_hook(vars.mlx, ft_loop_hook, &vars);
	mlx_hook(vars.win, 2, 1L << 1, ft_key_hook, &vars);
	mlx_hook(vars.win, 4, 0, ft_click_hook, &vars);
	mlx_hook(vars.win, 6, 1L << 4, ft_mouse_hook, &vars);

	mlx_hook(vars.win, 17, 0L, ft_free, &vars);
	mlx_loop(vars.mlx);
	ft_free(&vars);
}
