#include <cub3d.h>

int	dont_move(t_vars *vars)
{
	float	step = 0.2;
	if (vars->player.pos.x < 0.21 || vars->player.pos.y < 0.21)
		return(0);
	if(vars->map.raw[(int)(vars->player.pos.x + cos(vars->player.angle) * step)][(int)(vars->player.pos.y + sin(vars->player.angle) * step)] == 1)
		{
			return(0);
		}
	return (1);
}
