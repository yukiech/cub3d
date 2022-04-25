#include <cub3d.h>

static void	ft_set_wall_pos(t_wall *walls, int i, t_point p, int side);
static void	ft_set_wall_orientation(t_wall *walls, int i, t_point p, int side);

void	ft_create_wall(t_wall *walls, t_point p, int side, int type)
{
	int	i;

	i = 0;
	while (walls[i].type != W_NONE)
		i++;
	walls[i].type = type;
	ft_set_wall_pos(walls, i, p, side);
	ft_set_wall_orientation(walls, i, p, side);
}

static void	ft_set_wall_pos(t_wall *walls, int i, t_point p, int side)
{
	walls[i].pos = p;
	walls[i].pos.x += 0.5;
	walls[i].pos.y += 0.5;
	if (side == W_UPWALL)
		walls[i].pos.y -= 1;
	else if (side == W_LEFTWALL)
		walls[i].pos.x -= 1;
	else if (side == W_RIGHTWALL)
		walls[i].pos.x += 1;
	else if (side == W_DOWNWALL)
		walls[i].pos.y += 1;
}

static void	ft_set_wall_orientation(t_wall *walls, int i, t_point p, int side)
{
	if (side == W_UPWALL)
	{
		walls[i].p1 = (t_point){.x = p.x, .y = p.y};
		walls[i].p2 = (t_point){.x = p.x + 1, .y = p.y};
	}
	if (side == W_LEFTWALL)
	{
		walls[i].p1 = (t_point){.x = p.x, .y = p.y + 1};
		walls[i].p2 = (t_point){.x = p.x, .y = p.y};
	}
	if (side == W_RIGHTWALL)
	{
		walls[i].p1 = (t_point){.x = p.x + 1, .y = p.y};
		walls[i].p2 = (t_point){.x = p.x + 1, .y = p.y + 1};
	}
	if (side == W_DOWNWALL)
	{
		walls[i].p1 = (t_point){.x = p.x + 1, .y = p.y + 1};
		walls[i].p2 = (t_point){.x = p.x, .y = p.y + 1};
	}
}
