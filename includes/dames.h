/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s'actualise_avec_le_premier_save->studiocode.h     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leongu <leongu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:04:19 by leongudin            #+#    #+#             */
/*   Updated: 2021/12/08 13:04:19 by leongudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DAMES_H
# define DAMES_H
# define HAUTEUR 500
# define LARGEUR 500
# define PION_RAY HAUTEUR / 25

# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "../minilibx_macos/mlx.h"
# include "../../libft/libft.h"

# include "struct.h"
# include "definekey.h"
# include "colors.h"
# include "enum.h"

/*
** HOOK
*/

int		key_hook(int keycode, t_dam *env);
int		ft_expose_hook(t_dam *env);
int		mouse_hook(int button, int x, int y,t_dam *env);

/*
** INIT
*/

void	ptr_init(t_ptr *ptr);
void	ft_init(t_dam *env);
void	ft_init_game(t_dam *env);
void    setboard(t_dam *env);

/*
** Main 
*/

int	ft_error(char *s);

/*
** Print
*/

t_rgb	hex_to_rgb(int hex_color);
void	ft_put_pixel(t_dam *env, int x, int y, t_rgb color);
void	fill_image(t_dam *env);
void	ft_draw_board(t_dam *env);
void	ft_draw_circle(t_dam *env, int rayon, int x, int y, t_rgb color);
void	ft_put_cross(t_dam *env, int x, int y, t_rgb color);
void	ft_draw_pawns(t_dam *env);

/*
** Bresenham
*/

int	function(t_dam *env, t_proj point_zero, t_proj point_one);
int	another_function(t_dam *env, t_proj point_zero, t_proj point_one);
int	draw_line(t_dam *env, t_proj point_zero, t_proj point_one);

/*
** Gestion pions
*/

int     ft_action_pion(t_dam *env);

void    ft_put_pion(t_cursor clic, t_dam *env);
void    ft_del_pion(t_cursor clic, t_dam *env);

// verif pions
int     ft_is_your_turn(t_dam *env, t_cursor cursor);
int     ft_is_diagonal(t_dam *env);



// game usage
void    ft_next_turn(t_dam *env);


char    ft_opclr1(char turn);
char    ft_opclr2(char turn);

#endif
