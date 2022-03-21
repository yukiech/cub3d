#include <cub3d.h>

void	ft_load_image(t_vars *vars, char *filename, t_imgptr *ptr)
{
	if (filename != NULL)
		ptr->img = mlx_xpm_file_to_image(vars->mlx, filename, &ptr->w, &ptr->h);
	else
		ptr->img = mlx_new_image(vars->mlx, ptr->w, ptr->h);
	if (ptr->img == NULL)
		ft_exit(vars, "Image not found");
	ptr->pxs = (int *)mlx_get_data_addr(ptr->img, &ptr->bits,
			&ptr->line, &ptr->end);
	ptr->line = ptr->line / 4;
}

void	ft_set_px(t_imgptr *img, int x, int y, int color)
{
	img->pxs[y * img->line + x] = color;
}

int	ft_get_px(t_imgptr *img, int x, int y)
{
	return (img->pxs[y * img->line + x]);
}

int	ft_put_image(t_vars *vars, t_imgptr *img, t_point o1, t_point o2)
{
	int	i;
	int	j;
	int	offsety;
	int	offsetl;

	if (o2.x < o1.x)
		return (ft_put_image(vars, img, o2, o1));
	i = o1.x;
	while (i < o2.x)
	{
		offsety = map(i, o1.x, o2.x, o1.y, o2.y);
		offsetl = map(i, o1.x, o2.x, (vars->screen.h / 2 - o1.y) * 2,
				(vars->screen.h / 2 - o2.y) * 2);
		j = offsety;
		while (j < offsety + offsetl)
		{
			if (!(i < 0 || j < 0 || i >= vars->screen.w || j >= vars->screen.h))
				ft_set_px(&vars->screen, i, j,
					ft_get_px(img, map(i, o1.x, o2.x, 0, img->w),
						map(j, offsety, offsety + offsetl, 0, img->h)));
			j++;
		}
		i++;
	}
	return (0);
}
