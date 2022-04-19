#include <cub3d.h>

void	menu_load_image(t_vars *vars)
{	
	ft_load_image(vars, "./assets/menu_loading.xpm", &vars->loading.loading);
	ft_load_image(vars, "./assets/menu_loading2.xpm", &vars->loading.loading2);
	ft_load_image(vars, "./assets/char_ghost.xpm", &vars->loading.ghost);
	ft_load_image(vars, "./assets/char_ninja.xpm", &vars->loading.ninja);
	ft_load_image(vars, "./assets/char_pirate.xpm", &vars->loading.pirate);
	ft_load_image(vars, "./assets/char_franken.xpm", &vars->loading.franken);
}

void	set_char_stats(t_vars *vars)
{
	if (vars->loading.pos == 1)
		vars->player.ghost = 1;
	else if (vars->loading.pos == 2)
		vars->player.mspeed = 0.5;
	else if (vars->loading.pos == 3)
		vars->player.fov = radians(170);
	else if (vars->loading.pos == 4)
		vars->player.hp = 2000;
}

void	loading_screen(t_vars *vars, int i)
{
	if (i == 0)
	{
		if (vars->loading.i % 100 > 90)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.loading.img, 0, 0);
		else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.loading2.img, 0, 0);
	vars->loading.i += 1;
	}
	else if (i == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.ghost.img, 0, 0);
	else if (i == 2)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.ninja.img, 0, 0);
	else if (i == 3)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.pirate.img, 0, 0);
	else if (i == 4)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.franken.img, 0, 0);
	return;
}
