/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pistol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:49:17 by jjaqueme          #+#    #+#             */
/*   Updated: 2022/04/29 14:14:19 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

#define PISTOL_SPEED 6

int	x = WINDOW_WIDTH / 2 - 250;
int y = WINDOW_HEIGHT - 500;

void	pistol_fire(t_vars *vars)
{
	if (vars->pistol.frame == 0)
		sound_music(vars, "pistol");
	if (vars->pistol.frame < PISTOL_SPEED * 1)
		ft_put_image(vars, &vars->pistol.pistol2,
			(t_point){x, y}, (t_point){x + 500, y + 500});
	else if (vars->pistol.frame < PISTOL_SPEED * 2)
		ft_put_image(vars, &vars->pistol.pistol3,
			(t_point){x, y}, (t_point){x + 500, y + 500});
	else if (vars->pistol.frame < PISTOL_SPEED * 3)
		ft_put_image(vars, &vars->pistol.pistol4,
			(t_point){x, y}, (t_point){x + 500, y + 500});
	else if (vars->pistol.frame < PISTOL_SPEED * 4)
		ft_put_image(vars, &vars->pistol.pistol5,
			(t_point){x, y}, (t_point){x + 500, y + 500});
	else
		ft_put_image(vars, &vars->pistol.pistol1,
			(t_point){x, y}, (t_point){x + 500, y + 500});
	vars->pistol.frame++;
}
