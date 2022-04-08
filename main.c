#include <cub3d.h>

void	ft_init_player(t_vars *vars, int x, int y)
{
	if (ft_strchr("NWES", vars->map.raw[y][x]))
	{
		if (vars->player.pos.x != -1)
			ft_exit(vars, "2 players found, multiplayer to be defined");
		vars->player.pos.x = x + 0.5;
		vars->player.pos.y = y + 0.5;

		if (vars->map.raw[y][x] == 'N')
			vars->player.angle = radians(-90);
		else if (vars->map.raw[y][x] == 'W')
			vars->player.angle = radians(180);
		else if (vars->map.raw[y][x] == 'E')
			vars->player.angle = radians(0);
		else if (vars->map.raw[y][x] == 'S')
			vars->player.angle = radians(90);
		vars->map.raw[y][x] = '0';
	}	
}

void	ft_load_player(t_vars *vars)
{
	int	i;
	int	j;

	vars->player.fov = radians(90);
	vars->player.hori = 400;
	vars->player.pos.x = -1;
	i = 0;
	while (vars->map.raw[i] != NULL)
	{
		j = 0;
		while (vars->map.raw[i][j] != '\0')
		{
			ft_init_player(vars, j, i);
			j++;
		}
		i++;
	}
}

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

	ft_load_player(&vars);

	vars.map.walls = ft_calloc(ft_count_walls(&vars) + 1, sizeof(t_wall));
	ft_register_walls(&vars);

	ft_load_texter(&vars);

/*
	int	i;
	i = 0;
	while (vars.map.raw[i] != NULL)
	{
		printf("%s\n", vars.map.raw[i]);
		i++;
	}
*/

//	printf("color %d\n", ft_color(0, 0, 0, 255));

	mlx_mouse_hide();
	mlx_mouse_move(vars.win, vars.screen.w / 2, vars.screen.h / 2);

	ft_time();

	mlx_loop_hook(vars.mlx, ft_loop_hook, &vars);
	mlx_hook(vars.win, 2, 1L << 1, ft_key_hook, &vars);
	mlx_hook(vars.win, 4, 0, ft_click_hook, &vars);
	mlx_hook(vars.win, 6, 1L << 4, ft_mouse_hook, &vars);

	mlx_hook(vars.win, 17, 0L, ft_free, &vars);
	mlx_loop(vars.mlx);
	ft_free(&vars);
}
