/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:49:16 by jjaqueme          #+#    #+#             */
/*   Updated: 2022/04/26 14:10:37 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_init_vars(t_vars *vars)
{
	ft_bzero(vars, sizeof(t_vars));

	vars->player.fov = radians(60);
	vars->player.hori = 400;
	vars->player.hp = 1000;
	vars->player.speed = 0.02;
	vars->player.speed_mod = 0;
	vars->player.has_collisions = 1;
	vars->player.has_sound = 1;
	vars->player.on_fire = 0;

	vars->game_state = 0;
	vars->loading.pos = 2;
	vars->frame = 0;
	vars->pistol.frame = 100;

	vars->mlx = mlx_init();

	vars->screen.w = WINDOW_WIDTH;
	vars->screen.h = WINDOW_HEIGHT;
	vars->win = mlx_new_window(vars->mlx, vars->screen.w, vars->screen.h, "Cub3d");
	ft_load_image(vars, NULL, &vars->screen);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	char	*filename;

	ft_init_vars(&vars);

	if (argc == 2)
		filename = ft_strdup(argv[1]);
	else
		filename = ft_strdup("maps/small.cub");

	ft_open_map(&vars, &filename);
	ft_process_map(&vars);
	ft_register_walls(&vars);

	
	menu_load_image(&vars);
	ft_load_texter(&vars);


	mlx_loop_hook(vars.mlx, ft_loop_hook, &vars);
	mlx_hook(vars.win, 2, 1L << 1, ft_key_hook, &vars);
	mlx_hook(vars.win, 3, 1L << 1, ft_release_hook, &vars);
	mlx_hook(vars.win, 4, 0, ft_click_hook, &vars);
	mlx_hook(vars.win, 6, 1L << 4, ft_mouse_hook, &vars);
	mlx_hook(vars.win, 17, 0L, ft_free_all, &vars);
	mlx_loop(vars.mlx);
	ft_free_all(&vars);
}
