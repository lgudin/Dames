/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <leon.gudin@ynov.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:31:05 by lgudin            #+#    #+#             */
/*   Updated: 2021/12/11 14:20:09 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_cursor
{
	int						x;
	int						y;
}				t_cursor;

typedef struct	s_rgb
{
	unsigned char			color_r;
	unsigned char			color_g;
	unsigned char			color_b;
}				t_rgb;

typedef struct	s_proj
{
	long					x;
	long					y;
	t_rgb					color;
}				t_proj;


typedef struct	s_pt
{
	float					x;
	float					y;
	float					z;
	int						color;
}				t_pt;


typedef struct	s_ptr
{
	int						*mlx;
	int						*win;
	int						*img;
	char					*img_data;
	int						bpp;
	int						size_line;
	int						endian;
}				t_ptr;


typedef struct	s_dam
{
	t_cursor				selected;
	t_cursor				clic1;
	t_cursor				clic2;

	t_proj					**proj;
	t_pt					**tab;
    t_ptr                   ptr;
	char					turn;
	char					**data_board;
	int						bck_clr;

    
}				t_dam;