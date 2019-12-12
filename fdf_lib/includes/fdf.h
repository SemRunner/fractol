/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:19:24 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/30 22:14:45 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>

# define FDF_ANGLE_ROTATE_PRECISION 15

# define FDF_KEY_UP 126
# define FDF_KEY_DOWN 125
# define FDF_KEY_Q 12
# define FDF_KEY_ESC 53
# define FDF_KEY_PLUS 24
# define FDF_KEY_MINUS 27

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
	int				x0;
	int				y0;
	int				z0;
}					t_point;

typedef struct		s_rot
{
	double			r_x[16];
	double			r_y[16];
	double			r_z[16];
	double			r_persp[16];
	double			r_all[16];
}					t_rot;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	void			*main_im;
	int				*data_mainim;
	int				width;
	int				height;
	int				bits_pixel;
	int				size_line;
	int				endian;
	int				*map;
	int				map_x;
	int				map_y;
	int				max_h;
	int				min_h;
	t_point			*map_points;
	int				quantity_points;
	int				zoom_coef;
	double			zoom;
	int				h_coef;
	double			h;
	int				x_angle;
	int				y_angle;
	int				z_angle;
	int				rotate_prec;
	int				angle_projection_type;
	int				prev_ang_proj_type;
	int				projection_type;
	int				prev_proj_type;
	int				camera_x;
	int				camera_y;
	int				type_color_spectrum;
	t_rot			*mr;
}					t_mlx;

/*
** init and destroy data
** file initialize_mlx.c
*/

void				tmlx_destroy(t_mlx *m, int value_exit);
void				tmlx_initialize(t_mlx *m, int x, int y);
int					tmlx_create_mlx(t_mlx *m, char *title);
void				reset_map(t_mlx *m);

/*
** load data
** file readfile0.c readfile1.c readfile2.c
*/

void				first_check_file(t_mlx *m, char *filename);
void				load_map(t_mlx *m, char *filename);
int					check_file(t_mlx *m, int fd);
int					put_map(t_mlx *m, int fd);
void				set_base_coord(t_mlx *m);
void				calculate_max_min_h_in_map(t_mlx *m);

/*
** working functions
** files legend.c keyhook.c
*/

void				main_legend(t_mlx *m);
int					keyhooks(int keycode, t_mlx *m);
int					check_keyhooks_fdf(int k);
void				calc_hzoom(t_mlx *m, int coef);

/*
** making map_points from map. it's doing on every iteration, in map_points
** putting base points, than that points changing
** file make_map_points.c
*/

void				make_map_points(t_mlx *m);
void				calc_parameter_maps(t_mlx *m);

void				draw_surface(t_mlx *m, int not_black);

/*
** rotation functions
** file rotation.c
*/

void				set_rotate_matrix_zero(double *m);
void				set_rotate_matrix_to_one(double *m);
void				calc_r_x(t_rot *mr, int x_angle);
void				calc_r_y(t_rot *mr, int y_angle);
void				calc_r_z(t_rot *mr, int z_angle);
void				mult_rmatrix(double *res, double *a, double *b);
void				mult_xyz_rmatrix(t_mlx *m, double *rmatrix, t_point *p);
void				mult_xyz_rmatrix_persp(t_mlx *m, double *rmatrix,
											t_point *p);

void				z_rotation(t_mlx *m);
void				x_rotation(t_mlx *m);
void				y_rotation(t_mlx *m);
void				rotate_points(t_mlx *m);

/*
** draw pixel, line, figures
** file draw.c draw_point.c get_proj_point.c iso_transform.c
**      fdf_draw_figures.c
*/


void				draw_main_image(t_mlx *m);
void				clear_image(t_mlx *m);

void				putpixel(t_mlx *m, int x, int y, int color);
void				putline(t_mlx *m, t_point start, t_point end,
							int not_black);
void				putpoint(t_mlx *m, int i);
void				iso(t_mlx *m, int *x, int *y, int z);
void				putbox(t_mlx *m, t_point center, int size, int not_black);
void				put_full_box(t_mlx *m, t_point center, int size,
								int not_black);
void				putcircle(t_mlx *m, t_point center, int radius,
							int not_black);
void				put_thickcircle(t_mlx *m, t_point center, int radius,
							int not_black);
void				put_full_thickcircle(t_mlx *m, t_point center,
								int radius, int not_black);
void				put_thickline(t_mlx *m, t_point start, t_point end,
							int not_black);

t_point				get_point_to_draw(t_mlx *m, int i);
t_point				get_proj_point_to_draw(t_mlx *m, int i);

/*
** work with color
** file color.c
*/

double				perc(int start, int end, int curr);
int					calc_gradient(int start, int end, double percent);
int					color_gradient(t_point start, t_point end, double perc);
int					calc_color_spectrum(int type_color_spectrum, int percent);
void				correct_color(t_mlx *m);

#endif
