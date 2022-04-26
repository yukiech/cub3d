/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:49:16 by jjaqueme          #+#    #+#             */
/*   Updated: 2022/04/26 14:32:36 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	load_assets_2(t_vars *vars);

void	load_assets(t_vars *vars)
{	
	ft_load_image(vars, "./assets/menu_1.xpm", &vars->loading.menu_1);
	ft_load_image(vars, "./assets/menu_2.xpm", &vars->loading.menu_2);
	ft_load_image(vars, "./assets/menu_3.xpm", &vars->loading.menu_3);
	ft_load_image(vars, "./assets/menu_4.xpm", &vars->loading.menu_4);
	ft_load_image(vars, "./assets/char_ghost.xpm", &vars->loading.ghost);
	ft_load_image(vars, "./assets/char_ninja.xpm", &vars->loading.ninja);
	ft_load_image(vars, "./assets/char_pirate.xpm", &vars->loading.pirate);
	ft_load_image(vars, "./assets/char_franken.xpm", &vars->loading.franken);
	ft_load_image(vars, "./assets/sound_on.xpm", &vars->loading.sound_on);
	ft_load_image(vars, "./assets/sound_off.xpm", &vars->loading.sound_off);
	load_assets_2(vars);
}

static void	load_assets_2(t_vars *vars)
{
	ft_load_image(vars, "./assets/gun_1.xpm", &vars->pistol.pistol1);
	ft_load_image(vars, "./assets/gun_2.xpm", &vars->pistol.pistol2);
	ft_load_image(vars, "./assets/gun_3.xpm", &vars->pistol.pistol3);
	ft_load_image(vars, "./assets/gun_4.xpm", &vars->pistol.pistol4);
	ft_load_image(vars, "./assets/gun_5.xpm", &vars->pistol.pistol5);
	ft_load_image(vars, "./assets/heart_full.xpm", &vars->heart);
	ft_load_image(vars, "./assets/heart_left.xpm", &vars->heart_half);
	ft_load_image(vars, "./assets/newdoor.xpm", &vars->door);
	ft_load_image(vars, "./assets/portal.xpm", &vars->portal);
	ft_load_image(vars, "./assets/fire_0.xpm", &vars->fire[0]);
	ft_load_image(vars, "./assets/fire_1.xpm", &vars->fire[1]);
	ft_load_image(vars, "./assets/fire_2.xpm", &vars->fire[2]);
	ft_load_image(vars, "./assets/fire_3.xpm", &vars->fire[3]);
	ft_load_image(vars, "./assets/fire_4.xpm", &vars->fire[4]);
	ft_load_image(vars, "./assets/fire_5.xpm", &vars->fire[5]);
	ft_load_image(vars, "./assets/fire_6.xpm", &vars->fire[6]);
	ft_load_image(vars, "./assets/fire_7.xpm", &vars->fire[7]);
	ft_load_image(vars, "./assets/fire_8.xpm", &vars->fire[8]);
	ft_load_image(vars, "./assets/fire_9.xpm", &vars->fire[9]);
}
