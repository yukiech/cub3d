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

void	ft_put_image_full(t_vars *vars, t_imgptr *img)
{
	ft_put_image(vars, img, (t_point){0, 0},
		(t_point){vars->screen.w, vars->screen.h});
}

void	ft_put_image(t_vars *vars, t_imgptr *img, t_point o1, t_point o2)
{
	int		i;
	int		j;
	float	x;
	float	y;
	float	color;

	i = o1.x;
	while (i < o2.x)
	{
		j = o1.y;
		while (j < o2.y)
		{
			x = map(i, (t_vect){.v1 = o1.x, .v2 = o2.x},
					(t_vect){.v1 = 0, .v2 = img->w});
			y = map(j, (t_vect){.v1 = o1.y, .v2 = o2.y},
					(t_vect){.v1 = 0, .v2 = img->h});
			color = ft_get_px(img, x, y);
			if ((int)color >> 24 == 0)
				ft_set_px(&vars->screen, i, j, color);
			j++;
		}
		i++;
	}
}

void	ft_put_col(t_vars *vars, t_imgptr *img, t_point o1, float ratio)
{
	int		j;
	float	off_y;
	float	off_len;
	float	end;
	float	color;

	off_y = vars->player.hori - o1.y / 2;
	off_len = o1.y;
	j = fmax(off_y, 0);
	end = fmin(off_y + off_len, vars->screen.h);
	while (j < end)
	{
		color = ft_get_px(img, ratio * img->w,
				fmin(img->h, fmax(0, (j - off_y) * (img->h) / (off_len))));
		if ((int)color >> 24 == 0)
			ft_set_px(&vars->screen, o1.x, j, color);
		j++;
	}
}
