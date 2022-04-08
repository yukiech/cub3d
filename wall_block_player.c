#include <cub3d.h>

void	ft_ws(t_vars *vars, int keycode, float step)
{
    if (keycode == K_W) //W
    {
         if (vars->map.raw[(int)(vars->player.pos.y)][(int)(vars->player.pos.x + cos(vars->player.angle) * step)] == 48)
			 vars->player.pos.x += cos(vars->player.angle) * step;
         if (vars->map.raw[(int)(vars->player.pos.y + sin(vars->player.angle) * step)][(int)(vars->player.pos.x)] == 48)
            vars->player.pos.y += sin(vars->player.angle) * step;
    }
    else if (keycode == K_S) //S
    {
         if (vars->map.raw[(int)(vars->player.pos.y)][(int)(vars->player.pos.x - cos(vars->player.angle) * step)] == 48)
        vars->player.pos.x -= cos(vars->player.angle) * step;
         if (vars->map.raw[(int)(vars->player.pos.y - sin(vars->player.angle) * step)][(int)(vars->player.pos.x)] == 48)
        vars->player.pos.y -= sin(vars->player.angle) * step;
    }
}


void	ft_ad(t_vars *vars, int keycode, float step)
{
    if (keycode == K_A) //A
    {
         if (vars->map.raw[(int)(vars->player.pos.y)][(int)(vars->player.pos.x + cos(vars->player.angle - radians(90)) * step)] == 48)
       		 vars->player.pos.x += cos(vars->player.angle - radians(90)) * step;
         if (vars->map.raw[(int)(vars->player.pos.y + sin(vars->player.angle - radians(90) * step))][(int)(vars->player.pos.x)] == 48)
     		   vars->player.pos.y += sin(vars->player.angle - radians(90)) * step;
    }
    else if (keycode == K_D) //D
    {
         if (vars->map.raw[(int)(vars->player.pos.y)][(int)(vars->player.pos.x - cos(vars->player.angle - radians(90)) * step)] == 48)
		 {
        vars->player.pos.x += cos(vars->player.angle + radians(90)) * step;
         if (vars->map.raw[(int)(vars->player.pos.y - sin(vars->player.angle - radians(90) * step))][(int)(vars->player.pos.x)] == 48)
        vars->player.pos.y += sin(vars->player.angle + radians(90)) * step;
		 }
	}
}

void	ft_arrow(t_vars *vars, int keycode, float step)
{
	(void)step;
    if (keycode == K_AR_L) //L_ARROW
    {
        vars->player.angle -= radians(5);
        printf("angle : %f\n", degrees(vars->player.angle));
    }
    else if (keycode == K_AR_R) //R_ARROW
    {
        vars->player.angle += radians(5);
        printf("angle : %f\n", degrees(vars->player.angle));
    }


    if (keycode == K_AR_U) //UP_ARROW
    {
        vars->player.hori += 10;
        printf("hori : %f\n", vars->player.hori);
    }
    else if (keycode == K_AR_D) //DOWN_ARROW
    {
        vars->player.hori -= 10;
        printf("hori : %f\n", vars->player.hori);
    }
}

void	ft_move(t_vars *vars, int keycode, float step)
{

	if (keycode == K_W || keycode == K_S)
		ft_ws(vars, keycode, step);
	else if (keycode == K_A || keycode == K_D)
		ft_ad(vars, keycode, step);
	else if (keycode == K_AR_L || keycode == K_AR_R || keycode == K_AR_U || keycode == K_AR_D)
		ft_arrow(vars, keycode, step);
}
