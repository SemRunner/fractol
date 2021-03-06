/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:42:55 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/15 15:07:53 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "fdf.h"
# include "mlx.h"
# include "math.h"
# include "libft.h"
# include "fractol_opcl.h"

# define HEIGHT 1000
# define WIDTH 1000

# define COUNT_FRACTOLS 7

# define FR_MANDEL 0
# define FR_JULIA 1
# define FR_BRN_SP 2
# define FR_CEL_MAN 3
# define FR_TEST1 4
# define FR_CEL_PER 5
# define FR_SPIDER 6

typedef struct	s_complex
{
	long double		re;
	long double		im;
}				t_complex;

typedef struct	s_fractol
{
	t_mlx			*m;
	void			*imlegend;
	int				*data_imlegend;
	int				bits_pixel;
	int				size_line;

	int				type_fractol;
	int				type_color;
	int				show_legend;

	int				mouse_x;
	int				mouse_y;
	int				in_move;

	long double		zoom;
	long double		m_x;
	long double		m_y;
	long double		m_xx;
	long double		m_yy;

	int				max_iter;

	t_complex		centre;
	t_complex		max;
	t_complex		min;
	t_complex		c;
	t_complex		k;
	t_complex		factor;

	t_opcl			*opcl;
	int				type_device;

}				t_fractol;

t_complex		init_complex(long double re, long double im);

void			fractol_init(t_fractol *f);
void			fractol_reset(t_fractol *f);

/*
** mandelbrot
*/

void			draw_fractol(t_fractol *f);
void			put_fractol_legend(t_fractol *f);
void			draw_background_legend(t_fractol *f);

int				cycle_mandel(t_fractol *f, t_complex z);
int				cycle_julia(t_fractol *f, t_complex z);
int				cycle_brn_sp(t_fractol *f, t_complex z);
int				cycle_cel_man(t_fractol *f, t_complex z);
int				cycle_test1(t_fractol *f, t_complex z);
int				cycle_cel_per(t_fractol *f, t_complex z);
int				cycle_spider(t_fractol *f, t_complex z);

void			mandelbrot(t_mlx *m, t_complex max, t_complex min,
							int max_iter);
void			julia(t_mlx *m, t_complex max, t_complex min,
							int max_iter, t_complex k);

int				in_frontiers(int x, int y, t_fractol *f);

int				fract_keyhook(int keycode, void *fr);
int				mouse_move(int x, int y, t_fractol *f);
int				mouse_press(int key, int x, int y, t_fractol *f);
int				mouse_release(int key, int x, int y, t_fractol *f);
void			zoom_fractol(t_fractol *f, int keycode);
void			move_fractol(int x, int y, t_fractol *f);

/*
** openCL
*/

void			draw_cl(t_opcl *opcl, t_fractol *f);

#endif
