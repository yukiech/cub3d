#include <cub3d.h>

void	menu_load_image(t_vars *vars)
{	
	ft_load_image(vars, "./assets/menu_1.xpm", &vars->loading.menu_1);
	ft_load_image(vars, "./assets/menu_2.xpm", &vars->loading.menu_2);
	ft_load_image(vars, "./assets/menu_3.xpm", &vars->loading.menu_3);
	ft_load_image(vars, "./assets/menu_4.xpm", &vars->loading.menu_4);
	ft_load_image(vars, "./assets/char_ghost.xpm", &vars->loading.ghost);
	ft_load_image(vars, "./assets/char_ninja.xpm", &vars->loading.ninja);
	ft_load_image(vars, "./assets/char_pirate.xpm", &vars->loading.pirate);
	ft_load_image(vars, "./assets/char_franken.xpm", &vars->loading.franken);
	ft_load_image(vars, "./assets/sound_on.xpm", &vars->loading.sound_on);
	ft_load_image(vars, "./assets/sound_off.xpm", &vars->loading.sound_off);
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
		if (vars->loading.i % 100 < 18)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.menu_1.img, 0, 0);
		else if (vars->loading.i % 100 > 17 && vars->loading.i % 100 < 35)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.menu_2.img, 0, 0);
		else if (vars->loading.i % 100 > 34 && vars->loading.i % 100 < 52)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.menu_3.img, 0, 0);
		else if (vars->loading.i % 100 > 51 && vars->loading.i % 100 < 69)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.menu_4.img, 0, 0);
		else if (vars->loading.i % 100 > 68 && vars->loading.i % 100 < 86)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.menu_3.img, 0, 0);
		else if (vars->loading.i % 100 > 85)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.menu_2.img, 0, 0);
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
	if (vars->loading.sound == 0 && vars->game_state == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.sound_off.img, 720, 30);
	else if (vars->loading.sound == 1 && vars->game_state == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.sound_on.img, 720, 30);
	return;
}

void	load_music_title(t_vars *vars, char *map)
{
	if (ft_strcmp(map, "maps/bocal.cub") == 0)
	{
		vars->loading.music_title = malloc(sizeof(char) * ft_strlen("imperial"));
		vars->loading.music_title = "imperial";
	}
	else
	{
		vars->loading.music_title = malloc(sizeof(char) * ft_strlen("nyancat"));
		vars->loading.music_title = "nyancat";
	}
}
