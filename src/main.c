/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <leon.gudin@ynov.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:07:21 by lgudin            #+#    #+#             */
/*   Updated: 2022/08/27 01:38:43 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dames.h"
#include <stdio.h>

int	ft_error(char *s)
{
	ft_putstr("Error: ");
	ft_putstrln(s);
	return (-1);
}

int main(int ac, char **av)
{
	(void)ac;
	t_dam	*env;

	env = (t_dam*)ft_memalloc(sizeof(t_dam));
	ft_init(env); 
	setboard(env); // ça aussi je crois 
	
	//ft_init_game(env); probablement inutile

	if (!(env->ptr.img = mlx_new_image(env->ptr.mlx, LARGEUR, HAUTEUR)))
		return ((int)ft_error("mlx_new_image passe pas"));
	env->ptr.img_data = mlx_get_data_addr(env->ptr.img,
			&env->ptr.bpp, &env->ptr.size_line, &env->ptr.endian);


	ft_draw_board(env);
	ft_draw_pawns(env);
	mlx_put_image_to_window(env->ptr.mlx, env->ptr.win, env->ptr.img, 0, 0);


	mlx_mouse_hook(env->ptr.win, mouse_hook, env);
	mlx_hook(env->ptr.win, 2, 3, key_hook, env);
	mlx_expose_hook(env->ptr.win, ft_expose_hook, env);
	
	mlx_loop(env->ptr.mlx);

	mlx_destroy_image(env->ptr.mlx, env->ptr.img);
	return (0);
}