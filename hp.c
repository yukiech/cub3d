#include <cub3d.h>

void	ft_damage(t_vars *vars)
{
	if (ft_get_case(vars, vars->player.pos.x, vars->player.pos.y) == '^')
	{
		vars->player.hp -= 0.5;
		ft_put_image_full(vars, &vars->loading.damage);
	}
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
	}
	else if (vars->player.hp == 0)
	{
		sound_music(vars, "wilheim");
		vars->player.hp = -1;
	}
}
