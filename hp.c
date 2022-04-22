#include <cub3d.h>

void	ft_damage(t_vars *vars)
{
	if (ft_get_case(vars, vars->player.pos.x, vars->player.pos.y) == '^')
		vars->player.hp -= 1;
}

void	ft_hp_draw(t_vars *vars)
{
	char	*text;
	char	*number;

	ft_damage(vars);
	text = "HP : ";
	number = ft_itoa(vars->player.hp);
	text = ft_strjoin(text, number);
	ft_tfree((void **)&number);
	ft_write_text(vars, text, (t_point){.x = 600, .y = 30},
		(t_vect){.v1 = 2, .v2 = 0x000000});
	ft_tfree((void **)&text);
}
