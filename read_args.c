#include <cub3d.h>

static int	ft_select_arg(t_vars *vars, char **sp);
static int	ft_set_arg(t_vars *vars, char **txt, char *input);

void	ft_read_args(t_vars *vars, int fd)
{
	char	*line;
	int		infos;
	char	**sp;

	infos = 0;
	line = get_next_line(fd);
	while (infos < 6 && line != NULL)
	{
		line[ft_strlen(line) - 1] = '\0';
		sp = ft_split(line, ' ');
		if (ft_tab_len(sp) == 2)
			infos += ft_select_arg(vars, sp);
		else if (ft_strlen(line) > 1)
			ft_exit(vars, "Error dirt map");
		ft_free_2d(sp);
		free(line);
		if (infos != 6)
			line = get_next_line(fd);
	}
	if (infos != 6)
		ft_exit(vars, "Error first args");
}

static int	ft_select_arg(t_vars *vars, char **sp)
{
	if (ft_strcmp(sp[0], "NO") == 0)
		return (ft_set_arg(vars, &vars->map.north.path, sp[1]) + 1);
	else if (ft_strcmp(sp[0], "SO") == 0)
		return (ft_set_arg(vars, &vars->map.south.path, sp[1]) + 1);
	else if (ft_strcmp(sp[0], "WE") == 0)
		return (ft_set_arg(vars, &vars->map.west.path, sp[1]) + 1);
	else if (ft_strcmp(sp[0], "EA") == 0)
		return (ft_set_arg(vars, &vars->map.east.path, sp[1]) + 1);
	else if (ft_strcmp(sp[0], "F") == 0)
		return (ft_set_arg(vars, &vars->map.floor.raw, sp[1]) + 1);
	else if (ft_strcmp(sp[0], "C") == 0)
		return (ft_set_arg(vars, &vars->map.ceil.raw, sp[1]) + 1);
	else if (ft_strcmp(sp[0], "M") == 0)
		return (ft_set_arg(vars, &vars->map.music, sp[1]) + 0);
	else if (ft_strcmp(sp[0], "F") == 0)
		return (ft_set_arg(vars, &vars->map.next, sp[1]) + 0);
	else
		return (0);
}

static int	ft_set_arg(t_vars *vars, char **txt, char *input)
{
	if (*txt == NULL)
		*txt = ft_strdup(input);
	else
		ft_exit(vars, "Arg found twice");
	return (0);
}
