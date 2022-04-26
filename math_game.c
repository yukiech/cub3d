/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:49:16 by jjaqueme          #+#    #+#             */
/*   Updated: 2022/04/26 13:49:16 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_set_px(t_imgptr *img, int x, int y, int color)
{
	if (!(x < 0 || y < 0 || x >= img->w || y >= img->h))
		img->pxs[y * img->line + x] = color;
}

int	ft_get_px(t_imgptr *img, int x, int y)
{
	return (img->pxs[y * img->line + x]);
}

int	ft_color(UCHAR a, UCHAR r, UCHAR g, UCHAR b)
{
	int	res;

	res = a;
	res = (res << 8) | r;
	res = (res << 8) | g;
	res = (res << 8) | b;
	return (res);
}

char	ft_get_case(t_vars *vars, int x, int y)
{
	if (y < 0)
		return ('\e');
	if (y > vars->map.height)
		return ('\e');
	if (x < 0)
		return ('\e');
	if (x > (int)ft_strlen(vars->map.raw[y]))
		return ('\e');
	if (vars->map.raw[y][x] == '\0')
		return ('\e');
	return (vars->map.raw[y][x]);
}
