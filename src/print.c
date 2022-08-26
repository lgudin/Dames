/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <leon.gudin@ynov.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 13:55:38 by lgudin            #+#    #+#             */
/*   Updated: 2021/12/11 14:26:22 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dames.h"

t_rgb	hex_to_rgb(int hex_color)
{
	t_rgb splitted_color;

	splitted_color.color_r = hex_color % 256;
	hex_color /= 256;
	splitted_color.color_g = hex_color % 256;
	hex_color /= 256;
	splitted_color.color_b = hex_color % 256;
	return (splitted_color);
}

t_proj	prj(long x, long y, t_rgb color)
{
	t_proj i;

	i.x= (int)x;
	i.y = (int)y;
	i.color = color;
	return (i);
}

void	ft_reset_selection(t_dam *env)
{
	env->selected.x = -1;
	env->selected.y = -1;
}

void	ft_draw_pawns(t_dam *env)
{

	/*	PIONS 
	**	1 : Blanc
	**	2 : Noir
	**	3 : Reine Blanche
	**	4 : Reine Noire
	*/

	int x;
	int y;
	int i;

	y = 0;
	x = 0;
	i = 0;

	while(y < 10)
	{
		x = 0;
		while(x < 10)
		{
			if (env->data_board[y][x] == '3' || env->data_board[y][x] == '4')
				ft_draw_circle(env, PION_RAY + 3, ((x) * LARGEUR / 10 + (LARGEUR / 20)), ((y) * (LARGEUR/10) + (LARGEUR/ 20)), hex_to_rgb(GOLD));	
			if (env->data_board[y][x] == '1' || env->data_board[y][x] == '3')
				ft_draw_circle(env, PION_RAY, ((x) * LARGEUR / 10 + (LARGEUR / 20)), ((y) * (LARGEUR/10) + (LARGEUR/ 20)), hex_to_rgb(WHITE));
			else if (env->data_board[y][x] == '2' || env->data_board[y][x] == '4')
				ft_draw_circle(env, PION_RAY, ((x) * LARGEUR / 10 + (LARGEUR / 20)), ((y) * (LARGEUR/10) + (LARGEUR/ 20)), hex_to_rgb(BLACK));
			x++;
		}
		y++;
	}
	if (env->selected.x != -1)
		ft_draw_circle(env, 5, ((env->selected.x) * LARGEUR / 10 + (LARGEUR / 20)), ((env->selected.y) * (LARGEUR/10) + (LARGEUR/ 20)), hex_to_rgb(PINK));	
	ft_reset_selection(env);
}

void	ft_draw_circle(t_dam *env, int rayon, int x, int y, t_rgb color)
{
	int i;
	int ibis;
	int j;
	int jbis;

	i = 90;
	ibis = 90;
	j = 270;
	jbis = 270;

	while (i--)
	{
		ft_put_cross(env, (int)(x + rayon * cos(i)), (int)(y + rayon * sin(i)), color);
		draw_line(env, prj(x + rayon * cos(i),(y + rayon * sin(i)),color), prj(x + rayon * cos(ibis),(y + rayon * sin(ibis)), color));
		draw_line(env, prj(x + rayon * cos(j),(y + rayon * sin(j)), color), prj(x + rayon * cos(jbis),(y + rayon * sin(jbis)), color));
		ibis++;
		j++;
		jbis--;
	}

}

void	ft_put_cross(t_dam *env, int x, int y, t_rgb color)
{
	ft_put_pixel(env, x, y, color);
	ft_put_pixel(env, x + 1, y, color);
	ft_put_pixel(env, x + 1, y + 1, color);
	ft_put_pixel(env, x - 1, y, color);
	ft_put_pixel(env, x - 1, y + 1, color);
	ft_put_pixel(env, x, y + 1, color);
	ft_put_pixel(env, x + 1, y + 1, color);
	ft_put_pixel(env, x - 1, y + 1, color);
	ft_put_pixel(env, x, y - 1, color);
	ft_put_pixel(env, x + 1, y - 1, color);
	ft_put_pixel(env, x - 1, y - 1, color);
}

void	ft_put_pixel(t_dam *env, int x, int y, t_rgb color)
{
	int cursor;

	cursor = (x * 4 + y * env->ptr.size_line);
	if (x <= LARGEUR && x >= 0 && y <= HAUTEUR && y >= 0 && cursor
			+ 3 < HAUTEUR * LARGEUR * 4
			&& cursor < 2147483647 && cursor > -2147483648)
	{
		env->ptr.img_data[cursor] = color.color_r;
		env->ptr.img_data[cursor + 1] = color.color_g;
		env->ptr.img_data[cursor + 2] = color.color_b;
	}
}


void	ft_draw_board(t_dam *env)
{
	t_cursor c;

		while (++c.y < LARGEUR)
	{
		c.x = -1;
		while (c.x++ < HAUTEUR)
		{
			if ((c.y / (LARGEUR / 10)) % 2 )// x impair
				(c.x / (LARGEUR / 10)) % 2 ? ft_put_pixel(env, c.x, c.y, hex_to_rgb(LIGHT_BROWN)) : ft_put_pixel(env, c.x, c.y, hex_to_rgb(BROWN));
			else
				(c.x / (LARGEUR/10)) % 2 ? ft_put_pixel(env, c.x, c.y, hex_to_rgb(BROWN)) : ft_put_pixel(env, c.x, c.y, hex_to_rgb(LIGHT_BROWN));
		}
	}
}

/*

void	fill_image(t_dam *env)
{
	t_cursor c;

	c.y = -1;
	while (++c.y < LARGEUR)
	{
		c.x = -1;
		while (++c.x < HAUTEUR)
		{
			if (c.x + 1 < HAUTEUR)
			{
				draw_line(env, env->proj[c.y][c.x], env->proj[c.y][c.x + 1]);
			}
			if (c.y + 1 < LARGEUR)
			{
				draw_line(env, env->proj[c.y][c.x], env->proj[c.y + 1][c.x]);
			}
		}
	}
}
*/
/*
void	ft_print_menu(t_dam *env)
{
	if (!(env->val->inside))
		ft_outside_alert(env);
	if (env->stat_mode == LOCK_S)
		ft_lock_menu(env);
	if (env->val->color_mode == LABY)
		ft_game_menu(env);
	if (env->stat_mode != LOCK_S && env->val->color_mode != LABY)
		ft_regular_menu(env);
	if (env->val->game == WIN && env->stat_mode != LOCK_S)
		ft_putwin(env);
}
*/