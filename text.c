/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:49:18 by jjaqueme          #+#    #+#             */
/*   Updated: 2022/04/26 13:49:18 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

#define FONT_FILE "./assets/font.xpm"

void	ft_load_texter(t_vars *vars)
{
	ft_load_image(vars, FONT_FILE, &vars->texter);
}

//t_vect: size, color
void	ft_write_text(t_vars *vars, char *str, t_point pos, t_vect si_col)
{
	int	i;
	int	j;
	int	k;
	int	size;

	size = si_col.v1;
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (j < 20 * size)
		{
			k = i * size * 10;
			while (k < (i + 1) * size * 10)
			{
				if (ft_get_px(&vars->texter, (str[i] - 32) * 12
						+ (k - i * size * 10) / size, j / size) > 0)
					ft_set_px(&vars->screen, pos.x + k, pos.y + j, si_col.v2);
				k++;
			}
			j++;
		}
		i++;
	}
}
