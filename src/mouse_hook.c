/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <leon.gudin@ynov.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:13:47 by lgudin            #+#    #+#             */
/*   Updated: 2021/12/11 18:24:03 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dames.h"


t_cursor    get_coord(int x, int y)
{
    t_cursor cursor;

    cursor.x = x / (LARGEUR/10);
    cursor.y = y / (HAUTEUR/10);
    return (cursor);

}


int		mouse_hook(int button, int x, int y,t_dam *env)
{
    //printf("button : %d | x : %d | y : %d\n", button, x, y);

    t_cursor position;

    position = get_coord(x,y);

    if (button > 2) // refuse autre input que clic et clic droit
    {
        ft_putstr("bad input - out of mouse hook\n");
        return (0);
    }  
    //ft_draw_board(env);
    //ft_draw_pawns(env);
    if (env->clic1.x == -1) // si aucun pion selectioné
    {
        if (env->data_board[position.y][position.x] == '0')// && ft_is_your_turn(env, position)) // selection possible sur pion + de la bonne couleur
        {
            ft_putstr("aucun pion sur cette case - out of mouse hook\n");
            return(0);
        }
        /*if (ft_is_your_turn(env, position) != 1)
        {
            ft_putstr("not your turn\n\n");
            return (0);
        }*/
        
        env->clic1 = position;
        env->selected.x = position.x;
        env->selected.y = position.y;
    }
    else
    {
        env->clic2 = get_coord(x,y);
        ft_putstr("clic 2\n"); 
        if (ft_action_pion(env) == 1) // return 0 si mouv illegal
        {
            ft_putstr("moove validé\n");
            env->clic1.x = -1;
            ft_next_turn(env);

            ft_putstr("->> main aux ");
            env->turn == WHITE_TURN ? ft_putstr("Blancs \n") : ft_putstr("noirs \n");
        }
        else
        {
            ft_putstr("illegal moove\n");
            env->clic1.x = -1;
        }
    }
    
    // ? env->clic1 = get_coord(x,y) : env->clic2 = get_coord(x,y);


    ft_draw_board(env);
	ft_draw_pawns(env);
    if (env->clic1.x != -1)
        ft_draw_circle(env, 5, ((x) * LARGEUR / 10 + (LARGEUR / 20)), ((y) * (LARGEUR/10) + (LARGEUR/ 20)), hex_to_rgb(PINK));
	mlx_put_image_to_window(env->ptr.mlx, env->ptr.win, env->ptr.img, 0, 0);
    
	return (0);
}
