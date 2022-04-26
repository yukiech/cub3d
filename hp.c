/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:49:16 by jjaqueme          #+#    #+#             */
/*   Updated: 2022/04/26 13:49:16 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_damage(t_vars *vars)
{
	if (ft_get_case(vars, vars->player.pos.x, vars->player.pos.y) == '^')
	{
		vars->player.hp -= 0.5;
		vars->player.on_fire++;
	}
	if (vars->player.on_fire > 0)
	{
		if (ft_get_case(vars, vars->player.pos.x, vars->player.pos.y) != '^')
			vars->player.on_fire -= 4;
		ft_put_image(vars, &vars->fire[(int)(vars->frame / 6) % 10],
			(t_point){0, vars->screen.h * 0.5}, (t_point){vars->screen.w, vars->screen.h * 1.2});
	}
}

void	ft_hp_draw(t_vars *vars)
{
	ft_damage(vars);
	if (vars->player.hp > 0)
	{
		t_point	start;
		start.x = 600;
		start.y = 30;

		int		i;

		i = 0;
		while (i < 4)
		{
			if (vars->player.hp * 100 / vars->player.hp_start > (1 / (4 * 2)) * (i * 2 + 1))
				ft_put_image(vars, &vars->loading.heart, start, (t_point){start.x + 40, start.y + 37});

			else if (vars->player.hp / vars->player.hp_start > (1 / (4 * 2)) * (i * 2))
				ft_put_image(vars, &vars->loading.heart_half, start, (t_point){start.x + 20, start.y + 37});


			start.x += 40;


//				mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.heart_half.img, 600, 30);

			i++;

			
		}

		printf("%f\n", vars->player.hp);

/*

		if (vars->player.hp * 100 / vars->player.hp_start > 0 )
			ft_put_image(vars, &vars->loading, start, (t_point){start.x + 20, start.y + 37}
			mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.heart_half.img, 600, 30);
		if (vars->player.hp * 100 / vars->player.hp_start > 12)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.heart.img, 600, 30);
		if (vars->player.hp * 100 / vars->player.hp_start > 25)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.heart_half.img, 640, 30);
		if (vars->player.hp * 100 / vars->player.hp_start > 37)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.heart.img, 640, 30);
		if (vars->player.hp * 100 / vars->player.hp_start > 50)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.heart_half.img, 680, 30);
		if (vars->player.hp * 100 / vars->player.hp_start > 62)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.heart.img, 680, 30);
		if (vars->player.hp * 100 / vars->player.hp_start > 75)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.heart_half.img, 720, 30);
		if (vars->player.hp * 100 / vars->player.hp_start > 87)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->loading.heart.img, 720, 30);*/
	}
	else if (vars->player.hp == 0)
	{
		sound_music(vars, "wilheim");
		vars->player.hp = -1;
	}
}
