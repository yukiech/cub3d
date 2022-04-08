#include <cub3d.h>

void		ft_damage(t_vars *vars)
{
	if (vars->map.raw[(int)vars->player.pos.y][(int)vars->player.pos.x] == '^')
		vars->player.hp -= 1;
}

void	ft_hp_draw(t_vars *vars)
{
	ft_damage(vars);
	mlx_string_put(vars->mlx, vars->win, 600, 30, 0x000000, "HP : ");
	mlx_string_put(vars->mlx, vars->win, 650, 30, 0x000000, ft_itoa(vars->player.hp));
}
