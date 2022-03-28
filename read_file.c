#include <cub3d.h>

static void	ft_read_args(t_vars *vars, int fd);
static int	ft_select_arg(t_vars *vars, char **sp);
static void	ft_read_map(t_vars *vars, int fd);

void	ft_load_map(t_vars *vars, char *filename)
{
	int	fd;

	if (ft_atoi(filename) == 0)
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1 || read(fd, NULL, 0) == -1)
			ft_exit(vars, "Error file");
		ft_read_args(vars, fd);
		ft_read_map(vars, fd);
		close(fd);
	}
	else
		ft_generate_map(vars, (unsigned int)ft_atoi(filename));
	ft_load_image(vars, vars->map.north.path, &vars->map.north);
	ft_load_image(vars, vars->map.south.path, &vars->map.south);
	ft_load_image(vars, vars->map.west.path, &vars->map.west);
	ft_load_image(vars, vars->map.east.path, &vars->map.east);
}

static void	ft_read_args(t_vars *vars, int fd)
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
		vars->map.north.path = ft_strdup(sp[1]);
	else if (ft_strcmp(sp[0], "SO") == 0)
		vars->map.south.path = ft_strdup(sp[1]);
	else if (ft_strcmp(sp[0], "WE") == 0)
		vars->map.west.path = ft_strdup(sp[1]);
	else if (ft_strcmp(sp[0], "EA") == 0)
		vars->map.east.path = ft_strdup(sp[1]);
	else if (ft_strcmp(sp[0], "F") == 0)
		vars->map.floor.raw = ft_strdup(sp[1]);
	else if (ft_strcmp(sp[0], "C") == 0)
		vars->map.ceil.raw = ft_strdup(sp[1]);
	else
		return (0);
	return (1);
}

static void	ft_read_map(t_vars *vars, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line != NULL)
		line[ft_strlen(line) - 1] = '\0';
	while (line != NULL)
	{
		if (vars->map.raw == NULL && ft_strlen(line) == 0)
			free(line);
		else
			ft_concat_tab(&vars->map.raw, line);
		line = get_next_line(fd);
		if (line != NULL)
			line[ft_strlen(line) - 1] = '\0';
	}
}
