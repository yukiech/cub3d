#include <cub3d.h>

static void	ft_read_file(t_vars *vars, char *filename);
static void	ft_read_map(t_vars *vars, int fd);
static void	ft_load_color(t_vars *vars, t_color *color);

void	ft_open_map(t_vars *vars, char *filename)
{
	if (ft_atoi(filename) == 0)
		ft_read_file(vars, filename);
	else
		ft_generate_map(vars, (unsigned int)ft_atoi(filename));
	ft_load_image(vars, vars->map.north.path, &vars->map.north);
	ft_load_image(vars, vars->map.south.path, &vars->map.south);
	ft_load_image(vars, vars->map.west.path, &vars->map.west);
	ft_load_image(vars, vars->map.east.path, &vars->map.east);
	ft_load_image(vars, "./assets/newdoor.xpm", &vars->map.door);
	ft_load_color(vars, &vars->map.ceil);
	ft_load_color(vars, &vars->map.floor);
}

static void	ft_read_file(t_vars *vars, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1 || read(fd, NULL, 0) == -1)
		ft_exit(vars, "Error file");
	ft_read_args(vars, fd);
	ft_read_map(vars, fd);
	close(fd);
}

static void	ft_read_map(t_vars *vars, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line != NULL && ft_strchr(line, '\n'))
		line[ft_strchr(line, '\n') - line] = '\0';
	while (line != NULL)
	{
		if (vars->map.raw == NULL && ft_strlen(line) == 0)
			free(line);
		else
			vars->map.height = ft_concat_tab(&vars->map.raw, line) - 1;
		line = get_next_line(fd);
		if (line != NULL && ft_strchr(line, '\n'))
			line[ft_strchr(line, '\n') - line] = '\0';
	}
}

static void	ft_load_color(t_vars *vars, t_color *color)
{
	char	**sp;

	sp = ft_split(color->raw, ',');
	if (sp == NULL)
		ft_exit(vars, "Split error");
	if (ft_tab_len(sp) != 3
		|| ft_isnumber(sp[0]) == 0
		|| ft_isnumber(sp[1]) == 0
		|| ft_isnumber(sp[2]) == 0)
	{
		ft_exit(vars, "Color arguments error");
	}
	color->color = ft_atoi(sp[0]) << 16 | ft_atoi(sp[1]) << 8 | ft_atoi(sp[2]);
}
