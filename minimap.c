/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:49:16 by jjaqueme          #+#    #+#             */
/*   Updated: 2022/04/26 14:35:49 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

#define MAP_SIZE 21
#define MAP_HALF 10.5
#define MAP_PX 6.0

static void	mm_colors(t_vars *vars, float x, float y, char c);
static void	mm_case(t_imgptr *minimap, float x, float y, int color);
static void	mm_player(t_vars *vars, t_imgptr *minimap);

void	minimap_draw(t_vars *vars)
{
	t_point		playerpos;
	float		i;
	float		j;

	playerpos = vars->player.pos;
	i = -MAP_HALF - fmod(playerpos.y, 1);
	while (i <= MAP_HALF + 1)
	{
		j = -MAP_HALF - fmod(playerpos.x, 1);
		while (j <= MAP_HALF + 1)
		{
			mm_colors(vars, j, i, ft_get_case(vars,
					playerpos.x + j, playerpos.y + i));
			j++;
		}
		i++;
	}
	mm_player(vars, &vars->screen);
}

static void	mm_colors(t_vars *vars, float x, float y, char c)
{
	if (ft_strchr("\e1 ", c) != NULL)
		mm_case(&vars->screen, x, y, ft_color(0, 0, 0, 0));

	else if (ft_strchr("0", c) != NULL)
		mm_case(&vars->screen, x, y, ft_color(0, 255, 255, 255));

	else if (ft_strchr("D", c) != NULL)
		mm_case(&vars->screen, x, y, ft_color(0, 0, 0, 255));

	else if (ft_strchr("^", c) != NULL)
		mm_case(&vars->screen, x, y, ft_color(0, 255, 128, 0));

	else if (ft_strchr("F", c) != NULL)
		mm_case(&vars->screen, x, y, ft_color(0, 0, 255, 0));
}

static void	mm_case(t_imgptr *minimap, float x, float y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i <= MAP_PX)
	{
		j = 0;
		while (j <= MAP_PX)
		{
			if (ft_pyta(x + j / MAP_PX, y + i / MAP_PX) < 8)
				ft_set_px(minimap, (x + MAP_HALF - 0.5) * MAP_PX + j,
					(y + MAP_HALF - 0.5) * MAP_PX + i, color);
			else if (ft_pyta(x + j / MAP_PX, y + i / MAP_PX) < 9)
				ft_set_px(minimap, (x + MAP_HALF - 0.5) * MAP_PX + j,
					(y + MAP_HALF - 0.5) * MAP_PX + i, ft_color(0, 105, 75, 0));
			j++;
		}
		i++;
	}
}

static void	mm_player(t_vars *vars, t_imgptr *minimap)
{
	t_point	pl;
	t_point	p1;
	t_point	p2;
	t_point	p3;

	p1.x = cos(vars->player.angle) * 6;
	p1.y = sin(vars->player.angle) * 6;
	p2.x = cos(vars->player.angle - radians(120)) * 3;
	p2.y = sin(vars->player.angle - radians(120)) * 3;
	p3.x = cos(vars->player.angle + radians(120)) * 3;
	p3.y = sin(vars->player.angle + radians(120)) * 3;
	pl.y = -MAP_HALF + 0.5;
	while (pl.y < MAP_HALF)
	{
		pl.x = -MAP_HALF + 0.5;
		while (pl.x < MAP_HALF)
		{
			if (abs(bsp(pl, p1, p2) + bsp(pl, p2, p3) + bsp(pl, p3, p1)) == 3)
				ft_set_px(minimap, pl.x + MAP_HALF * MAP_PX,
					pl.y + MAP_HALF * MAP_PX, ft_color(0, 255, 0, 0));
			pl.x += 0.1;
		}
		pl.y += 0.1;
	}
}
