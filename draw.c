/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:49:15 by jjaqueme          #+#    #+#             */
/*   Updated: 2022/04/26 13:49:15 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_draw_hline(t_imgptr *ptr, t_point o, int len, int color)
{
	int	i;

	i = o.x;
	while (i < o.x + len)
	{
		if (!(i < 0 || o.y < 0 || i >= ptr->w || o.y >= ptr->h))
			ft_set_px(ptr, i, o.y, color);
		i++;
	}	
}

void	ft_draw_vline(t_imgptr *ptr, t_point o, int len, int color)
{
	int	i;

	i = o.y;
	while (i < o.y + len)
	{
		if (!(o.x < 0 || i < 0 || o.x >= ptr->w || i >= ptr->h))
			ft_set_px(ptr, o.x, i, color);
		i++;
	}	
}

#define CROSS_LEN 20
#define CROSS_WIDTH 3

void	ft_draw_cross(t_vars *vars)
{
	int	i;
	int	mid_h;
	int	mid_w;

	mid_h = vars->screen.h / 2;
	mid_w = vars->screen.w / 2;
	i = mid_h - (CROSS_WIDTH / 2);
	while (i < mid_h + (CROSS_WIDTH / 2))
	{
		ft_draw_hline(&vars->screen, (t_point){mid_w - (CROSS_LEN / 2), i},
			CROSS_LEN, 0xFFFFFF);
		i++;
	}
	i = mid_w - (CROSS_WIDTH / 2);
	while (i < mid_w + (CROSS_WIDTH / 2))
	{
		ft_draw_vline(&vars->screen, (t_point){i, mid_h - (CROSS_LEN / 2)},
			CROSS_LEN, 0xFFFFFF);
		i++;
	}
}
