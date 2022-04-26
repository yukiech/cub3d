/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:49:18 by jjaqueme          #+#    #+#             */
/*   Updated: 2022/04/26 13:49:18 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERATE_H
# define GENERATE_H

# define GEN_WIDTH 80
# define GEN_HEIGHT 60

# define GEN_PROPAG 25
# define GEN_CONTINUE 70
# define GEN_TRESH 0.08
# define GEN_BORDERS 0.2

# define GEN_NORTH "./assets/normal_north.xpm"
# define GEN_SOUTH "./assets/normal_south.xpm"
# define GEN_WEST "./assets/normal_west.xpm"
# define GEN_EAST "./assets/normal_east.xpm"
# define GEN_CEIL "150,220,220"
# define GEN_FLOOR "160,160,160"

void	ft_generate_map(t_vars *vars, unsigned int seed);
int		ft_gen_count(t_vars *vars);
void	ft_gen_expend(t_vars *vars, int x, int y, int dir);
int		ft_gen_check(t_vars *vars);

#endif //GENERATE_H
