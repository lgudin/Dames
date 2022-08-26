/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <leon.gudin@ynov.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:23:31 by lgudin            #+#    #+#             */
/*   Updated: 2021/12/11 14:03:53 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dames.h"

int		key_hook(int keycode, t_dam *env)
{
	if (keycode == ESC)
		exit(0);
	/*
	else if (keycode == U)
	*/

	//ft_expose_hook(env);
	return (0);
}

int		ft_expose_hook(t_dam *env)
{
	ft_draw_board(env);
	ft_draw_pawns(env);

	//mlx_put_image_to_window(env->ptr.mlx, env->ptr.win, env->ptr.img, 0, 0);
	//ft_print_menu(env);
	return (0);
}
