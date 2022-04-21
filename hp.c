#include <cub3d.h>

void		ft_damage(t_vars *vars)
{
//	if (vars->map.raw[(int)vars->player.pos.y][(int)vars->player.pos.x] == '^')
		vars->player.hp -= 1;
}

void	ft_hp_draw(t_vars *vars)
{
	ft_damage(vars);
	if (vars->player.hp > 0)
	{
		if (vars->player.hp * 100 / vars->player.hp_start > 0 )
			mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.heart_half.img, 600, 30);
		if (vars->player.hp * 100 / vars->player.hp_start > 12)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.heart.img, 600, 30);
		if (vars->player.hp * 100 / vars->player.hp_start > 25)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.heart_half.img, 640, 30);
		if (vars->player.hp * 100 / vars->player.hp_start > 37)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.heart.img, 640, 30);
		if (vars->player.hp * 100 / vars->player.hp_start > 50)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.heart_half.img, 680, 30);
		if (vars->player.hp * 100 / vars->player.hp_start > 62)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.heart.img, 680, 30);
		if (vars->player.hp * 100 / vars->player.hp_start > 75)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.heart_half.img, 720, 30);
		if (vars->player.hp * 100 / vars->player.hp_start > 87)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.heart.img, 720, 30);
//		mlx_string_put(vars->mlx, vars->win, 600, 30, 0x000000, "HP : ");
//		mlx_string_put(vars->mlx, vars->win, 650, 30, 0x000000, ft_itoa(vars->player.hp));
	}
}
