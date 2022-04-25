#include <cub3d.h>

static void	ft_sprint(t_vars *vars, int keycode);
static void	ft_walk_collisions(t_vars *vars, int keycode);
static void	ft_walk(t_vars *vars, int keycode, t_point *futur);
static void	ft_move_camera(t_vars *vars, int keycode);

void	ft_move(t_vars *vars, int keycode)
{
	ft_sprint(vars, keycode);
	ft_walk_collisions(vars, keycode);
	ft_move_camera(vars, keycode);
}

static void	ft_sprint(t_vars *vars, int keycode)
{
	if (keycode == K_SHIFT_L)
	{
		vars->player.speed_mod += 1;
	}
	else if (keycode == -K_SHIFT_L)
	{
		vars->player.speed_mod -= 1;
	}
	else if (keycode == K_CTRL_L || keycode == K_ALT_L)
	{
		vars->player.speed_mod += 2;
	}
	else if (keycode == -K_CTRL_L || keycode == -K_ALT_L)
	{
		vars->player.speed_mod -= 2;
	}
}

static void	ft_walk_collisions(t_vars *vars, int keycode)
{
	t_point	futur;

	if (keycode == K_W || keycode == K_S || keycode == K_A || keycode == K_D)
	{
		futur.x = vars->player.pos.x;
		futur.y = vars->player.pos.y;
		ft_walk(vars, keycode, &futur);
		if (vars->player.has_collisions == 0
			|| ft_strchr("1DF \e",
				ft_get_case(vars, futur.x, vars->player.pos.y)) == NULL)
			vars->player.pos.x = futur.x;
		if (vars->player.has_collisions == 0
			|| ft_strchr("1DF \e",
				ft_get_case(vars, vars->player.pos.x, futur.y)) == NULL)
			vars->player.pos.y = futur.y;
	}
}

static void	ft_walk(t_vars *vars, int keycode, t_point *futur)
{
	float	step;

	step = vars->player.speed * (vars->player.speed_mod + 1);
	if (keycode == K_W)
	{
		futur->x += cos(vars->player.angle) * step;
		futur->y += sin(vars->player.angle) * step;
	}
	else if (keycode == K_S)
	{
		futur->x -= cos(vars->player.angle) * step;
		futur->y -= sin(vars->player.angle) * step;
	}
	else if (keycode == K_A)
	{
		futur->x += cos(vars->player.angle - radians(90)) * step;
		futur->y += sin(vars->player.angle - radians(90)) * step;
	}
	else if (keycode == K_D)
	{
		futur->x += cos(vars->player.angle + radians(90)) * step;
		futur->y += sin(vars->player.angle + radians(90)) * step;
	}
}

static void	ft_move_camera(t_vars *vars, int keycode)
{
	if (keycode == K_AR_L)
		vars->player.angle -= radians(5);
	else if (keycode == K_AR_R)
		vars->player.angle += radians(5);
	else if (keycode == K_AR_U)
		vars->player.hori += 10;
	else if (keycode == K_AR_D)
		vars->player.hori -= 10;
}
