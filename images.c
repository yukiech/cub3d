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
	if (!(x < 0 || y < 0 || x >= img->w || y >= img->h))
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
//	int	off_y;
//	int	off_len;

//	if (o2.x < o1.x)
//		return (ft_put_image(vars, img, o2, o1, hori));
	i = o1.x;
	while (i < o2.x)
	{
//		off_y = map(i, (t_vect){.v1 = o1.x, .v2 = o2.x}, (t_vect){.v1 = o1.y, .v2 = o2.y});
//		off_len = map(i, (t_vect){.v1 = o1.x, .v2 = o2.x},
//				(t_vect){.v1 = (hori - o1.y) * 2, .v2 = (hori - o2.y) * 2});


		j = o1.y;
		while (j < o2.y)
		{
			ft_set_px(&vars->screen, i, j, ft_get_px(img, map(i, (t_vect){.v1 = o1.x, .v2 = o2.x}, (t_vect){.v1 = 0, .v2 = img->w}), map(j, (t_vect){.v1 = o1.y, .v2 = o2.y}, (t_vect){.v1 = 0, .v2 = img->h})));
			j++;
		}

		i++;
	}
	return (0);
}

int	ft_put_col(t_vars *vars, t_imgptr *img, t_point o1, float ratio)
{
	int	j;
	float	off_y;
	float	off_len;
	float	end;

//	off_y = o1.y;
	off_y = vars->player.hori - o1.y / 2;
	off_len = o1.y;
//	off_len = (vars->player.hori - o1.y) * 2.0;

//	printf("%f  %f\n ", off_y, off_len);

//	j = off_y;
//	end = off_y + off_len;



	j = fmax(off_y, 0);
	end = fmin(off_y + off_len, vars->screen.h);
	while (j < end)
	{

//		float	res = ((j - in->v1) * (out->v2 - out->v1) / (in->v2 - in->v1) + out->v1);
		float	res = ((j - off_y) * (img->h) / (off_len));


		float dd = res;
//		float dd = map(j, n_vect(off_y, off_y + off_len), n_vect(0, img->h));
		float cc = fmax(0, dd);



		float bb = fmin(img->h, cc);


		float aa = 	ft_get_px(img, ratio * img->w, bb);




		ft_set_px(&vars->screen, o1.x, j, aa);
		j++;
	}
	return (0);
}

/*
int	ft_put_image(t_vars *vars, t_imgptr *img, t_point o1, t_point o2)
{
	int	i;
	int	j;
	int	off_y;
	int	off_len;

	if (o2.x < o1.x)
		return (ft_put_image(vars, img, o2, o1));
	i = o1.x - 1;
	while (++i < o2.x)
	{
		off_y = map(i, n_vect(o1.x, o2.x), n_vect(o1.y, o2.y));
		off_len = map(i, n_vect(o1.x, o2.x),
				n_vect((vars->screen.h / 2 - o1.y) * 2,
					(vars->screen.h / 2 - o2.y) * 2));
		j = off_y - 1;
		while (++j < off_y + off_len)
		{
			ft_set_px(&vars->screen, i, j, ft_get_px(img,
					map(i, n_vect(o1.x, o2.x), n_vect(0, img->w)),
					map(j, n_vect(off_y, off_y + off_len),
						n_vect(0, img->h))));
		}
	}
	return (0);
}
*/
