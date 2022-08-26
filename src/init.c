/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgudin <leon.gudin@ynov.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:01:53 by lgudin            #+#    #+#             */
/*   Updated: 2022/08/27 01:22:33 by lgudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dames.h"

void	ptr_init(t_ptr *ptr)
{
	ptr->endian = 0;
	ptr->bpp = 32;
	ptr->size_line = LARGEUR * 4;
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, LARGEUR, HAUTEUR, "Jeu de Dames");
}

void	ft_init(t_dam *env)
{
    
	ptr_init(&env->ptr); 
	//ft_init_game(env); // Regle le tour pour les blancs 

    env->bck_clr = BLACK; // Regle la couleur de fond
/*
	env->clic1.x = -1;
	env->clic1.y = -1;
	
	env->clic2.x = -1;
	env->clic2.y = -1;
	*/

}

/*
void setboard(t_dam *env)
{
	env->data_board = (char**)ft_memalloc(sizeof(char*) * 11);
	
	env->data_board[0] = ft_strdup("0202020202");
	env->data_board[1] = ft_strdup("2020202020");
	env->data_board[2] = ft_strdup("0000000000");
	env->data_board[3] = ft_strdup("0202001010");
	env->data_board[4] = ft_strdup("0010000200");
	env->data_board[5] = ft_strdup("0202001010");
	env->data_board[6] = ft_strdup("0000000000");
	env->data_board[7] = ft_strdup("1010101010");
	env->data_board[8] = ft_strdup("0101010101");
	env->data_board[9] = ft_strdup("1010101010");
	env->data_board[10] = ft_strdup("\0");
}
*/

void	ft_init_game(t_dam *env)
{
	env->turn = WHITE_TURN; // choisir qui commence WHITE_TURN ou BLACK_TURN
}


void setboard(t_dam *env) // Choisir la composition du plateau de jeu : 0 case vide, 1 pion blanc / 2 Pion noir / 3 et 4 sont les dames je crois 
{
	env->data_board = (char**)ft_memalloc(sizeof(char*) * 11);
	
	env->data_board[0] = ft_strdup("0202020202");
	env->data_board[1] = ft_strdup("2020202020");
	env->data_board[2] = ft_strdup("0202020202");
	env->data_board[3] = ft_strdup("2020202020");
	env->data_board[4] = ft_strdup("0000000000");
	env->data_board[5] = ft_strdup("0000000000");
	env->data_board[6] = ft_strdup("0101010101");
	env->data_board[7] = ft_strdup("1010101010");
	env->data_board[8] = ft_strdup("0101010101");
	env->data_board[9] = ft_strdup("1010101010");
	env->data_board[10] = ft_strdup("\0");
}
