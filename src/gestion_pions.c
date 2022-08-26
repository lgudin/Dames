/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_pions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <leon.gudin@ynov.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:43:20 by lgudin            #+#    #+#             */
/*   Updated: 2022/08/27 01:42:04 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dames.h"

int     ft_is_diagonal(t_dam *env)
{
    if  (env->clic2.x == env->clic1.x + 1 && (env->clic2.y == env->clic1.y - 1))
        return (1);
    else if  (env->clic2.x == env->clic1.x + 1 && (env->clic2.y == env->clic1.y + 1))
        return (1);
    else if ((env->clic2.x) == (env->clic1.x - 1) && (env->clic2.y == env->clic1.y - 1))
        return (1);
    else if ((env->clic2.x) == (env->clic1.x - 1) && (env->clic2.y == env->clic1.y + 1))
        return (1);
    return (0);
}

char    ft_opclr1(char turn) // return opposite pawn color number
{
    if (turn == WHITE_TURN)
        return ('2');
    return ('1');
}

char    ft_opclr2(char turn) // return opposite queen color number / doit etre separé car on test les deux pions potentiels de la couleur opposé
{
    if (turn == WHITE_TURN)
        return ('4');
    return ('3');
}

int     ft_is_diagonal2(t_dam *env)
{
    
    t_cursor todelete;

    if  (env->clic2.x == env->clic1.x + 2 && (env->clic2.y == env->clic1.y - 2)) // diagonal distance 2
    {
        if (env->data_board[env->clic1.y - 1][env->clic1.x + 1] == ft_opclr1(env->turn) || 
            env->data_board[env->clic1.y - 1][env->clic1.x + 1] == ft_opclr2(env->turn)) // pion entre deux de bonne couleure
        {
            ft_putstr("ça mange y- x+\n");
            // on supprime le pion 
            todelete.y = env->clic1.y - 1;
            todelete.x = env->clic1.x + 1;
            ft_del_pion(todelete, env);

            return (1); // exit avec réussite
            
        }
    }
    else if  (env->clic2.x == env->clic1.x + 2 && (env->clic2.y == env->clic1.y + 2))
    {
        if (env->data_board[env->clic1.y + 1][env->clic1.x + 1]== ft_opclr1(env->turn) || 
            env->data_board[env->clic1.y + 1][env->clic1.x + 1] == ft_opclr2(env->turn)) // pion entre deux de bonne couleure
        {
            ft_putstr("ça mange y+ x+\n");
            todelete.y = env->clic1.y + 1;
            todelete.x = env->clic1.x + 1;
            ft_del_pion(todelete, env);
            return (1); // exit avec réussite
        }
    }
    else if ((env->clic2.x) == (env->clic1.x - 2) && (env->clic2.y == env->clic1.y - 2))
    { 
        if (env->data_board[env->clic1.y - 1][env->clic1.x - 1]== ft_opclr1(env->turn) || 
            env->data_board[env->clic1.y - 1][env->clic1.x - 1] == ft_opclr2(env->turn)) // pion entre deux de bonne couleure
        {
            ft_putstr("ça mange y- x-\n");
            todelete.y = env->clic1.y - 1;
            todelete.x = env->clic1.x - 1;
            ft_del_pion(todelete, env);
            return (1); // exit avec réussite
        }
    }
    else if ((env->clic2.x) == (env->clic1.x - 2) && (env->clic2.y == env->clic1.y + 2))
    {
        if (env->data_board[env->clic1.y + 1][env->clic1.x - 1]== ft_opclr1(env->turn) || 
            env->data_board[env->clic1.y + 1][env->clic1.x - 1] == ft_opclr2(env->turn)) // pion entre deux de bonne couleure
        {
            ft_putstr("ça mange y+ x-\n");
            todelete.y = env->clic1.y + 1;
            todelete.x = env->clic1.x - 1;
            ft_del_pion(todelete, env);
            return (1); // exit avec réussite   
        }
    }
    return (0);
}


int     ft_is_diagonal_unlimited(t_dam *env)
{
    int d_x;  // delta x et y 
    int d_y;

    d_x =  env->clic2.x - env->clic1.x;
    d_y =  env->clic2.y - env->clic1.y;

    d_x < 0 ? d_x = -d_x : ft_putstr(""); // on met en valeur absolue
    d_y < 0 ? d_x = -d_x : ft_putstr("");

    if (d_x == d_y) // si les distance x et y sont égales, les deux cliques sont en diagonale
        return (d_x);
    return (0);
}


int     ft_is_your_turn(t_dam *env, t_cursor cursor)
{
    char data;

    data = env->data_board[cursor.y][cursor.x];
    if ((data == '1' || data == '3') && env->turn == WHITE_TURN)
        return (1);
    else if ((data == '2' || data == '4') && env->turn == BLACK_TURN)
        return (1);
    return (0);
}

void    ft_next_turn(t_dam *env)
{
    if (env->turn == WHITE_TURN)
        env->turn = BLACK_TURN;
    else
        env->turn = WHITE_TURN;
}

void    ft_del_pion(t_cursor clic, t_dam *env)
{
    env->data_board[clic.y][clic.x] = '0';
}

void    ft_put_pion(t_cursor clic, t_dam *env)
{
    if (env->turn == WHITE_TURN && clic.y == 0) // si la main est au blanc + last rangée
        env->data_board[clic.y][clic.x] = '3';  // promotion reine blanche
    else if (env->turn == WHITE_TURN)
        env->data_board[clic.y][clic.x] = '1';
    else if (clic.y == 9) // si main au noir + last rangé noire
        env->data_board[clic.y][clic.x] = '4';  // promotion reine noire
    else
        env->data_board[clic.y][clic.x] = '2'; // pion noir
}

int ft_miam(t_dam *env)
{
    
    return (0);
}


int     ft_action_pion(t_dam *env)
{
    if (ft_is_your_turn(env, env->clic1) != 1)
    {
        ft_putstr("not your turn\n\n");
        return (0);
    }
    // Mouvement simple sans prise
    if (((env->data_board[env->clic2.y][env->clic2.x] == '0') && ft_is_diagonal(env)) == 1) // si mouvement simple valide et pas de pion sur la destination
    {
        ft_putstr("moove simple possible\n\n");
        ft_del_pion(env->clic1, env);
        ft_put_pion(env->clic2, env);
    }
    else if ((env->data_board[env->clic2.y][env->clic2.x] == '0') && ft_is_diagonal2(env) == 1)
    {
       // ft_draw_board(env);
        //ft_draw_pawns(env);
        ft_del_pion(env->clic1, env);
        ft_put_pion(env->clic2, env);
    }
    else
        return (0);

    return (1);
}